// OneFoolStudios

#pragma once

#include "GameFramework/Character.h"
#include "HumanCharacter.generated.h"

UCLASS()
class ROOMESCAPEDEV_API AHumanCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHumanCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Functions

	///MOVING FUNCTIONS
	UFUNCTION(BlueprintCallable, Category = Input) void MoveForward(float ThumbStick);
	UFUNCTION(BlueprintCallable, Category = Input) void MoveLeft(float ThumbStick);
	// Jumping: is just a blueprint called jump, no use to make one here
	//Crouch

	///LOOKING FUNCTIONS
	UFUNCTION(BlueprintCallable, Category = Input) void LookUp(float ThumbStick);
	UFUNCTION(BlueprintCallable, Category = Input) void LookLeft(float ThumbStick);

};
