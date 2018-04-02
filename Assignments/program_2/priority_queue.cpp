///////////////////////////////////////////////////////////////////////////////
//                   YOU MUST COMPLETE AND COMMENT YOUR CODE!
// Title:            (program's title)
// Files:            (list of source files)
// Semester:         (course) Spring 2018
//
// Author:           (your name)
// Email:            (your email address)
// Description:
//       describe program here thoroughly
/////////////////////////////////////////////////////////////////////////////////


/**
* Function Push:
*      Pushes an item onto the stack.
*
* Params:
*      [int] val - value of item being pushed
* Returns
*      void
*/

/////////////////////////////////
// List Based Queue
//
// First In First Out
//
// Method:
//    void push()
//    string pop()
//    bool empty()
//    bool full() ?????
/////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

/**
* class Queue
*     description of what this class does ...
* Methods:
*  - Queue()       : constructor
*  - string pop()  :
*/
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
	* pop
	*
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

	bool empty()
	{
		return (Front == NULL);
	}

	void print()
	{
		Node *temp = Front;
		while (temp)
		{
			cout << temp->val << "->";
			temp = temp->next;
		}
		cout << endl;
	}

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

	void sort()
	{
		string animal1, animal2, tempAnimal;
		Node *temp = Front;
		while (temp->next != NULL)
		{
			animal1 = temp->val;
			animal2 = temp->next->val;

			if (animal1.length() > animal2.length()) {
				tempAnimal = animal1;
				animal1 = animal2;
				animal2 = tempAnimal;
			}

			else if (animal1.length() == animal2.length()) {
				if (animal1 > animal2) {
					tempAnimal = animal1;
					animal1 = animal2;
					animal2 = tempAnimal;
				}
			}
			temp = temp->next;
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

	infile.open("input_data.txt");
	outfile.open("priority_out.txt");

	outfile << "Animals Popped off the Queue: \n \n";
	
	while (!infile.eof()) {
		infile >> pushOrPop;
		if (pushOrPop == "push") {
			infile >> animal;
			Q.push(animal);
		}
		else {
			outfile << count++ << " " << animal << endl;
			Q.pop(animal);
		}
	}
	
	
	cout << "Animals that remained on the Queue: \n \n";
	Q.sort();
	Q.print();

	

	infile.close();
	outfile.close();
	system("pause");
	return 0;
}
