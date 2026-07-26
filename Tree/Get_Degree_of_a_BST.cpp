#include <iostream>
using namespace std;

struct node
{
  int val;
  node *left, *right;
};

typedef node *tree;

node *get_node(int x){
  node *p = new node;
  p->val = x;
  p->left = p->right = nullptr;
  return p;
}

void add(tree &t, int x){
  if(!t){
    t = get_node(x);
    return;
  }
  if(t->val == x) return;
  if(t->val > x)  add(t->left, x);
  else add(t->right, x);
}

void input(tree &t){
  int n;
  cin >> n;
  int x;
  for(int i = 0;i < n;++i){
    cin >> x;
    add(t, x);
  }
}

int degree(const tree &t, int x){
  if(!t)  return -1;
  if(t->val == x){

    int res = 0;
    if(t->left) res++;
    if(t->right)  res++;
    return res;
  }
  if(t->val < x)  return degree(t->right, x);
   else return degree(t->left, x);
}

int main(){
  tree t;
  t = nullptr;
  input(t);
  int x;
  cin >> x;
  cout << degree(t, x);
}