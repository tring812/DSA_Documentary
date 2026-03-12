#include <iostream>
using namespace std;

struct node{
  int value;
  node *left, *right;
};

/*struct tree{
  node *root;
};*/
  
typedef node* Tree;

node *get_node(int x){
  node *p = new node;
  if(!p){
    cout << "Memory full";
    return p;
  }
  p->value = x;
  p->left = p->right = nullptr;
  return p;
}

void add_node(Tree &t, int x){
  if(t == nullptr){
    t = get_node(x);
    return;
  }

  if(x == t->value){
    cout << "Value exist";
    return;
  }

  if(x < t->value)
    add_node(t->left, x);
  else
    add_node(t->right, x);
}

void inputTree(Tree &t){
  int n;
  cin >> n;
  for(int i = 0;i < n;++i){
    int x;
    cin >> x;
    add_node(t, x);
  }
}

void NLR(Tree t){
  if(t == nullptr)  return;
  cout << t->value << " ";
  NLR(t->left);
  NLR(t->right);
}

void LRN(Tree t){
  if(t == nullptr)  return;
  LRN(t->left);
  LRN(t->right);
  cout << t->value << " ";
}

void LNR(Tree t){
  if(t == nullptr)  return;
  LNR(t->left);
  cout << t->value << " ";
  LNR(t->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	return 0;
}
