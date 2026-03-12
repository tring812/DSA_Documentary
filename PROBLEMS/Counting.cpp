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

void add_tree(Tree &t, int x){
  if(t == nullptr){
    t = get_node(x);
    return;
  }
  if(x == t->value){
    return;
  }

  if(x < t->value)
    add_tree(t->left, x);
  else
    add_tree(t->right, x);
}

void inputTree(Tree &t){
  int n;
  cin >> n;
  for(int i = 0;i < n;++i){
    int x;
    cin >> x;
    add_tree(t, x);
  }
}

void LNR(Tree t){
  if(t == nullptr)  return;
  LNR(t->left);
  cout << t->value << " ";
  LNR(t->right);
}

int countNodes(Tree t){
  if(t == nullptr)  return 0;
  return 1 + countNodes(t->left) + countNodes(t->right);
}

int depthOfTree(Tree t){
  if(t == nullptr)  return -1;
  return max(depthOfTree(t->left), depthOfTree(t->right)) + 1;
}

void countEven(Tree t, int &x){
  if(t == nullptr) return;
  if(t->value % 2 == 0)
    x++;
  countEven(t->left, x);
  countEven(t->right, x);
}

void countOdd(Tree t,int &x){
  if(t == nullptr) return;
  if(t->value % 2 != 0)
    x++;
  countOdd(t->left, x);
  countOdd(t->right, x);
}

int countPositive(Tree t){
  if(t == nullptr)  return 0;
  if(t->value > 0){
    return countPositive(t->left) + countPositive(t->right) + 1;
  }
  return countPositive(t->left) + countPositive(t->right);
}

int countNegative(Tree t){
  if(t == nullptr)  return 0;
  if(t->value < 0){
    return countNegative(t->left) + countNegative(t->right) + 1;
  }
  return countNegative(t->left) + countNegative(t->right);
}

bool is_prime(int x){
  if(x < 2) return false;
  for(int i = 2;i * i <= x;++i){
    if(x % i == 0)  return false;
  }
  return true;
}

int countPrime(Tree t){
  if(t == nullptr)  return 0;
  if(is_prime(t->value)){
    return countPrime(t->left) + countPrime(t->right) + 1;
  }
  return countPrime(t->left) + countPrime(t->right);
}

void listPrime(Tree t){
  if(t == nullptr)  return;
  if(is_prime(t->value))
    cout << t->value << " ";
  listPrime(t->left);
  listPrime(t->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;
    
    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);
    


	return 0;
}
