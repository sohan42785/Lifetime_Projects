//Sohan Byrapuneni
//sbyrapun@asu.edu
#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#pragma warning(disable: 4996)

using namespace std;

struct Project {
	string projName;
	string region;
	int cost;
	struct Project * next;
};

class linkedList
{
private:
	
public:
	linkedList(); //Constructor

	int listSize;
	struct Project * head;

	void displayList(linkedList list, int size);
	int searchList(linkedList list, string name, int size);
	int maxCost(linkedList list, int size);
	string maxCostString(linkedList list, int size,int maxCost);
	int removeElement(linkedList list, string name, int size);

};

//Constructor
linkedList::linkedList()
{
	head = NULL;
	listSize = 0;
}

//This displays the elements in the linkedList for each hash table index
void linkedList::displayList(linkedList list, int size) {
	//Sets ptr equal to the head of the linked list
	Project * ptr = list.head;
	//goes through each project in the linked list and prints the details
	for (int i = 0; i < size;i++) {
		cout << "Project Name: " << ptr->projName << endl;
		cout << "Region: " << ptr->region << endl;
		cout << "Cost: " << ptr->cost << endl;
		cout << endl;
		//goes to the next node in the linked list
		ptr = ptr->next;
	}
}

//Tries to find the name the user inputed
int linkedList::searchList(linkedList list, string name, int size) {
	//Set ptr equal to the head of the linked list
	Project * ptr = new Project();
	ptr = list.head;
	//goes through the linked list searching for the project name
	for (int i = 0; i < size;i++) {
		if (ptr->projName == name) {
			return ptr->cost;	//return the cost value if the project is found
		}
		//go to next node in linked list
		ptr = ptr->next;
	}
	//return -1 if name isn't found
	return -1;
}

//This function searches for the max cost of a project
int linkedList::maxCost(linkedList list, int size) {
	int max = 0;
	//sets ptr equal to the head of the linked list
	Project *ptr = new Project();
	ptr = list.head;
	//if there are no elements in the linked list then return 0
	if (size == 0) {
		return 0;
	}
	//otherwise iterate through the linked list and return the max value of the linked list
	else {
		for (int i = 0; i < size;i++) {
			if (ptr->cost > max) {
				max = ptr->cost;
			}
			ptr = ptr->next;
		}
	}
	return max;
}

string linkedList::maxCostString(linkedList list,int size,int maxCost) {
	//set ptr equal to the head of the linked list
	Project *ptr = new Project();
	ptr = list.head;
	//if linked list size is equal to zero then return an empty string
	if (size == 0) {
		return "";
	}
	//otherwise iterate through the linked list and return the name of the project with the largest cost 
	else {
		for (int i = 0; i < size;i++) {
			if (ptr->cost == maxCost) {
				return ptr->projName;
			}
			ptr = ptr->next;
		}
	}
}

//This function removes the chosen project from the linked list
int linkedList::removeElement(linkedList list, string name, int size) {
	//sets ptr equal to the head of the linked list
	Project * ptr = new Project();
	ptr = list.head;
	//prev is going to be the node before ptr
	Project * prev = NULL;
	int value = 0;
	//if linked list is empty return -1
	if (ptr == NULL) {
		return -1;
	}
	//If head node contains the name then return its cost
	else if (ptr->projName == name) {
		value = ptr->cost;
		list.head = list.head->next;
		return value;
	}
	//otherwise keep iterating through the linked list until the name of the project is found
	else {
		prev = list.head;
		//The loop continues as long as ptr isn't NULL
		while(ptr != NULL) {
			//if the value we want to remove is found
			if (ptr->projName == name) {
				//set the prev pointer past the current pointer and equal to the next one
				value = ptr->cost;
				prev->next = ptr->next;
				return value;
			}
			prev = ptr;
			ptr = ptr->next;
		}
	}
}
