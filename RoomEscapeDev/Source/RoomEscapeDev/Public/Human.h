// OneFoolStudios

#pragma once

#include "GameFramework/Pawn.h"
#include "Human.generated.h"


// Foward declarations
class UHumanMovementComponent;
class UHumanBody;


UCLASS()
class ROOMESCAPEDEV_API AHuman : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHuman();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly) UHumanMovementComponent* HumanMovementComponent = nullptr;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//fucntions
	UFUNCTION(BlueprintCallable, Category = Setup) void SetHumanBodyReference(UHumanBody* HumanBodyToSet);


	
	
};
