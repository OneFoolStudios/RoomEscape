// OneFoolStudios

#pragma once

#include "Blueprint/UserWidget.h"
#include "BullsAndCowsMiniGame.generated.h"

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};


/**
 * 
 */
UCLASS()
class ROOMESCAPEDEV_API UBullsAndCowsMiniGame : public UUserWidget
{
	GENERATED_BODY()

public:	
	//UBullsAndCowsMiniGame();
	UFUNCTION(BlueprintCallable, Category = "MyUUserWidgetClass") void WordGame(FString Guess, FString& Result, bool& EndGame);

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	void Reset();
	EWordStatus CheckGuessValidity(FString) const;

	FBullCowCount SubmitValidGuess(FString);

private:


	//Vars
	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 3;
	FString MyHiddenWord = "ant";
	bool bWonGame;

	bool IsIsogram(FString) const;
	
};
