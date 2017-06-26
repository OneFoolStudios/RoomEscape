// OneFoolStudios

#pragma once

#include "Components/ActorComponent.h"
#include "Interact.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPEDEV_API UInteract : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteract();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//Reach of the player
	float Reach = 150.0f;

	UFUNCTION(BlueprintCallable, Category = "Input") UPrimitiveComponent* GetHitObject(FString& RootName);

	//Gets the location where the player can reach to grab something
	FVector GetReachLineStart();
	FVector GetReachLineEnd();
		
	
};
