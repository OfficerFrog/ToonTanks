// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	ATank();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void HandleDestruction();

	bool bAlive = true;

	APlayerController* GetTankPlayerController() const {return TankPlayerController;}

private:
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* CameraArm;
	
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 200.f;
	UPROPERTY(EditAnywhere)
	float TurnSpeed = 200.f;

	void Move(float Value);
	void Turn(float Value);	

	APlayerController* TankPlayerController;
};
