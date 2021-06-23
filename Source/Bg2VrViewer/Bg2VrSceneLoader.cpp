// Fill out your copyright notice in the Description page of Project Settings.


#include "Bg2VrSceneLoader.h"
#include "Misc/CommandLine.h"
#include "EngineUtils.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "ProceduralMeshComponent.h"
#include "Bg2ModelComponent.h"

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
	//for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr) {
	//	{
	//		TArray<UProceduralMeshComponent*> Meshes;


	//		AActor* Mesh = *ActorItr;
	//		Mesh->GetComponents(Meshes);
			
	//		for (int i = 0; i < Meshes.Num(); ++i) {
			
				//Mesh->SetActorEnableCollision(false);
				/*FString str1 = ActorItr->GetName();
				auto ObjTeleportArea = NewObject<UTeleportAreaComponent>(Mesh);
				ObjTeleportArea->RegisterComponent();
				FVector extent;
				FVector origin;
				ActorItr->GetActorBounds(true, origin, extent);
				ObjTeleportArea->SetBoxExtent(extent);*/

				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *str1));
				//FString str2 = ActorItr->GetActorLocation().ToString();
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *str2));
	//		}
	//	}
	//}

	if (addFloorNavigation)
	{
		UE_LOG(LogTemp, Warning, TEXT("No collider found in scene. Using default navigation"));
		
	}
	else
	{
		// Disable floor navigation
	}
}
