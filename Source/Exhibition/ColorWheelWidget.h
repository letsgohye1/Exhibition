// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ColorWheelWidget.generated.h"

class UButton;
class USynth2DSlider;

UCLASS()
class EXHIBITION_API UColorWheelWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

    virtual void NativeConstruct() override;

    /** 2D 컬러휠 슬라이더 */
    UPROPERTY(meta = (BindWidget))
    USynth2DSlider* ColorWheelSlider;

    /** 색상 적용 버튼 */
    UPROPERTY(meta = (BindWidget))
    UButton* ColorButton;

    /** 2D 슬라이더 값 변경 시 호출 */
    UFUNCTION()
    void OnColorWheelChanged(FVector2D Value);

    /** SliderValue → Color */
    FLinearColor GetColorFromColorWheel(const FVector2D& SliderValue) const;
};
