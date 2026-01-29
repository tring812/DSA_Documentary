#include <bits/stdc++.h>
using namespace std;

struct node{
  int value;
  node *next;
};

struct List{
  node *head, *tail;
};

void Init(List &l){
  l.head = nullptr, l.tail = nullptr;
}

node *get_node(int x){
  node *p = new node;
  p->next = nullptr;
  p->value = x;
  return p;
}

void add_tail(List &l, int x){
  node *p = get_node(x);
  if(l.head == nullptr){
    //If empty, head and tail will point current node
    l.head = p;
    l.tail = p;
  }
  else{
    //Else, the current TAIL node will point to current node
    l.tail->next = p;
    l.tail = p;
  }
}

int main(){
  //create linked list
  List l;
  Init(l);
  int n; cin >> n;
  for(int i = 0;i < n;++i){
    int x; cin >> x;
    add_tail(l, x);
  }
  return 0;
}