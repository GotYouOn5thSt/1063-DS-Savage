#include <iostream>
#include <ctime>

using namespace std;
struct node {
	int data;
	node* next;
};

class intLinkedList {
private:
	node* Head;
public:
	intLinkedList() {
		Head = NULL;
	}
	void insert(int x) {
		//empty list case
		if (!Head) {
			Head = new node;
			Head->data = x;
			Head->next = NULL;
		}
		else {//not empty list
			node* T = new node;
			T->data = x;
			T->next = Head;
			Head = T;
		}
	}

	node* Find(int key) {
		node* temp = Head;
		while (temp) {
			if (temp->data == key) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}

	node* Remove(int key) {
		node* result = Find(key);
		if (result) {
			node* temp = Head;
			while (temp->next != result) {
				temp = temp->next;
			}
			temp->next = result->next;
			delete result;
		}
	}

	void print() {
		node* p = Head;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

	void divideByX(int x) {
		node* banana = Head;

		while (banana) {
			banana->data /= x;
			banana = banana->next;
		}
	}

	//assumptions are list is >= length(2);
	// swaps sets of neighbors
	// 1: head->A->B->C->D->E->NULL
	// 2: head->B->A->D->C->E->NULL
	void swapNeighbors() {
		node* prev = Head;
		node* temp = Head->next;
		int tempvar;

		while (temp->next) {
			tempvar = temp->data;
			temp->data = prev->data;
			prev->data = tempvar;

			prev = prev->next->next;
			temp = temp->next->next;
		}
	}

};

int main() {
	srand(8734587);

	intLinkedList mylist;
	for (int i = 0; i<10; i++) {
		mylist.insert(rand() % 100);
	}
	//mylist.print();
	//cout<<mylist.Find(99)<<endl;
	//mylist.Remove(58);
	mylist.print();
	mylist.swapNeighbors();
	mylist.print();

	system("pause");
	return 0;

}
