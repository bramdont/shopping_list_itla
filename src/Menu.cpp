/*
 * Menu.cpp
 *
 *  Created on: May 22, 2016
 *      Author: raydelto
 */

#include "Menu.h"
#include "List.h"
#include "Element.h"
#include <iostream>
#include <cstdlib>
using namespace std;

List* list = new List();

Menu::Menu()
{

}

void Menu::clearScreen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

void Menu::pause()
{
	#ifdef _WIN32
	system("pause");
	#else
	system("read -n1 -r -p \"Press any key to continue...\" key");
	#endif
}


bool Menu::validate(int option)
{
	if(option >= 1 && option <= 4)
	{
		return true;
	}else
	{
		cout << "Please pick an option between 1 and 4"<< endl;
		pause();
		return false;
	}
}

void Menu::routeAction(int option)
{
	switch(option)
	{
	case 1:
		listItems();
		break;
	case 2:
		addItems();
		break;
	case 3:
		removeItems();
		break;
	case 4:
		cout << "Thanks for using our software, good bye!" << endl;
	}
	pause();
}

void Menu::listItems()
{
	Element* i = list -> getFirst();
	int position = 1; // to identify the position of the element
	while (i != NULL)
	{

		cout << position++ << " - "<< i -> getName() << endl;
		i = i -> getNext();
	}
}

void Menu::addItems()
{
	string name;

	cout << "Type the element Name: ";
	cin >> name;

	Element* element = new Element(name);

	list -> add(element); // add the element to the list
	cout << "New element added successfully to the list";

}

void Menu::removeItems()
{

	int position;
	int counter = 1;

	cout << "Introduce the position of the element you want to remove: ";
	cin >> position;
	list -> remove(position);
	Element* beforeTheRemoved = list -> getFirst();


	while (counter < position ) // to get the element before the one to be remove and point
	{								// the next after the removed one.
		counter++;
		beforeTheRemoved = beforeTheRemoved ->getNext();
	}

	Element* afterTheRemoved = beforeTheRemoved;
	afterTheRemoved = afterTheRemoved -> getNext();// the actual one to be removed
	afterTheRemoved = afterTheRemoved -> getNext();// the one after the element to be removed

	beforeTheRemoved -> setNext(afterTheRemoved);


}

void Menu::show()
{
	int option;
	do
	{
		clearScreen();
		cout << "ITLA Shopping List" << endl;
		cout << "1- List items" << endl;
		cout << "2- Add Item" << endl;
		cout << "3- Remove Item" << endl;
		cout << "4- Exit" << endl;
		cout << "Select an option => ";
		cin >> option;
		if(validate(option))
		{
			routeAction(option);
		}
	}while(option !=4);
}
