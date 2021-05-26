//Sohan Byrapuneni
//sbyrapun@asu.edu
#pragma once

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include "linkedList.h"
#pragma warning(disable: 4996)

using namespace std;

class hashTable {

private:
	int hashSize;
	class linkedList * table;

public:
	hashTable(int n); //Constructor
	
	int hashFunction(string name, int count);
	void insert(string in, int index);
	void display();
	void search(string name, int index);
	void maxCost();
	void remove(string name, int index);

};

//Constructor
hashTable::hashTable(int n) {
	//initializes values of the hashTable depending on the user input
	table = new linkedList[n];
	hashSize = n;
	//Sets all the linked list size and head value equal to zero and null for each index
	for (int i = 0; i < n; i++) {
		table[i].listSize = 0;
		table[i].head = NULL;
	}
}
// This function determines the index of each Project
int hashTable::hashFunction(string name, int count) {
	int index = 0;
	int sum = 0;
	//Takes the ASCII sum of each character in "name" 
	for (int i = 0; i < count; i++) {
		sum += int(name.at(i));
	}
	//Sets the index equal to the remainder of the hash table size
	index = sum % hashSize;
	return index;
}
//This function inserts each Project into the hash table
void hashTable::insert(string in, int index) {
	table[index].listSize += 1;	//Increment linkedList size by 1
	struct Project * temp = new Project();	//Create a temp variable to hold the values of the name, region, and cost
	//Locates the first and second comma then using substring assigns a name, region, and cost into temp
	int firstComma = in.find(',', 0);
	int secondComma = in.find(',', firstComma+1);
	temp->projName = in.substr(0, firstComma);
	temp->region = in.substr(firstComma+1, secondComma-firstComma-1);
	temp->cost = stoi(in.substr(secondComma + 1));
	//checks if linked list head is null
	if (table[index].head == NULL) {
		table[index].head = temp;	//Assign temp value to head
		table[index].head->next = NULL;	//Create a new NULL space in linkedList
	}
	else {
		//else assign the new Project value to the front of the linked list
		temp->next = table[index].head;
		table[index].head = temp;
	}
}

//This function displays the hash table
void hashTable::display() {
	cout << "Hash Table Content" << endl;
	cout << "-------------------" << endl;
	cout << endl;
	//goes through the loop and displays the linked list in each index of the hash table
	for (int i = 0; i < hashSize; i++) {
		//if the list size is empty then output "list is empty"
		if (table[i].listSize == 0) {
			cout << "Index: " << i << ", linked list size: " << "0" << endl;
			cout << "The list is empty" << endl;
			cout << endl;
		}
		else {
			//Displays all the elements in each linked list for each index
			cout << "Index: " << i << ", linked list size: " << table[i].listSize << endl;
			table->displayList(table[i],table[i].listSize);
		}
	}
}

//This function searches for a project name using the index given by hash Function
void hashTable::search(string name, int index) {
	//Set c equal to the cost of the searched Project
	int c = table->searchList(table[index], name, table[index].listSize);
	//if c is not found then it should equal -1
	if (c != -1) {
		//if c is found
		cout << "The Project: " << name << " with Cost " << c << " is found" << endl;
	}
	else {
		//if c is not found
		cout << "The Project: " << name << " is not found" << endl;
	}
}

//This searches for the max cost and outputs the variables name
void hashTable::maxCost() {
	int max = 0;
	string maxString = "";
	int tempInt;
	//goes through all the elements of the hash table
	for (int i = 0; i < hashSize;i++) {
		//Searches the linked list in each index looking for the max cost
		tempInt = table->maxCost(table[i], table[i].listSize);
		//changes max variable if a larger project cost is found, also changes the string variable
		if (tempInt > max) {
			max = tempInt;
			maxString = table->maxCostString(table[i],table[i].listSize,max);
		}
	}
	//if max is equal to zero then the list is empty
	if (max == 0) {
		cout << "The list is empty" << endl;
	}
	//Otherwise the largest project cost and name are printed
	else {
		cout << "The Project: " << maxString << " has the highest cost of " << max << endl;
	}
}

//This function removes the chosen Project
void hashTable::remove(string name, int index) {
	//Sets x equal to the removed projects cost
	int x = table->removeElement(table[index],name,table[index].listSize);
	//if the project is not removed then x is equal to -1 
	if (x == -1) {
		cout << "The Project: " << name << " is not removed" << endl;
	}
	//Otherwise the project is removed and its cost and name are printed
	else {
		table[index].listSize--;
		cout << "The Project: " << name << " with Cost " << x << " is removed" << endl;
	}
}

#endif