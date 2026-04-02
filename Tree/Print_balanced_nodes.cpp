
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *left, *right;
};
typedef struct Node* Tree;

Node *getNode(int x)
{
	Node *p = new Node;
	if (p)
	{
		p->info = x;
		p->left = p->right = NULL;
	}
	return p;
}

void add_node(Tree &t, int x){
	Node *p = getNode(x);
	if(!t){
		t = p;
		return;
	}
	if(x > t->info)	add_node(t->right, x);
	else	add_node(t->left, x);
}

void inputTree(Tree &t){
	int n, x;
	cin >> n;
	while(n--){
		cin >> x;
		add_node(t, x);
	}
}

int depth(Tree t){
	if(!t)	return -1;
	return 1 + max(depth(t->left), depth(t->right));
}

void balancedNodes(Tree t){
	if(!t)	return;
	if(depth(t->left) == depth(t->right))	cout << t->info << " ";
	balancedNodes(t->left);
	balancedNodes(t->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	balancedNodes(T);
	return 0;
}
