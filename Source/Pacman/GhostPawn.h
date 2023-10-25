// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GhostPawn.generated.h"

UENUM(BlueprintType)

enum class EGhostState : uint8 {
	Default,
	Idle
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGhostStateChangedEvent, EGhostState, NewState);

UCLASS()
class PACMAN_API AGhostPawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGhostState State = EGhostState::Default;

	UFUNCTION(BlueprintCallable)
	void Hunt();

	UFUNCTION(BlueprintCallable)
	void Idle();

	FGhostStateChangedEvent& OnStateChanged() { return ghostStateChangedState; }

private:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FGhostStateChangedEvent ghostStateChangedState;


};
