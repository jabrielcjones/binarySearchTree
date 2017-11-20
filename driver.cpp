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

// ======================= Function Prototypes ======================== //
/** Reads in the integers and their operations and determines the method
 *  to be called.
 *  @param 	inFile	an ifstream object
 *  @param 	aTree		a BinarySearchTree object
 *  @pre		The file is open
 *  @post	The integers in the file are stored and the operations have
 * 			been executed. There is nothing left in the file.
 */
void processData(ifstream&, BinarySearchTree<int>&);

/** Reads in the name of the file and opens it if its valid.
 *  @param 	inFile 	an ifstream object.
 *  @pre		none.
 *	 @post 	file is opened.
 */
void openFile(ifstream&);

/** Adds an integer to the Binary Search Tree if the item is not already
 *  in the tree, otherwise a message is displayed.
 *  @param	item	integer variable
 *  @param	aTree	a BinarySearchTree object
 *  @pre		none
 *  @post	Integer is added to the tree or a message is displayed
 */
void add(int, BinarySearchTree<int>&);

/** Removes an integer from the Binary Search Tree if the item exists
 *  in the tree, otherwise a message is displayed.
 *  @param	item	integer variable
 *  @param	aTree	a BinarySearchTree object
 *  @pre		none
 *  @post	Integer is removed from the tree or a message is displayed
 */
void remove(int, BinarySearchTree<int>&);

/** Searches for an integer in the Binary Search Tree and outputs the
 *  results of the search
 *  @param	item	integer variable
 *  @param	aTree	a BinarySearchTree object
 *  @pre		none
 *  @post	Results of the search are outputed to the screen.
 */
void search(int, BinarySearchTree<int>&);

int lessThanInt(const int &, const int &);
int equals(const int &, const int &);
void displayIntNode(int &);

int main()
{
	ifstream							inFile;
	BinarySearchTree <int>		aTree(lessThanInt, equals);
	
	openFile(inFile);
	processData(inFile, aTree);
	
	return 0;
} /** end main function */


void openFile(ifstream& inFile)
{
   char file_name[NAMESIZE];

   do
   {
      cout << "Please enter file name:"<< endl;
      cin  >> file_name;
      inFile.open(file_name);

      if(!inFile)
      {
         cout << file_name
              << " could not be opened."
              << endl;
      }
   }while(!inFile);
}  /** end of openFile function */


void processData(ifstream& inFile, BinarySearchTree<int>& aTree)
{
	char		operation;
	int		num;
	
	while (inFile.peek() != '\n')
	{
		inFile >> num;
		add(num, aTree);
	}
	
	inFile >> operation;
	while (!inFile.eof())
	{
		
		inFile >> num;
		
		cout << "Operation: "
			  << operation
			  << " "
			  << num
			  << endl;
		
		if (operation == 'A')
			add(num, aTree);
		else if (operation == 'D')
			remove(num, aTree);
		else if (operation == 'S')
			search(num, aTree);
		else
			cout << "Invalid Operation: " << operation << endl;
		
		inFile >> operation;
	}
}	/** end processData */


void add(int item, BinarySearchTree<int>& aTree)
{	
	int		found;
	
	aTree.search(item, found);
	if (found)
	{
		cout << "The value "
			  << item
			  << " already exists in the file."
			  << endl;
	}
	else
		aTree.add(item);
	
	aTree.inorderTraversal(displayIntNode);
	cout << endl;
} /** end add */


void remove(int item, BinarySearchTree<int>& aTree)
{	
	int		found;
	
	aTree.search(item, found);
	if (!found)
	{
		cout << "The value "
			  << item
			  << " does not exist in the file."
			  << endl;
	}
	else
		aTree.remove(item);
	
	aTree.inorderTraversal(displayIntNode);
	cout << endl;
} /** end remove */


void search(int item, BinarySearchTree<int>& aTree)
{	
	int		found;
	
	aTree.search(item, found);
	if (found)
	{
		cout << "The value "
			  << item
			  << " exists in the file."
			  << endl;
	}
	else
	{
		cout << "The value "
			  << item
			  << " does NOT exist in the file."
			  << endl;
	}
} /** end search */


int lessThanInt(const int &one,
                const int &two)
{
   return (one < two);
}  /** end of lessThanInt */


int equals(const int &one,
           const int &two)
{
   return (one == two);
}  /** end of lessThanInt */


void displayIntNode(int &value)
{
   cout << value << " ";
}  /** end of displayIntNode */
