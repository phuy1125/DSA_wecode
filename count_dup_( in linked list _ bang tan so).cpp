
#include <iostream>
using namespace std;

struct Node {
	int data;
	int hz;
	Node* next;

};

struct List {
	Node* Head;
	Node* Tail;
};

Node* makeNode(int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

Node* _makeNode(int data,int hz) {
	Node* temp = new Node();
	temp->data = data;
	temp->hz = hz;
	temp->next = NULL;
	return temp;
}


void InitList(List& lst) {
	lst.Head = NULL;
	lst.Tail = NULL;
}

void insertLast(List& lst, Node* temp) {
	if (lst.Head == NULL) {
		lst.Head = temp;
		lst.Tail = temp;
	}

	else {
		lst.Tail->next = temp;
		lst.Tail = temp;
	}
}

int countOccurrences(List lst, int value) {
	Node* current = lst.Head;
	int count = 0;
	while (current != nullptr) {
		if (current->data == value) {
			count++;
		}
		current = current->next;
	}

	return count;
}

void sort(List& tempList, int& value, int& hz) {
	Node* temp = tempList.Head;
	Node* prev = NULL;
	while (temp != NULL && temp->data < value) {
		prev = temp;
		temp = temp->next;
	}
	Node* p = _makeNode(value, hz);
	if (prev == NULL) {
		tempList.Head = p;
		p->next = temp;
	}
	else if (temp == NULL) {
		prev->next = p;
	}
	else {
		p->next = temp;
		prev->next = p;
	}
}

void countDuplicate(List lst,List& tempList) {
	Node* current = lst.Head;
	List uniqueList;
	InitList(uniqueList);
	while (current != nullptr) {
		int data = current->data;
		bool isDuplicate = false;
		Node* uniqueNode = uniqueList.Head;
		while (uniqueNode != nullptr) {
			if (uniqueNode->data == data) {
				isDuplicate = true;
				break;
			}
			uniqueNode = uniqueNode->next;
		}

		if (!isDuplicate) {
			insertLast(uniqueList, makeNode(data));
			int x = countOccurrences(lst, data);
			sort(tempList, data,x);
			/*cout << data << ": " << countOccurrences(lst, data) << endl;*/
		}
		current = current->next;
	}
}

void print(List lst) {
	if (lst.Head == NULL) {
		return;
	}
	else {
		Node* temp = lst.Head;
		while (temp != NULL) {
			cout << temp->data << " "<<temp->hz<<endl;
			temp = temp->next;
		}
	}
}

int main() {
	List lst;
	InitList(lst);
	List tempList;
	InitList(tempList);
	int x;
	do
	{
		cin >> x;
		if (x != 0) {
			Node* temp = makeNode(x);
			insertLast(lst, temp);
		}
	} while (x!=0);
	countDuplicate(lst, tempList);
	print(tempList);
	return 0;
}
