// Copyright Epic Games, Inc. All Rights Reserved.

#include "Test.h"
#include "TestStyle.h"
#include "TestCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "STaskViewer.h"
#include "STestWidget.h"
#include "ToolMenus.h"

static const FName TestTabName("Test");

#define LOCTEXT_NAMESPACE "FTestModule"

void FTestModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FTestStyle::Initialize();
	FTestStyle::ReloadTextures();

	FTestCommands::Register();
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

	PropertyModule.RegisterCustomClassLayout("Planner", FOnGetDetailCustomizationInstance::CreateStatic(&STaskViewer::MakeInstance));
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FTestCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FTestModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FTestModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TestTabName, FOnSpawnTab::CreateRaw(this, &FTestModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FTestTabTitle", "Test"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	PropertyModule.NotifyCustomizationModuleChanged();
}

void FTestModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FTestStyle::Shutdown();

	FTestCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TestTabName);
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.UnregisterCustomPropertyTypeLayout("Planner");
	PropertyModule.NotifyCustomizationModuleChanged();
}

TSharedRef<SDockTab> FTestModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{


	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "AddADDADDADD code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FTestModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("Test.cpp"))
		);
	FDetailsViewArgs DetailsViewArgs;
	TSharedRef<IDetailsView> DetailsView = PropertyModule.CreateDetailView(DetailsViewArgs);
	TArray< TWeakObjectPtr< UObject > > Objects;
	DetailsView->GetSelectedObjects();
	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[

			//SNew(STestWidget)
			DetailsView


		];
}

void FTestModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(TestTabName);
}

void FTestModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FTestCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FTestCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestModule, Test)