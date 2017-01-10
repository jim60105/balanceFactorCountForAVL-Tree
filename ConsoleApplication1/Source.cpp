#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
	int v;
	Node* left;
	Node* right;
};

void insertNode(Node* pt, Node* rt, int v) {

	if (rt == 0) {//´¡¤JÂI
		Node* in = new Node;
		in->v = v;
		in->left = in->right = 0;
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
		cout << p->v << ", ";
		inorder(p->right);
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
	inorder(root);
	system("pause");
}