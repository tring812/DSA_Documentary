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

bool check_ins(Tree &t, int x){
  if(t == NULL){
    t = get_node(x);
    return 1;
  }
  
  node *p = get_node(x);
  if(t->value == x) return 0;

  if(x > t->value)  return check_ins(t->right, x);
  else  return check_ins(t->left, x);
}

void inputTree(Tree &t){
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    if(check_ins(t, x) == 0){
      cout << "Bi trung gia tri, ket thuc qua trinh tao cay\n";
      return;
    }
  }
}

void NLR(Tree t){
  if(t == NULL)  return;
  cout << t->value << " ";
  NLR(t->left);
  NLR(t->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T); //Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
	cout<<"NLR: "; NLR(T);
	return 0;
}



