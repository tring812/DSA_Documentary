#include <bits/stdc++.h>
using namespace std;

struct node{
  int value;
  node *next;
};

struct List{
  node *head, *tail;
};

void init(List &l){
  l.head = nullptr, l.tail = nullptr;
}

void add_tail(List &l, int x){
  node *p = get_node(x);
  if(l.head = nullptr){
    l.head = p;
    l.tail = p;
  }
  else{
    l.tail->next = p;
    l.tail = p; 
  }
}

node *get_node(int x){
  node *p = new node;
  p->next = nullptr;
  p->value = x;
  return p;
}

int main(){
  //create linked list
  List l;
  init(l);
  int n; cin >> n;
  for(int i = 0;i < n;++i){
    int x; cin >> x;
    add_tail(l, x);
  }
  return 0;
}