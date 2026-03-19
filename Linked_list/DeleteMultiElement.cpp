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

void  find_x(List &l, int a, int b){
  node *p = l.head;
  while(p){
    if(p->value == a){
      node *p1 = get_node(b);
      p1->next = p->next;
      p->next = p1;

      if(p == l.tail) l.tail = p1;
      return;
    }
    p = p->next;
  }
  add_head(l, b);
}

void del(List &l, node *q){
  if(l.head == nullptr) return;
  if(q == nullptr){
    del_head(l);
    return;
  }
  node *p = q->next;
  q->next = p->next;
  p->next = nullptr;
  
  if(l.tail == p) l.tail = q;
  delete p;
}

void del_once(List &l,int n){
  if(l.head == nullptr) return;
    node *p = l.head, *q = nullptr;
    while(p){
      if(p->value == n){
        del(l, q);
        return;
      }
      else{
        q = p;
        p = p->next;
      }
    }
    if(l.head == nullptr)  
      l.head = l.tail = nullptr;
}

void del_mul(List &l, int n){
  if(l.head == nullptr) return;
  node *p = l.head, *q = nullptr;
  while(p){
    if(p->value == n){
      p = p->next;
      del(l, q);
    }
    else{
      q = p;
      p = p->next;
    }
  }
}

void output(List l){
  if(l.head == nullptr) return;
  node *p = l.head;
  while(p){
    cout << p->value << " ";
    p = p->next;
  }
}

void process(List &l){
  int x;
  cin >> x;
  while(x != 6){
    int y, z;
    switch (x){
      case 0:
        cin >> y;
        add_head(l, y);
        break;
      case 1:
        cin >> y;
        add_tail(l, y);
        break;
      case 2:
        cin >> y >> z;
        find_x(l, y, z);
        break;
      case 3:
        cin >> y;
        del_once(l, y);
        break;
      case 4:
        cin >> y;
        del_mul(l, y);
        break;
      case 5:
        del_head(l);
        break;  
    }
    cin >> x;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  List l; init(l);
  process(l);
  output(l);
}