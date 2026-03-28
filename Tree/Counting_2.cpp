#include <iostream>
using namespace std;


struct node{
  int value;
  node *left, *right;
};

typedef node* Tree;

node *get_node(int x){
  node *p = new node;
  p->value = x;
  p->left = p->right = nullptr;
  return p;
}

void insert(Tree &t, int x){
  if(t == nullptr){
    t = get_node(x);
    return;
  }
  if(x > t->value)  insert(t->right, x);
  else  insert(t->left, x);
}

void inputTree(Tree &t){
  int n, x;
  cin >> n;
  while(n--){
    cin >> x;
    insert(t, x);
  }
}

int countNodes(Tree t){
  if(t == nullptr)  return 0;
  return countNodes(t->left) + countNodes(t->right) + 1;
}

int countLeafs(Tree t){
  if(!t) return 0;
  if(!t->left && !t->right) return 1;
  return countLeafs(t->left) + countLeafs(t->right);
}

int countInternalNodes(Tree t){
  return max(0, countNodes(t) - countLeafs(t) -  1);
}

int countOneChild(Tree t){
  if(!t) return 0;
  if((t->left && !t->right) || (!t->left && t->right))
    return 1 + countOneChild(t->left) + countOneChild(t->right);
  return countOneChild(t->left) + countOneChild(t->right);
}

int countTwoChildren(Tree t){
  if(!t) return 0;
  if(t->left && t->right)
    return 1 + countTwoChildren(t->left) + countTwoChildren(t->right);
  return countTwoChildren(t->left) + countTwoChildren(t->right);
}

int countLess(Tree t, int x){
  if(!t) return 0;
  if(t->value < x)
    return 1 + countLess(t->left, x) + countLess(t->right, x);
  return countLess(t->left, x);
}

int countBetweenValues(Tree t, int x, int y){
  if(!t)  return 0;
  if(t->value > x && t->value < y)  return 1 + countBetweenValues(t->left, x, y) + countBetweenValues(t->right, x, y);
  return countBetweenValues(t->left, x, y) + countBetweenValues(t->right, x, y);
}

int main()
{
	Tree T = NULL;
	inputTree(T);

    cout<<"Number of nodes: " << countNodes(T)<<endl;
	cout<<"Number of leaf nodes: " << countLeafs(T)<<endl;
	cout<<"Number of internal nodes: "<< countInternalNodes(T)<<endl;
	cout<<"Number of nodes with one child: "<< countOneChild(T)<<endl;
	cout<<"Number of nodes with two children: "<< countTwoChildren(T)<<endl;

	int x;cout<<"Enter x: ";cin>>x;
	cout<<"\nNumber of nodes less than "<<x<<": "<< countLess(T,x)<<endl;
	int y; cout<<"Enter x,y: ";cin>>x>>y;
	cout<<"\nNumber of nodes greater than "<<x<<" and less than "<<y<<": "<< countBetweenValues(T,x,y)<<endl;

	return 0;
}
