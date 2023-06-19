#include<iostream>
#include<vector>

struct Node {
	int data;
	Node* pLeft;
	Node* pRight;
};

void InitTree(Node*& T) {
	T = NULL;
}

void makeTree(Node*& t, int& x) {
	if (t == NULL) {
		Node* p = new Node;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else {
		if (t->data > x) {
			makeTree(t->pLeft, x);
		}
		else if (t->data < x) {
			makeTree(t->pRight, x);
		}
	}
}

void nodeTemp(Node*& x, Node*& y) {
	if (y->pLeft != NULL) {
		nodeTemp(x, y->pLeft);
	}
	else {
		x->data = y->data;
		x = y;
		y = y->pRight;
	}
}

void deleteNode(Node*& tree, int data) {
	if (tree == NULL) {
		return;
	}
	else {
		if (data < tree->data) {
			deleteNode(tree->pLeft, data);
		}
		else if (data > tree->data) {
			deleteNode(tree->pRight, data);
		}
		else {
			Node* x = tree;
			if (tree->pLeft == NULL) {
				tree = tree->pRight;
			}
			else if (tree->pRight == NULL) {
				tree = tree->pLeft;
			}
			else {
				nodeTemp(x, tree->pRight);
			}
			delete x;
		}
	}
}

bool _find(Node*& t, int& data) {
	if (t == NULL) {
		return false;
	}
	else {
		if (t->data > data) {
			return _find(t->pLeft, data);
		}
		else if (t->data < data) {
			return _find(t->pRight, data);
		}
		else {
			return true;
		}
	}
}

void printTree(Node*& t) {
	if (t != NULL) {
		std::cout << t->data << " ";
		printTree(t->pLeft);
		printTree(t->pRight);
	}

}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	Node* tree;
	InitTree(tree);
	std::vector<int> box;
	while (true) {
		int option;
		std::cin >> option;
		if (option == 0) break;
		switch (option)
		{
		case 1:
		{
			int id;
			std::cin >> id;
			makeTree(tree, id);
		}
		break;
		case 2:
		{
			int id;
			std::cin >> id;
			if (_find(tree, id)) box.emplace_back(1);
			else box.emplace_back(0);
		}
		break;
		case 3:
		{
			int id;
			std::cin >> id;
			deleteNode(tree, id);
		}
		break;

		}
	}
	for (int i = 0; i < box.size(); i++) {
		std::cout << box[i] <<"\n";
	}
	return 0;
}
