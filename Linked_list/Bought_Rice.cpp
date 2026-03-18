#include <iostream>
using namespace std;

struct customer{
  int id;
  string food;
};

struct node{
  customer value;
  node *next;
};

struct List{
  node *head, *tail;
};

void Init(List &l){
  l.head = l.tail = nullptr;
}

node *get_node(string x){
  node *p = new node;
  p->value.food = x;
  p->next = nullptr;
  return p;
}

void add_tail(List &l,int idx, string x){
  node *p = get_node(x);
  if(l.head == nullptr){
    l.head = p;
    l.tail = p;
  }
  else{
    l.tail->next = p;
    l.tail = p;
  }
  p->value.id = idx;
}

void remove_head(List &l){
  if(l.head == nullptr) return;
  node *p = l.head;
  l.head = l.head->next;
  p->next = nullptr;
  if(l.head == nullptr)   l.tail = nullptr;
  delete p;
}

void output(List l){
  node *p = l.head;
  while(p != nullptr){
    cout << p->value.id << " " << p->value.food << '\n';
    p = p->next;
  }
}

int main(){
  List l;
  Init(l);
  int x, idx = 1;
  string y;
  cin >> x;
  while(x != -1){
    if(x == 0){
      cin >> y;
      add_tail(l, idx, y);
      idx++;
    }
    else{
      remove_head(l);
    }
    cin >> x;
  }
  if(l.head == nullptr) cout << "Tiem qua e, khong co khach nao";
  else{
    output(l);
  }
}