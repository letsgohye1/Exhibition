// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorWheelWidget.h"

#include "Components/Button.h"
//#include "Synth2DSlider.h"
#include "Kismet/KismetMathLibrary.h"


void UColorWheelWidget::NativeConstruct()
{
   /* Super::NativeConstruct();

    if (ColorWheelSlider)
    {
        ColorWheelSlider->OnValueChanged.AddDynamic(
            this,
            &UColorWheelWidget::OnColorWheelChanged
        );
    }*/
}

void UColorWheelWidget::OnColorWheelChanged(FVector2D Value)
{/*
    if (!ColorButton)
        return;

    FLinearColor Color = GetColorFromColorWheel(Value);
    ColorButton->SetColorAndOpacity(Color);*/
}

FLinearColor UColorWheelWidget::GetColorFromColorWheel(const FVector2D& SliderValue) const
{
    return FLinearColor();
}

