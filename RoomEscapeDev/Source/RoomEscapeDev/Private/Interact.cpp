// OneFoolStudios

#include "RoomEscapeDev.h"
#include "Interact.h"


#define OUT

// Sets default values for this component's properties
UInteract::UInteract()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteract::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteract::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UPrimitiveComponent* UInteract::GetHitObject(FString& RootName) {
	/// setup query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	/// Ray-cast out to reach distance
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		GetReachLineStart(),
		GetReachLineEnd(),
		FCollisionObjectQueryParams(),
		TraceParameters
	);
	if (!HitResult.GetComponent() || !HitResult.GetActor()) { return nullptr; }
	UE_LOG(LogTemp, Warning, TEXT("%s"), *HitResult.GetComponent()->GetName());
	RootName = HitResult.GetActor()->GetRootComponent()->GetName();
	//ActorHit = HitResult.GetActor();
	return HitResult.GetComponent();
}


///Get the location where the player can grab
FVector UInteract::GetReachLineStart() {
	///Get player veiw point
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	return PlayerViewPointLocation;
}

FVector UInteract::GetReachLineEnd() {
	///Get player veiw point
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}