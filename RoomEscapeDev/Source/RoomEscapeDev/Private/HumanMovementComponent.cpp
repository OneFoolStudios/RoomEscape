// OneFoolStudios

#include "RoomEscapeDev.h"
#include "HumanBody.h"
#include "HumanMovementComponent.h"

void UHumanMovementComponent::SetBodyReference(UHumanBody* HumanBodyToSet) 
{
	if (!HumanBodyToSet) { return; }
	HumanBody = HumanBodyToSet;
}




void UHumanMovementComponent::IntendMoveForward(float Acc) 
{
	if (!HumanBody) { return; }
	HumanBody->SetAcceleration(Acc);

}


