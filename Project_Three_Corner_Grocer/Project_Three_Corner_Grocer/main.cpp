// Curtis Hetrick
// June 23, 2024

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class ProduceItem { // Class used to create objects for each item and their count
public:
	ProduceItem() { name = "none"; count = 0; }
	void SetName(string itemName) { this->name = itemName; }
	void SetCount(int itemCount) { this->count = itemCount; }
	string getName() { return name; }
	int getCount() { return count; }
private:
	string name;
	int count;
};

void menuChoice(string choice, bool& quit, vector<string> fullList, vector<ProduceItem> objectList);
int main() {
	bool quit = false;
	string userInput;
	int i = 0; // For loop iteration variable
	string fileString;	// string variable to receive input from file
	ifstream inFS;	// File input stream
	ofstream outFS;	// File output stream for backup file
	vector<string> fileList; // Initial list to take all strings from file
	//vector<int> itemCount;	// Vector to hold count of item in same index as noDupeList
	vector<string> noDupesList;	// Vector to hold items without duplicates
	vector<ProduceItem> objectList;

	inFS.open("CS210_Project_Three_Input_File.txt");
	if (!inFS.is_open()) {	// Displays message if file fails to open
		cout << "Could not open file CS210_Project_Three_Input_File.txt" << endl;
		return 1;
	}

	// Take first input from file prior to entering loop
	inFS >> fileString;
	while (!inFS.fail()) {	// iterates through file, putting each string into a vector
		fileList.push_back(fileString);
		inFS >> fileString;
	}
	inFS.close();	// closes input file after it has been fully read

	outFS.open("frequency.dat");	// Opening backup output file to begin pre-emptive item count backup
	if (!outFS.is_open()) {	// Displays message if backup file fails to open
		cout << "Could not open file frequency.dat" << endl;
	}
	for (i = 0; i < fileList.size(); ++i) {
		// If branch in case item from fileList is a duplicate
		if (find(noDupesList.begin(), noDupesList.end(), fileList.at(i)) != noDupesList.end()) {
			continue;
		}
		else { // Creates new ProduceItem object with corresponding name and count, then adds it to list of objects
			noDupesList.push_back(fileList.at(i));
			ProduceItem newItem; // Initializes new ProduceItem object 
			newItem.SetName(fileList.at(i)); // Sets object's name to current loop iteration's element
			newItem.SetCount(count(fileList.begin(), fileList.end(), fileList.at(i))); // Uses count() to set item count
			objectList.push_back(newItem); // Item is added to list of items
			outFS << fileList.at(i) << "---" << newItem.getCount() << endl;
		}
	}
	outFS.close();	// Closes backup file before any user action occurs
	
	// Enter menu loop
	while (quit != true) {
		cout << "____Corner Grocer Menu____" << endl
			<< "[1] Specific Item Search" << endl
			<< "[2] Numeric Item Count" << endl
			<< "[3] Item Count Histogram" << endl
			<< "[4] Exit Program" << endl
			<< "Enter a menu number. " << endl;
		cin >> userInput;
		menuChoice(userInput, quit, fileList, objectList);
	}
	
}

void menuChoice(string choice, bool& quit, vector<string> fullList, vector<ProduceItem> objectList) {
	string newInput;
	if (choice == "4") { 
		quit = true;
		cout << "Exiting Program..." << endl;
	}

	else if (choice == "1") {	// Checks if item is in list and if true, displays item purchase count
		cout << "\nEnter the name of an item to search for: ";
		cin >> newInput;
		newInput[0] = toupper(newInput[0]); // Automatically capitalizes to help since all elements have a capital
		if (find(fullList.begin(), fullList.end(), newInput) != fullList.end()) {	// finds item in list if it exists
			cout << newInput << " were bought " << count(fullList.begin(), fullList.end(), newInput) << " time(s).\n" << endl;
		}
		else {	// Informs user that item is not in list
			cout << "No item by that name was found in the list.\n" << endl;
		}
	}

	else if (choice == "2") {	// Iterates through objects and calls their getName() and getCount() functions
		cout << "\nList of all items bought and their purchase count:" << endl;
		for (int i = 0; i < objectList.size(); ++i) {
			cout << objectList.at(i).getName() << "---" << objectList.at(i).getCount() << endl;
		}
		cout << endl;
	}

	else if (choice == "3") {	// Iterates through each object and uses getCount() function to determine asterisk number
		cout << "\nHistogram of all items purchased (One * per purchase of that item):" << endl;
		for (int i = 0; i < objectList.size(); ++i) {	// Loop which picks an object and first calls it's getName() function
			cout << objectList.at(i).getName() << " ";
			for (int j = 0; j < objectList.at(i).getCount(); ++j) {	// Loop which iterates based on getCount() of current object for asterisks
				cout << '*';
			}
			cout << endl;
		}
		cout << endl; // Newlines to keep output evenly spaced
	}
	cout << endl;
}
