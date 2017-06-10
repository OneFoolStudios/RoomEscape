// OneFoolStudios

#include "RoomEscapeDev.h"
#include "HumanMovementComponent.h"
#include "Human.h"



// Sets default values
AHuman::AHuman()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHuman::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHuman::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHuman::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



void AHuman::SetHumanBodyReference(UHumanBody* HumanBodyToSet) 
{
	if (!HumanBodyToSet) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("No Body Found"));
		return;
	}
	HumanMovementComponent->SetBodyReference(HumanBodyToSet);
}
