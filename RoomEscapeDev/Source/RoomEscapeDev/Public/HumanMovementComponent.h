// OneFoolStudios

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "HumanMovementComponent.generated.h"

class UHumanBody;
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ROOMESCAPEDEV_API UHumanMovementComponent : public UMovementComponent
{
	GENERATED_BODY()
	
public:
	//Functions
	UFUNCTION(BlueprintCallable, Category = "Input") void IntendMoveForward(float Acc);
	
	void SetBodyReference(UHumanBody* HumanBodyToSet);




	//Vars
	UPROPERTY(EditDefaultsOnly) float MaxAcc = 100; // 100kg at 10m/s²
	UHumanBody* Body = nullptr;


private:


	
};
