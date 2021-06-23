// Fill out your copyright notice in the Description page of Project Settings.


#include "Bg2VRGameMode.h"
#include "VRPawn.h"

ABg2VRGameMode::ABg2VRGameMode()
	: Super()
{
	DefaultPawnClass = AVRPawn::StaticClass();

}