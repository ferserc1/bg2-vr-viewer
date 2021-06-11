// Fill out your copyright notice in the Description page of Project Settings.


#include "Bg2VrSceneLoader.h"
#include "Misc/CommandLine.h"

ABg2VrSceneLoader::ABg2VrSceneLoader()
	:Super()
{
	TeleportArea = CreateDefaultSubobject<UTeleportAreaComponent>(TEXT("DefaultTeleportArea"));
	TeleportArea->SetBoxExtent(FVector(1000000, 1000000, 5));
	RootComponent = TeleportArea;
}

void ABg2VrSceneLoader::LoadSceneAndAddFloor()
{
	LoadSceneFromFilesystem();
	bool addFloorNavigation = false;

	// TODO: Search collider components
	// collider present: add floor navigation at the collider position
	// collider not present: add floor navigation
	addFloorNavigation = true;

	if (addFloorNavigation)
	{
		UE_LOG(LogTemp, Warning, TEXT("No collider found in scene. Using default navigation"));
		
	}
	else
	{
		// Disable floor navigation
	}
}
