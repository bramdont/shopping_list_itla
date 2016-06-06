/*
 * List.cpp
 *
 *  Created on: May 22, 2016
 *      Author: raydelto
 */

#include "List.h"
#include "Element.h"
#include <iostream>
#include <cstdlib>
using namespace std;

List::List(): _first(NULL), _last(NULL)
{


}

void List::add(Element* element)
{
	if (_first == NULL) //When the list is empty the element added is the first and the last
	{
		_first = element;
		_last = element;

	}else // when the list is not empty, the actual last have the new element as next and the new element is now the last
	{
		_last -> setNext(element);
		_last = element;

	}

}

void List::remove(int index)
{
	char ans; // user answer

	cout << "Are you sure you want to remove the element " << index << " [Y/N]" << endl;
	cin >> ans;

	if (ans == 'Y' || ans == 'y')
	{
		cout << "The element "<< index <<" has been removed.";
	}
	// this is only a test, this do not eliminate the element
}
