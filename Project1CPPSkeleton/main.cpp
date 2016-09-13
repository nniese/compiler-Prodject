/*
 * main.cpp
 *
 *  Created on: Aug 31, 2015
 *      Author: bhoward
 *  Modified on: August 22, 2016
 *      Author: sthede
 */

#include "Scanner.h"

#include <iostream>
using namespace std;

int main() 
{
	Scanner scanner( cin );
	Token token;

	do 
	{
		token = scanner.next();
		cout << token << endl;
	} while (token.type != EOFILE);
}
