/////////////////////////////////////////////////////////////////////////////////////////////
// ProgramName: Program-3: Survival of the Lucky
// Author: Roderic Savage 
// Description: 
//     This program reads in a list of animal names, places them into a doubly linked list
//     (while keeping them alphabetized), traverses the list according to whether a value from
//     the input file is even or odd, and from a user inputted number, "dispatches" an animal
//     in the list, and then continues to traverse and "dispatch" until only one animal
//     remains.
// Course: 1063 Data Structures
// Semester: Spring 2018
// Date: 27 04 2018
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Node {
	string animal;
	Node* next;
	Node* prev;
};

class SeigeOfYodfat {
private:
	Node* Head;
	Node* Tail;
	Node* Current;
public:
	SeigeOfYodfat()
		Head = NULL;
		Current = NULL;
		Tail = NULL;
		/**
		* InsertFront -
		*     Inserts a value at the front of the list by calling
		*     actual insert with a node.
		* Params:
		*     string : data element to be inserted
		*/
	void InsertFront(string x) {
		Node* Temp = new Node(x);
		InsertFront(Temp);
	}
	/**
	* InsertFront -
	*     Inserts a value at the front of the list by calling
	*     actual insert with a node.
	* Params:
	*     string : data element to be inserted
	*/
	void InsertFront(Node* &Temp) {

		if (!Head) {
			Head = Temp;
			Tail = Temp;
			Tail->next = Head;
			Current = Temp;
			Head->prev = Tail;
		}
		else {
			Temp->next = Head;
			Temp->prev = Tail;
			Head->prev = Temp;
			Tail->next = Temp;
			Head = Temp;
			Current = Head;
		}
	}
	/**
	* InsertRear -
	*     Inserts a value at the rear of the list by calling
	*     actual insert with a node.
	* Params:
	*     pointer : add by reference
	*/
	void InsertRear(Node* &Temp) {

		if (!Head) {
			InsertFront(Temp);
		}
		else {

			Tail->next = Temp;
			Temp->prev = Tail;
			Tail = Temp;
			Temp->next = Head;
			Head->prev = Tail;
			Current = Tail;
		}
	}
	/**
	* InsertRear -
	*     Inserts a value at the rear of the list by calling
	*     actual insert with a node.
	* Params:
	*     string : data element to be inserted
	*/
	void InsertRear(string x) {
		if (!Head) {
			InsertFront(x);
		}
		else {
			Node* Temp = new Node(x);
			InsertRear(Temp);

		}
	}
	/**
	* InsertInOrder -
	*     Inserts a value in order of the list by calling
	*     actual insert with a node.
	* Params:
	*     string : data element to be inserted
	*/
	void InsertInOrder(string Data) {
		if (!Head) {
			InsertFront(Data);
		}
		else {
			Node* Temp = new Node(Data);
		}
	}
	/**
	* Delete -
	*     Deletes head of linked list. Rearranges pointers as needed. 
	* Params:
	*     string : data element to be inserted
	*/
	bool Delete(string x) {
		if (Head == Tail && Head->animal == x) {
			delete Head;
			Head = NULL;
			Tail = NULL;
			Current = NULL;
			return true;
		}
		else if (Head->animal == x) {
			Head = Head->next;
			Current = Head;
			delete Head->prev;
			Head->prev = Tail;
			return true;
		}
		else if (Tail->animal == x) {
			cout << "deleting tail...\n";
			Tail = Tail->prev;
			delete Tail->next;
			Tail->next = Head;
			Current = Tail;
			return true;
		}
		else {
			Node* Location = Find(x);            
			if (Location) {
				Location->prev->next = Location->next;
				Location->next->prev = Location->prev;
				Current = Location->next;
				delete Location;
				return true;
			}
		}
		return false;
	}
	/**
	* Find -
	*     Locates specific value in linked list.
	* Params:
	*     string : data element to be inserted
	*/
	bool Find(string x) {
		return false;
	}
	/**
	* Update -
	*     Updates string elements of linked list.
	* Params:
	*     string : data element to be inserted
	*/
	bool Update(string x, string y) {
		return false;
	}
	/**
	* Prints -
	*     Prints strings inside of linked lists
	* Params:
	*     string : data element to be inserted
	*/
	void Print(int columns) {
		Node *Temp = Head;
		int count = 1;

		while (Temp != Tail) {
			cout << Temp->animal << " ";
			Temp = Temp->next;
			if (columns && count % columns == 0)
				cout << endl;
			count++;
		}
		cout << Tail->animal << " ";
	}
	/**
	* Print -
	*     Prints value.
	* Params:
	*     none
	*/
	void Print() {
		Print(0);
	}

	/**
	* rPrint -
	*     Prints value.
	* Params:
	*     none
	*/
	void rPrint() {
		rPrint1(Tail);
	}
	/**
	* rPrint -
	*     Prints value.
	* Params:
	*     node pointer
	*/
	void rPrint(Node* Head) {
		if (Head == Tail) {
			return;
		}
		else {

			rPrint(Head->next);
			cout << Head->animal << " ";
		}
	}
	/**
	* rPrint1 -
	*     Prints value
	* Params:
	*     node pointer.
	*/
	void rPrint1(Node* Tail) {
		if (Tail == Head) {
			return;
		}
		else {
			cout << Tail->animal << " ";
			rPrint1(Tail->prev);
		}
	}


	/**
	* Find -
	*     Traverses list checking to see if string value matches key.
	* Params:
	*     string : data element
	*/
	Node* Find(string key) {
		Node* Temp = Head;

		while (Temp) {
			if (Temp->Data == key) {
				return Temp;
			}
			Temp = Temp->next;
		}
		return NULL;
	}

	/**
	* MovieIt -
	*     shuffles data around the circle.
	* Params:
	*     int
	*/
	void MoveIt(int move) {
		Node *temp = Current;
		if (move % 2 == 0)
		{
			for (int i = 0; i<move; i++)
			{
				Current = Current->next;
			}
			cout << "right " << Current->animal << endl;
			if (Current->animal == "horse") {
				Print();
			}
			Delete(Current->animal);
		}
		else
		{
			for (int i = 0; i<move; i++)
			{
				Current = Current->prev;
			}
			cout << "left:" << Current->animal << endl;
			Delete(Current->animal);
		}

	}
};



int main()
{
	fstream infile;
	fstream outfile;
	infile.open("animals.txt");
	outfile.open("eliminated.txt");

	int multiplier;
	int rand;
	int count = 0;
	int length;
	int quit = 20;
	string a;



	cout << "Input a random seed" << endl;    // request for user input on random seed
	cin >> rand;
	srand(rand);

	while (!infile.eof()) {       // reads in animal name to linked list and counts animals
		cin >> a;
		count++;
		SeigeOfYodfat.InsertRear(a);
	}

	infile.clear();
	infile.seekg(0, std::ios::beg);   // return to beginning

	cout << "Please choose a value from 1 to 13 (inclusive). This will be our multiplier" << endl;
	cin >> multiplier      // requests user for integer input

	while (multiplier < 1 || multiplier > 13) {  // ensures that value inputted will fit within
		cout << "Incorrect value. Please try again." << endl;   // the range of 1 to 13.
		cin >> multiplier;
	}
	cout << "Multiplier: \t " << multiplier << endl;

	while (!infile.eof()) {
		infile >> a;

		for (int i = count; i > 1; i--) {
			length = a.length() * multiplier;
			cout << length;
			SeigeOfYodfat.MoveIt(length);
			infile >> a;
			if (a == "pheasant") {
				SeigeOfYodfat.Print();
			}
		}

	}






	infile.close();
	outfile.close();

	system("pause");
	return 0;
}
