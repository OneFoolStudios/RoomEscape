// OneFoolStudios

#include "RoomEscapeDev.h"
#include "HumanCharacter.h"


// Sets default values
AHumanCharacter::AHumanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHumanCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHumanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHumanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


///MOVEMENT FUNCTIONS
//Move Forward and backward
void AHumanCharacter::MoveForward(float ThumbStick) {
	AddMovementInput(GetActorForwardVector(), ThumbStick);
}

//Move Right and Left
void AHumanCharacter::MoveLeft(float ThumbStick) {
	AddMovementInput(GetActorRightVector(), ThumbStick);
}



///LOOKING FUNCTIONS
//Look Up and Down
void AHumanCharacter::LookUp(float ThumbStick) {
	AddControllerPitchInput(ThumbStick);
}

//Look Right and Left
void AHumanCharacter::LookLeft(float ThumbStick) {
	AddControllerYawInput(ThumbStick);
}