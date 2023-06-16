#include<iostream>
#include<string>
using namespace std;
struct Tree {
	string word;
	string mean;
	Tree* pLeft;
	Tree* pRight;
 };

void InitTree(Tree*& t) {
	t = NULL;
}

void makeTree(Tree*& t, string& w,string& m) {
	if (t == NULL) {
		Tree* p = new Tree();
		p->word = w;
		p->mean = m;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else {
		if (t->mean > m) {
			 makeTree(t->pLeft, w, m);
		}
		else if (t->mean < m) {
			makeTree(t->pRight, w, m);
		}
	}
}

Tree* dictionary(Tree*& t,const string& x) {
	if (t == NULL) {
		return NULL;
	}
	else {
		if (t->mean > x) {
			return dictionary(t->pLeft, x);
		}
		else if (t->mean < x) {
			return dictionary(t->pRight, x);
		}
		else {
			return t;
		}
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	Tree* tr;
	InitTree(tr);
	for (int i = 0; i < n; i++) {
		string w;
		string m;
		cin >> w >> m;
		makeTree(tr, w, m);
	}
	string word[m];
	for (int i = 0; i < m; i++) {
		string x;
		cin >> x;
		Tree* temp;
		temp = dictionary(tr, x);
		if (temp != NULL) {
			word[i] = temp->word;
		}
		else {
			word[i] = "eh";
		}
		
	}

	for (int i = 0; i < m; i++) {
		cout << word[i] << " ";
	}
	/*printTree(tr);*/
	return 0;
}
