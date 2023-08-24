#include <iostream>
#include <string>
#include <vector>


using namespace std;

const vector<string> words = {
    "programming",
    "hangman",
    "computer",
    "science",
    "algorithm",
    "cplusplus",
    "java",
    "python",
    "javascript",
    "html",
    "css"
};

// Function to choose a random word from the 'words' vector
string chooseRandomWord() {
    int index = rand() % words.size();
    return words[index];
}

// Function to check if the guessed letter is in the word
bool isLetterInWord(char letter, const string& word) {
    for (char c : word) {
        if (c == letter) {
            return true;
        }
    }
    return false;
}

// Function to update the guessed word with correct guesses
string updateGuessedWord(const string& word, const string& guessedWord, char letter) {
    string updatedWord = guessedWord;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            updatedWord[i] = letter;
        }
    }
    return updatedWord;
}

int main() {
	

    cout << "Welcome to Hangman!" << endl;

    string word = chooseRandomWord();
    string guessedWord(word.length(), '_');
    int attempts = 6;
    char letter;

    while (attempts > 0) {
        cout << "Word: " << guessedWord << endl;
        cout << "Attempts left: " << attempts << endl;
        cout << "Enter a letter: ";
        cin >> letter;

        if (isLetterInWord(letter, word)) {
            guessedWord = updateGuessedWord(word, guessedWord, letter);
            if (guessedWord == word) {
                cout << "Congratulations! You guessed the word: " << word << endl;
                break;
            }
        } else {
            cout << "Incorrect guess!" << endl;
            attempts--;
        }
    }

    if (attempts == 0) {
        cout << "Oops! You ran out of attempts. The word was: " << word << endl;
    }

    return 0;
}