
#include <iostream>
using namespace std;

struct node{
  int info;
  node *left, *right;
};

typedef node* Tree;

node *get_node(int x){
  node *p = new node;
  p->info = x;
  p->left = p->right = nullptr;
  return p;
}

void add_node(Tree &t, int x){
  node *p = get_node(x);
  if(!t){
    t = p;
    return;
  }
  if(x > t->info) add_node(t->right, x);
  else  add_node(t->left, x);
}

void inputTree(Tree &t){
  int n, x;
  cin >> n;
  while(n--){
    cin >> x;
    add_node(t, x);
  }
}

void NLR(Tree t){
  if(!t) return;
  cout << t->info << " ";
  NLR(t->left);
  NLR(t->right);
} 

int depth(Tree t){
  if(!t)  return -1;
  return 1 + max(depth(t->left), depth(t->right));
}

int isBalancedTree(Tree t){
  if(!t)  return 1;
  if(isBalancedTree(t->left) == 0)  return 0;
  if(isBalancedTree(t->right) == 0) return 0;
  if(depth(t->left) != depth(t->right))  return 0;
  return 1;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	int i = isBalancedTree(T); //Kiem tra cay hoan toan can bang
	if(i==1)
        cout<<"\nTree is balanced";
    else
        cout<<"\nTree is not balanced";
	return 0;
}