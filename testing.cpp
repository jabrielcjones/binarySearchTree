/** Filename:	driver.cpp
 *  Name:		Jabriel C. Jones
 *  Date:		1 May 2011
 *  Purpose:	Read integer values from a file and store them in the
 *					ADT Binary Search Tree.
 */

#include <iostream>						// for input/output stream
#include <fstream>						// for file stream
#include "binary-search-tree01.h" // for binary_search_tree class

using namespace std;

// ============================= CONSTANTS ============================ //
const int NAMESIZE = 100;


int lessThanInt(const int &, const int &);
int equals(const int &, const int &);
void displayIntNode(int &);

int main()
{
	ifstream		inFile;
	BinarySearchTree <int>	one(lessThanInt, equals);
	
	//openFile(inFile);
	
	return 0;
}

