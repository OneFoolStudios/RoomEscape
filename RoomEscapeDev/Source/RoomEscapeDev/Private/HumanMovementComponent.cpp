// OneFoolStudios

#include "RoomEscapeDev.h"
#include "HumanFoot.h"
#include "HumanMovementComponent.h"

void UHumanMovementComponent::SetFootReference(UHumanFoot* HumanFootToSet)
{
	if (!HumanFootToSet) 
	{
		UE_LOG(LogTemp, Warning, TEXT("No Body2 Found"));
		return; 
	}
	UE_LOG(LogTemp, Warning, TEXT("Body found at: %s"), *HumanFootToSet->GetOwner()->GetActorLocation().ToString());
	//Foot = HumanFootToSet;
	
}




void UHumanMovementComponent::IntendMoveForward(float Acc) 
{
	//if (!Foot) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("moving"));
	//Foot->SetAcceleration(Acc);

}


