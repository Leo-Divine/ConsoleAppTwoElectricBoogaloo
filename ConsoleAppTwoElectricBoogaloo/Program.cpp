#include <iostream>;
#include <cstring>;
#include <vector>;
#include <fstream>;
#include <sstream>;
using namespace std;

class Regional2018 {
	//00196205

	/*
		Name: main();
		Input: None;
		Output: A vector of words;
		Purpose: Gets all words from a file and returns them in a string vector;
	*/
	vector<string> getWordsFromLibrary() {
		vector<string> words = {};
		string line;
		ifstream fileReader("lib.txt");

		while (getline(fileReader, line)) {
			words.push_back(line);
		}
		if (line == "") {
			cout << "Error Reading the File\n";
		}

		return words;
	}

public:
	/*
		Name: main();
		Input: None;
		Output: None;
		Purpose: Creates a random passwords from the words given in the library;
	*/
	void main() {
		system("cls");
		srand(time(0));
		vector<string> words = getWordsFromLibrary();
		string output = "";
		int count;

		if (words.size() == 0) {
			return;
		}
		
		cout << "Please enter the number of words in the phrase: ";
		cin >> count;

		if (count < 0) {
			cout << "Please use a positive integer.\n";
			return;
		}

		vector<string> available_words = words;
		while (count > 0) {
			if (available_words.size() <= 0) {
				available_words = words;
			}
			int index = rand() % available_words.size();
			output += available_words.at(index);
			
			//Remove element at index
			vector<string> temp_words;
			for (string s : available_words) {
				if (available_words.at(index) != s) {
					temp_words.push_back(s);
				}
			}
			available_words = temp_words;

			count--;
		}
		cout << "The result phrase: " << output << "\n";
	}
};

class Regional2016 {
	/*
		Name: generateFibonacciNumbers();
		Input: None;
		Output: None;
		Purpose: Calculates and displays all fibonacci numbers up to 20;
	*/
	void generateFibonacciNumbers() {
		int current_number = 1;
		int previous_number = 0;
		int previous_number_holder = 0;

		for (int i = 0; i < 20; i++) {
			cout << "Fibonacci # " << i + 1 << " is: " << current_number << "\n";
			previous_number_holder = current_number;
			current_number += previous_number;
			previous_number = previous_number_holder;
		}
	}

	/*
		Name: generatePerfectNumbers();
		Input: None;
		Output: None;
		Purpose: Calculates and displays all perfect numbers less than 1000;
	*/
	void generatePerfectNumbers() {
		cout << "Here are all the perfect numbers less than 1000.\n";
		for (int i = 1; i < 1001; i++) {
			int total = 0;
			for (int divisor = 1; divisor < i; divisor++) {
				if (i % divisor == 0) {
					total += divisor;
				}
			}
			if (i == total) {
				cout << i << "\n";
			}
		}
	}
public:
	void main() {
		while (true) {
			system("cls");
			cout << "***********************************\n";
			cout << " Special Number Generator          \n";
			cout << "***********************************\n";
			cout << "1) Calculate Fibonacci Numbers\n";
			cout << "2) Calculate Perfect Numbers\n";
			cout << "3) Exit Program\n";
			cout << "Please select an option : ";

			string input;
			cin >> input;
			cout << "\n";

			if (input == "1") {
				generateFibonacciNumbers();
			}
			else if (input == "2") {
				generatePerfectNumbers();
			}
			else if (input == "3") {
				return;
			}
			else {
				cout << "Invalid Option entered";
			}

			cout << "\nPress any key to continue . . . ";
			cin >> input;
		}
	}
};


int main() {
	bool is_done = false;
	while (!is_done) {
		cout << "CPP 2, Electric Boogaloo\n\n";
		cout << "Select a BPA Test:\n";
		cout << "(1) Regional 2018\n";
		cout << "(2) Regional 2016\n";

		string input;
		cin >> input;
		if (input == "quit") {
			is_done = true;
			continue;
		}
		else if (input == "1") {
			Regional2018 r = Regional2018();
			r.main();
		}
		else if (input == "2") {
			Regional2016 r = Regional2016();
			r.main();
		}
		else {
			system("cls");
			continue;
		}
		cout << "\nType Anything to Continue: ";
		cin >> input;
		system("cls");
	}
	return 0;
}