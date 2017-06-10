// OneFoolStudios

#pragma once

#include "Components/ActorComponent.h"
#include "HumanBody.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPEDEV_API UHumanBody : public UStaticMeshComponent
{
	GENERATED_BODY()

public:	
	//functions
	UFUNCTION(BlueprintCallable, Category = "Input") void SetAcceleration(float Acc);

	//Vars
	UPROPERTY(EditDefaultsOnly) float MaxAcc = 100; // 100kg at 10m/s²

private:



		
	
};
