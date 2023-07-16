// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "DetailCustomizations.h"
#include "IDetailCustomization.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
/**
 * 
 */
class TEST_API STaskViewer : public IDetailCustomization
{
public:
	SLATE_BEGIN_ARGS(STaskViewer)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
		static TSharedRef<IDetailCustomization> MakeInstance();

	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;
};
