// Fill out your copyright notice in the Description page of Project Settings.


#include "STaskViewer.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

TSharedRef<IDetailCustomization> STaskViewer::MakeInstance()
{
	return MakeShareable(new STaskViewer);
}

void STaskViewer::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	IDetailCategoryBuilder& PlannerCat = DetailLayout.EditCategory(TEXT("Planner"));
	TSharedPtr<IPropertyHandle> OverrideLightmapRes = DetailLayout.GetProperty("Donut Shop");
	FDetailWidgetRow& WarningRow = PlannerCat.AddCustomRow(FText::FromString("TEST"))
		.WholeRowContent()
		[
			SNew(SBox)
			.Padding(FMargin(0.f, 4.f))
		[
			SNew(STextBlock)
			.Text(FText::FromString("TESTESTSETET Button"))
		]
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
