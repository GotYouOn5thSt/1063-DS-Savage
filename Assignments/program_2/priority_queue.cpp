///////////////////////////////////////////////////////////////////////////////
// Title:            Program 2
// Files:            priority_queue.cpp
//                   priority_out.txt
//                   input_data.txt
// Semester:         1063 Spring 2018
//
// Author:           Roderic Savage
// Email:            ericsavage99@gmail.com
// Description:
//       This programs takes an input file of 450 rows and 2 columns. This first
//       column is a command of "push" or "pop". The second column is an animal
//       name. A queue is created, and the information is then pushed onto and
//       popped off of the queue per the command from the first column of the
//       file. The items in the queue are also re-arranged by length and 
//       alphabetical position. What remains in the queue is printed via a 
//       method titled "print", and items popped from the queue are printed to 
//       the output file titled "priority_out.txt"
/////////////////////////////////////////////////////////////////////////////////




#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
* Function countLen:
*      counts characters in string.
*
* Params:
*      [string] val - value of item being pushed
* Returns
*      int
*/
int countLen(char *word)
{
	int l = 0;
	while (*word)
	{
		*word++;
		l++;
	}
	return l;
}

struct Node
{
	string val;
	Node *next;
	Node()
	{
		val = " ";
		next = NULL;
	}
	Node(string v)
	{
		val = v;
		next = NULL;
	}
};


// List Based Queue
//
// First In First Out
//
// Method:
//    void push()
//    string pop()
//    bool pop()
//    bool empty()
//    void print() 
//	  void sort()

class Queue
{
private:
	Node *Front;
	Node *Rear;

public:
	/**
	* Queue
	* constructor
	*
	* params:
	*     - none
	*/
	Queue()
	{
		Front = Rear = NULL;
	}

	/**
	* Function pop:
	*      pops item off of queue.
	*
	* Params:
	*      none
	* Returns
	*      string
	*/
	string pop()
	{
		if (!empty())
		{
			Node *temp = Front;   // temp pointer so we can delete node
			string v = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			return v;
		}
		else
		{
			cout << "error: cannot pop off empty queue." << endl;
			return " ";
		}
	}
	/**
	* Function push:
	*      pushes item onto queue.
	*
	* Params:
	*      [string] v - value inside of node
	* Returns:
	*      none
	*/
	void push(string v)
	{
		Node *n = new Node(v);

		// handle the empty case
		if (empty())
		{
			Front = n;
			Rear = n;
		}
		else
		{
			// not empty add to rear
			Rear->next = n;
			Rear = n;
		}
	}

	/**
	* Function empty:
	*      tests for empty queue
	*
	* Params:
	*      none
	* Returns
	*      bool
	*/
	bool empty()
	{
		return (Front == NULL);
	}

	/**
	* Function print:
	*      prints popped items onto output file.
	*
	* Params:
	*      none
	* Returns
	*      none
	*/
	void print()
	{
		Node *temp = Front;
		int count = 1;
		while (temp)
		{
			cout << count++ << " " << temp->val << endl;
			temp = temp->next;
		}
		cout << endl;
	}

	/**
	* Function pop:
	*      pops items off of queue
	*
	* Params:
	*      [string] &v - value of node
	* Returns:
	*      bool
	*/
	bool pop(string &v)
	{
		if (!empty())
		{
			Node *temp = Front;   // temp pointer so we can delete node
			string t = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			v = t;
			return true;
		}
		else
		{
			cout << "error: cannot pop off empty queue." << endl;
			return false;
		}
	}

	/**
	* Function sort:
	*      sorts queue by length and alphabet
	*
	* Params:
	*      none
	* Returns:
	*      none
	*/
	void sort()
	{
		string tempAnimal = "";    // created temporary variable for swap
		Node* animal1 = Front;     // pointer initialized to "Front"
		Node* animal2 = Front;     // pointer initialized to "Front"
		bool swapped = false;      // setting condition to test for later
		while (animal1)
		{
			animal2 = animal1->next;   // guarantees that animal2 is ahead of ...
			while (animal2) {          // animal1 while traversing list
				if (animal1->val.length() > animal2->val.length()) {
					swapped = true;
					tempAnimal = animal1->val;     // the next three lines
					animal1->val = animal2->val;   // are the swap
					animal2->val = tempAnimal;
				}
				animal2 = animal2->next;   // iterates to the next node
			}
			animal1 = animal1->next;    // iterates to the next node
		}
		if (!swapped) {
			return;
		}
	}
};

int main()
{
	Queue Q;
	string pushOrPop, animal;
	int count = 1;

	ifstream infile;
	ofstream outfile;

	infile.open("input_data.txt");     // input information from external source
	outfile.open("priority_out.txt");  // output information to external source

	outfile << "Animals Popped off the Queue: \n \n";

	while (!infile.eof()) {    // this loop separates the list by initial command
		infile >> pushOrPop;
		if (pushOrPop == "push") {
			infile >> animal;
			Q.push(animal);    // pushes onto queue if command equals "push"
		}
		else {
			outfile << count++ << " " << animal << endl;
			Q.pop(animal);    // pops from queue if command equals "pop"
		}
	}


	cout << "Animals remaining on the Queue (in order of priority): \n \n";
	Q.sort();                 // sorts list in queue by length and alphabet
	Q.print();                // prints "popped" to output file 



	infile.close();
	outfile.close();
	system("pause");
	return 0;
}
