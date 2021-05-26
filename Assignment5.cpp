//Sohan Byrapuneni
//sbyrapun@asu.edu

/*
HASH ANALYSIS
- My hash function is just the remainder of the ASCII sum of all values in the project name (index = sum % hashSize)
-The number of collision was exactly what I expected, overall the hash function woeked well and I didn't have to make any changes to it
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include "hashTable.h"
#include "linkedList.h"

#pragma warning(disable: 4996)

using namespace std;


int main() {
	int size, commandNum,count,index,firstC;
	string command, input,first,searchName;
	
		//Gets the user input of the hash table size and with the size creates table with the constructor 
		cout << "Please enter a hash table size: " << endl;
		cin >> size;
		cin.ignore(20, '\n');
		cin.clear();
		hashTable * list1 = new hashTable(size);
		
		//do-While loop that takes the chained hash table with user created projects
		do {
			//cin >> input;
			getline(cin,input);
			
			//cin.ignore(20, '\n');
			// Exit while-loop if the user inputs 'EndOfInsertion'
			if (input == "EndOfInsertion") {
				break;
			}
			//Set 'first' equal to the projectName
			firstC = input.find(',', 0);
			first = input.substr(0, firstC);
			//count is the string length
			count = first.length();
			//Set index equal to the hash Function of string
			index = list1->hashFunction(first, count);
			//Using index insert Project into the hash Function
			list1->insert(input, index);
		}while (input != "EndOfInsertion");
		
		//Get user input for the amount of commands
		cout << "Please enter a number of commands: " << endl;
		cin >> commandNum;
		cin.ignore(20, '\n');
		cin.clear();
		//While Loop ends depending on command count
		while (commandNum > 0) {
			cout << "Command: " << endl;
			//cin >> command;
			getline(cin,command);
			//if there is a '/' in the command split it into two parts, one with command and other with projName
			if (command.find('/', 0)) {
				firstC = command.find('/',0);
				searchName = command.substr(firstC+1);
				count = searchName.length();
				command = command.substr(0, firstC); 
			}
			//Does whatever command the user asks for
			if (command == "hash_display") {
				list1->display();
			}
			else if (command == "hash_search") {
				index = list1->hashFunction(searchName,count);
				list1->search(searchName, index);
			}
			else if (command == "hash_delete") {
				index = list1->hashFunction(searchName, count);
				list1->remove(searchName,index);
			}
			else if (command == "hash_max_cost") {
				list1->maxCost();
			}
			else {
				break;
			}
			commandNum--;
		}
}

