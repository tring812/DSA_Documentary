#include <iostream>
using namespace std;

struct node{
  int value;
  node *next;
};

struct List{
  node *head, *tail;
};

void init(List &l){
  l.head = l.tail = nullptr;
}

node *get_node(int x){
  node *p = new node;
  if(!p)  return p;
  p->value = x;
  p->next = nullptr;
  return p;
}

void add_head(List &l, int x){
  node *p = get_node(x);
  if(l.head == nullptr){
    l.head = l.tail = p;
    return;
  }
  p->next = l.head;
  l.head = p;
}

void add_tail(List &l, int x){
  node *p = get_node(x);
  if(l.head == nullptr){
    l.head = l.tail = p;
    return;
  }
  l.tail->next = p;
  l.tail = p;
}

void del_head(List &l){
  if(l.head == nullptr) return;
  node *p = l.head;
  l.head = l.head->next;
  p->next = nullptr;
  delete p;
  if(l.head == nullptr)
    l.head = l.tail = nullptr;
}

void del_tail(List &l){
  if(l.head == nullptr) return;
  if(l.head == l.tail){
    delete l.head;
    l.head = l.tail = nullptr;
    return;
  }

  node *p = l.head;
  while(p->next != l.tail){
    p = p->next;
  }
  delete l.tail;
  l.tail = p;
  l.tail->next = nullptr;
}

void output(List l){
  if(l.head == nullptr) return;
  node *p = l.head;
  while(p != nullptr){
    cout << p->value << " ";
    p = p->next;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  List l;
  init(l);
  int n;
  cin >> n;
  while(n--){
    char sign, ht;
    int z;
    cin >> sign >> ht >> z;
    if(sign == '+')
      (ht == 'H')? add_head(l, z): add_tail(l, z);
    else
      (ht == 'H')? del_head(l): del_tail(l);
  }
  output(l);
}