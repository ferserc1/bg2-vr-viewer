// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bg2SceneLoader.h"
#include "TeleportAreaComponent.h"
#include "Bg2VrSceneLoader.generated.h"

/**
 * 
 */
UCLASS()
class BG2VRVIEWER_API ABg2VrSceneLoader : public ABg2SceneLoader
{
	GENERATED_BODY()
	
public:
	ABg2VrSceneLoader();

	UFUNCTION(BlueprintCallable)
	void LoadSceneAndAddFloor();

	UPROPERTY()
	UTeleportAreaComponent * TeleportArea;
};
