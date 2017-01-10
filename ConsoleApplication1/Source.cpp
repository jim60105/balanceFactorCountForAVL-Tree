#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
	int v;
	Node* left;
	Node* right;
	int leftHeight;
	int rightHeight;
};

void insertNode(Node* pt, Node* rt, int v) {

	if (rt == 0) {//´¡¤JÂI
		Node* in = new Node;
		in->v = v;
		in->left = in->right = 0;
		in->leftHeight = in->rightHeight = 0;
		if (pt->v <v)
			pt->right = in;
		else
			pt->left = in;
	}
	else if (rt->v<v)
		insertNode(rt, rt->right, v);
	else if (rt->v>v)
		insertNode(rt, rt->left, v);

}

void inorder(Node* p) {
	if (p == 0)
		return;
	else {
		inorder(p->left);
		cout << p->v << '[' << p->rightHeight-p->leftHeight<<']' << ", ";
		inorder(p->right);
	}
}

int countBF(Node* pt) {
	if (pt->left != 0) {
		pt->leftHeight = countBF(pt->left);
	}
	if (pt->right != 0) {
		pt->rightHeight = countBF(pt->right);
	}
	if (pt->leftHeight>pt->rightHeight)	{
		return pt->leftHeight + 1;
	}
	else {
		return pt->rightHeight + 1;
	}
}

int main() {
	int a[] = { 5,3,7,1,9,6,2,4 };

	Node* root = new Node;
	root->v = a[0];
	root->left = root->right = 0;
	for (int i = 0; i < 8; i++)
	{
		insertNode(0, root, a[i]);
	}
	countBF(root);
	inorder(root);
	system("pause");
}