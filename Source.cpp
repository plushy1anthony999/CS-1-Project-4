#include <iostream>
#include <string>
#include <cassert>

using namespace std;

const bool UNIT_TESTING = true;
const bool SYSTEM_TESTING = false;

// Function Prototypes
string getFirstWord(string text);
void doUnitTesting();
void doSystemTesting();


int main() {
	// TESTING
	if (UNIT_TESTING) doUnitTesting();
	if (SYSTEM_TESTING) doSystemTesting();


	string subjectLine;

	cout << "Enter the subject line of the email: ";
	cin >> subjectLine;
	cout << "Enter the body of the email.  Press Enter on an empty line to finish." << endl;


	
}


// Goes through "text", and returns the first word it finds.
// A word is a contiguous sequence of letters delimited by a non-letter or end of string.
// If text has no words, returns an empty string.
string getFirstWord(string text) {
	string firstWord = "";

	for (size_t i = 0; i != text.size(); i++) {
		while (isalpha(text[i])) // Found the start of a word
			firstWord += text[i]; // Construct word to return	
		
		return firstWord;
	}
}


void doUnitTesting() {
	// getFirstWord() Test
	cout << getFirstWord("   Hello HHell");
	//assert(getFirstWord("   Hello HHell") == "Hello");
	
	return;	
}

void doSystemTesting() {

}