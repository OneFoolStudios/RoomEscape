// OneFoolStudios

#include "RoomEscapeDev.h"
#include "HumanBody.h"


void UHumanBody::SetAcceleration(float Acc) 
{
	auto ForceApplied = GetForwardVector() * Acc * MaxAcc;
	auto ForceLocation = GetComponentLocation();
	auto HumanRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	HumanRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	
}