// OneFoolStudios

#include "RoomEscapeDev.h"
#include "HumanBody.h"
#include "HumanMovementComponent.h"

void UHumanMovementComponent::SetBodyReference(UHumanBody* HumanBodyToSet) 
{
	if (!HumanBodyToSet) 
	{
		UE_LOG(LogTemp, Warning, TEXT("No Body2 Found"));
		return; 
	}
	UE_LOG(LogTemp, Warning, TEXT("Body found at: %s"), *HumanBodyToSet->GetOwner()->GetActorLocation().ToString());
	//Body = HumanBodyToSet;
	
}




void UHumanMovementComponent::IntendMoveForward(float Acc) 
{
	if (!Body) { return; }
	//Body->SetAcceleration(Acc);

}


