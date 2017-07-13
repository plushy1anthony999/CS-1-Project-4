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
	int lengthOfFirstWord = 0;
	int startIndexofFirstWord = 0;

	for (size_t i = 0; i != text.size(); i++) {
		if(isalpha(text[i])) {
			startIndexofFirstWord = i;
			while (isalpha(text[i])) { // Found the start of a word
				lengthOfFirstWord++; // 
				i++;
	
				if(!isalpha(text[i]))  // Finished reading word
					return firstWord;
			}
		}
	}
}

// Goes through "text", and returns the last word it finds.
// If text has no words, returns an empty string.
string getLastWord(string text) {
	
}




void doUnitTesting() {
	// getFirstWord() Test
	assert(getFirstWord("   Hello HHell") == "Hello");
	assert(getFirstWord("") == "");
	assert(getFirstWord("*&#8347320") == "");
	assert(getFirstWord("   ") == "");
	assert(getFirstWord("hi4 hi ") == "hi");
	
	
}

void doSystemTesting() {

}