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
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr) {
		{
			TArray<UProceduralMeshComponent*> Meshes;


			AActor* Mesh = *ActorItr;
			Mesh->GetComponents(Meshes);
			TArray<UBoxComponent*> Boxes;
			Mesh->GetComponents(Boxes);
			
			for (int i = 0; i < Meshes.Num(); ++i) {

				auto mesh = Meshes[i];
				FString str1 = mesh->GetName();
				if (str1 == TEXT("bg2 engine mesh")) {
					
					if (Boxes.Num() > 0)
					{
						UBoxComponent* box = Boxes[0];
						FVector extent = box->GetScaledBoxExtent();
						FVector origin = box->GetComponentLocation();
						//auto ObjTeleportArea = NewObject<UTeleportAreaComponent>(Mesh);
						//ObjTeleportArea->RegisterComponent();
						DrawDebugBox(GetWorld(), origin, extent, FColor::Red, true);
						//ObjTeleportArea->SetBoxExtent(extent);
						// TODO: add a teleport area based on the mesh geometry. I don't know how to do it,
						// it seems to be something absurdly complicated
					}
				}
				

				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *str1));
				//FString str2 = ActorItr->GetActorLocation().ToString();
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s"), *str2));
			}
		}
	}

	if (addFloorNavigation)
	{
		UE_LOG(LogTemp, Warning, TEXT("No collider found in scene. Using default navigation"));
		
	}
	else
	{
		// Disable floor navigation
	}
}
