#include <iostream>
#include <string>
#include <locale>
#include <cassert>

using namespace std;

const bool UNIT_TESTING = true;
const bool SYSTEM_TESTING = false;

// Function Prototypes
string getFirstWord(string text);
string getLastWord(string text);
string extractWord(string& text);
bool isUppercase(string text);
string makeUppercase(string text);
bool hasMultipleExclamations(string text);
bool isGibberishWord(string text);
bool isVowel(char character);
void doUnitTesting();
void doSystemTesting();


int main() {
	// TESTING
	if (UNIT_TESTING) doUnitTesting();
	if (SYSTEM_TESTING) doSystemTesting();


	string subjectLine;

	// cout << "Enter the subject line of the email: ";
	// cin >> subjectLine;
	// cout << "Enter the body of the email.  Press Enter on an empty line to finish." << endl;


	
}


// Goes through "text", and returns the first word it finds.
// A word is a contiguous sequence of letters delimited by a non-letter or end of string.
// If text has no words, returns an empty string.
string getFirstWord(string text) {
	if (text.size() == 0) // Empty string passed in
		return "";

	string firstWord = "";


	for (size_t i = 0; i != text.size(); i++) {
		if (isalpha(text[i])) {
			while (isalpha(text[i])) { // Found start of word
				firstWord += text[i];
				i++;
			}

			return firstWord; // Finished reading word
		}

	}

	if (firstWord.size() == 0) // No words found
		return "";
}

// Goes through "text", and returns the last word it finds.
// If text has no words, returns an empty string.
string getLastWord(string text) {
	if (text.size() == 0) // Empty string passed in
		return "";

	string currentWord = "";

	for (size_t i = 0; i != text.size(); i++) {
		if (isalpha(text[i])) {
			currentWord = ""; // Resets current word incase a word was previously found

			while (isalpha(text[i])) { // Found the start of a word
				currentWord += text[i];
				i++;
			}

			i--; // Because of the while loop, i is +1 higher than it should be
			// Finished reading word
		}
	}

	if (currentWord.size() == 0)
		return "";

	return currentWord;
}

// Returns the first word found in "text", and removes that word and all characters
// before it in the string. If no words are found, change "text" to an empty string and return an empty string
string extractWord(string& text) {
	if (text.size() == 0) // Empty string passed in
		return "";

	string firstWord = "";

	for (size_t i = 0; i != text.size(); i++) {
		if (isalpha(text[i])) {
			int firstWordStartIndex = i; // Found start of word

			while (isalpha(text[i])) {
				firstWord += text[i];
				i++;
			}

			// Finished reading word
			int modifiedTextStartIndex = i;
			text = text.substr(modifiedTextStartIndex); // Remove all text before and including "firstWord" from "text"
			return firstWord;
		}

	}
	
	if (firstWord == "") { // No words found
		text = "";
		return "";
	}
}

// Returns true if all characters in "text" are uppercase
// Non-letter characters have no impact
// An empty "text" returns true
bool isUppercase(string text) {
	if (text.size() == 0) return true; // Empty String

	bool result = true;

	for (size_t i = 0; i < text.size(); i++) {
		if (isalpha(text[i]) && !isupper(text[i])) // Found lowercase letter
			result = false;
	}

	return result;
}

// Returns a string identical to "text" but with all letters capitalized
string makeUppercase(string text) {
	string resultString = "";

	for (size_t i = 0; i < text.size(); i++) {
		if (isalpha(text[i]) && islower(text[i])) // Found lowercase letter
			resultString += toupper(text[i]);
		else
			resultString += text[i];
	}

	return resultString;
}

// Returns true if "text" has 3 or more consecutive '!' characters
bool hasMultipleExclamations(string text) {
	if (text.size() == 0) return false; // Empty string passed in

	for (size_t i = 0; i < text.size() - 2; i++) { 
		if ( text[i]     == '!' &&
			 text[i + 1] == '!' &&
			 text[i + 2] == '!'
		) return true;	
	}

	return false;
}

// Returns true if "text" has at least 4 consecutive consonants
bool isGibberishWord(string text) {
	if (text.size() == 0) return false; // Empty string passed in
	
	for (size_t i = 0; i < text.size() - 3; i++) { 
		
		if (isalpha(text[i])     && !isVowel(text[i])     &&
			isalpha(text[i + 1]) && !isVowel(text[i + 1]) &&
			isalpha(text[i + 2]) && !isVowel(text[i + 2]) &&
			isalpha(text[i + 3]) && !isVowel(text[i + 3])
		) return true;
	}

	return false;
}

bool isVowel(char character) {
	switch (character) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return true;

		default:
			return false;
	}
}

void doUnitTesting() {
	// getFirstWord() Test
	assert(getFirstWord("   Hello HHell") == "Hello");
	assert(getFirstWord("") == "");
	assert(getFirstWord("*&#8347320") == "");
	assert(getFirstWord("   ") == "");
	assert(getFirstWord("hi4 hi ") == "hi");
	assert(getFirstWord("hi") == "hi");
	
	// getLastWord() Test
	assert(getLastWord("   Hello HHell") == "HHell");
	assert(getLastWord("") == "");
	assert(getLastWord("*&#8347320") == "");
	assert(getLastWord("   ") == "");
	assert(getLastWord("hi4 hi h 3") == "h");

	// extractWord() Test
	string extractWordString1 = "  231cat cat";
	assert(extractWord(extractWordString1) == "cat");
	assert(extractWordString1 == " cat");
	string extractWordString2 = "8347320 ";
	assert(extractWord(extractWordString2) == "");
	assert(extractWordString2 == "");
	string extractWordString3 = "h 809 h";
	assert(extractWord(extractWordString3) == "h");
	assert(extractWordString3 == " 809 h");
	
	// isUppercase() Test
	assert(isUppercase("  3KK 3KK") == true);
	assert(isUppercase("  3KK 333dK") == false);
	assert(isUppercase("") == true);
	assert(isUppercase("2") == true);
	assert(isUppercase("i") == false);
	assert(isUppercase("HJHDJd") == false);

	// makeUppercase() Test
	assert(makeUppercase("  3KKK KKK") == "  3KKK KKK");
	assert(makeUppercase("  3KK 333dK") == "  3KK 333DK");
	assert(makeUppercase("") == "");
	assert(makeUppercase("HJHDJd") == "HJHDJD");
	
	// hasMultipleExclamations() Test
	assert(hasMultipleExclamations("") == false);
	assert(hasMultipleExclamations("! ! !") == false);
	assert(hasMultipleExclamations("!! !!3!!!") == true);
	assert(hasMultipleExclamations("!! !!!3!") == true);

	// isGibberishWord() Test
	assert(isGibberishWord("AGPQrxab") == true);
	assert(isGibberishWord("xxxxozzzz") == true);
	assert(isGibberishWord("mortgage") == false);
	assert(isGibberishWord("discount prescriptions") == false);


	cout << "All unit tests passed" << endl;
	return;
}

void doSystemTesting() {

	exit(0);
}