#include <iostream>
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

void add_head(List &l, int x){
  node *p = get_node(x);
  if(l.head == nullptr){
    l.head = p;
    l.tail = p;
  }
  else{
    p->next = l.head;
    l.head = p;
  }
}

/*node* search(List L, int x){
  node *p = L.head;
  if(L.head == nullptr) return nullptr;
  else{
    while(p != nullptr){
      if(p->value == x) return p;
      p = p->next;
    }
    return nullptr;
  }
}

void insert(List &L, int x, node *k){
  node *p = get_node(x);
  if(k->next = nullptr){
    p->next = nullptr;
    L.tail = p;
    k->next = p; 
  }
  else{
    p->next = k->next;
    k->next = p;
  }
}

void remove(List &L){
  if(L.head == nullptr) return;
  else{
    node *p = L.head;
    L.head = L.head->next;
    p->next = nullptr;
    delete p;
    if(L.head == nullptr) L.tail = nullptr;
  }
}*/

void output(List l){
  node *p = l.head;
  while(p != nullptr){
    cout << p->value << " ";
    p = p->next;
  }
}

int main(){
  List L;
  Init(L);
  int x, y;
  cin >> x;
  while(x != 3){
    cin >> y;
    add_head(L, y);
    cin >> x;
  }
  output(L);
}