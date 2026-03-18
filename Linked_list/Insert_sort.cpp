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
  p->value = x;
  p->next = nullptr;
  return p;
}

void output(List l){
  if(l.head == nullptr) return;
  node *p = l.head;
  while(p != nullptr){
    cout << p->value << " ";
    p = p->next;
  }
  cout << '\n';
}

void sort_list(List &l, int x){
  node *p1 = get_node(x);
  if(l.head == nullptr){
    l.head = l.tail = p1;
    output(l);
    return;
  }

  if(l.head->value > x){
    p1->next = l.head;
    l.head = p1;
    output(l);
    return;
  }

  node *p = l.head;
  while(p != l.tail){
    if(p->next->value > x)
      break;
    p = p->next;
  }
  if(p != l.tail){
    p1->next = p->next;
    p->next = p1;
    output(l);
  }
  else{
    l.tail->next = p1;
    l.tail = p1;
    output(l);
  }
}

int main(){
  List l;
  init(l);
  int n;
  cin >> n;
  for(int i = 1;i <= n;++i){
    int x;
    cin >> x;
    sort_list(l, x);
  }
}