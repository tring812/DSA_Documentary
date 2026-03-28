
#include <iostream>
using namespace std;

struct Node{
  int value;
  Node *left, *right;
};

typedef Node* Tree;

Node *get_node(int x){
  Node *p = new Node;
  p->value = x;
  p->left = p->right = nullptr;
  return p;
}

void insert(Tree &t, int x){
  if(t == nullptr){
    t = get_node(x);
    return;
  }

  if(x > t->value)
    insert(t->right, x);
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

void LNR(Tree t){
  if(t == nullptr)  return;
  LNR(t->left);
  cout << t->value << " ";
  LNR(t->right);

}

Node *Search(Tree t, int x){
  if(t == nullptr)  return nullptr;
  if(t->value == x) return t;
  if(t->value < x)  return Search(t->right, x);
  else  return Search(t->left, x);
}

int minValue(Tree t){
  if(t->left == nullptr)  return t->value;
  return minValue(t->left);
}

int maxValue(Tree t){
  if(t->right == nullptr)  return t->value;
  return maxValue(t->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}
