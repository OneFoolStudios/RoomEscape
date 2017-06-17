// OneFoolStudios

#include "RoomEscapeDev.h"
#include "BullsAndCowsMiniGame.h"


//UBullsAndCowsMiniGame::UBullsAndCowsMiniGame() { Reset(); }

int32 UBullsAndCowsMiniGame::GetCurrentTry() const { return MyCurrentTry; }
int32 UBullsAndCowsMiniGame::GetHiddenWordLength() const { return MyHiddenWord.Len(); }
bool UBullsAndCowsMiniGame::IsGameWon() const { return bWonGame; }

int32 UBullsAndCowsMiniGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries;
	WordLengthToMaxTries.Add(3, 3);
	WordLengthToMaxTries.Add(4, 6);
	WordLengthToMaxTries.Add(5, 9);
	WordLengthToMaxTries.Add(6, 15);
	return WordLengthToMaxTries[GetHiddenWordLength()];
}

void UBullsAndCowsMiniGame::WordGame(FString Guess, FString& Result, bool& EndGame) {
	EndGame = false;
	Result = "";
	Guess = Guess.ToLower();
	EWordStatus Status = CheckGuessValidity(Guess);
	if (Status == EWordStatus::Wrong_Length) Result = "Your guess has the wrong amout of characters, please try again";
	else if (Status == EWordStatus::Not_Isogram) Result = "Your Guess has 2 times or more the same characters in it, please try again";
	else if (Status == EWordStatus::OK) {
		FBullCowCount GuessResult = SubmitValidGuess(Guess);
		if (Guess.Len() == GuessResult.Bulls) {
			Result = "Correct you have found A code to unlock one of the locks";
			EndGame = true;
		}
		else if (GuessResult.Bulls == 0 && GuessResult.Cows == 0) Result = "At this rate you should restart the game";
		else Result = FString::Printf(TEXT("Bulls: %d & Cows%d"), GuessResult.Bulls, GuessResult.Cows);
	}
	else Result = "ERROR 404 Restart the game please.";

}

EWordStatus UBullsAndCowsMiniGame::CheckGuessValidity(FString Guess) const {
	if (Guess.Len() != GetHiddenWordLength()) return EWordStatus::Wrong_Length;
	else if (!IsIsogram(Guess)) return EWordStatus::Not_Isogram;
	else return EWordStatus::OK;
}

FBullCowCount UBullsAndCowsMiniGame::SubmitValidGuess(FString Guess) {
	int32 WordLength = GetHiddenWordLength();
	//inc try
	MyCurrentTry++;

	//setup a return
	FBullCowCount BullCowCount;

	// loop through all letters and comp with the correct word
	for (int32 i = 0; i < WordLength; i++) {
		if (MyHiddenWord[i] == Guess[i]) BullCowCount.Bulls++;
		for (int32 j = 0; j < WordLength; j++) {
			if (MyHiddenWord[i] == Guess[j] && i != j) BullCowCount.Cows++;
		}
	}
	if (BullCowCount.Bulls == WordLength) bWonGame = true;
	return BullCowCount;
}



bool UBullsAndCowsMiniGame::IsIsogram(FString Word) const {
	auto CharArray = Word.GetCharArray();
	for (int32 i = 0; i < Word.Len(); i++) { //for all letters of the word
		for(int32 j = 0; j < Word.Len(); j++) {
			if (i == j);
			else if (CharArray[j] == CharArray[i]) return false;
		}
		return true;
	}

	return true;
}

void UBullsAndCowsMiniGame::Reset() {
	const FString HIDDEN_WORD = "ant";

	bWonGame = false;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	return;
}