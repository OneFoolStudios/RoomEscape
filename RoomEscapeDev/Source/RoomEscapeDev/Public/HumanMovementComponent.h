// OneFoolStudios

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "HumanMovementComponent.generated.h"

class UHumanBody;
class UHumanFoot;
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
	
	void SetFootReference(UHumanFoot* HumanFootToSet);




	//Vars
	UHumanFoot* Foot = nullptr;


private:


	
};
