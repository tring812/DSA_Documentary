#include <iostream>
using namespace std;

struct point{
  int x, y;
};

struct node{
  point value;
  node *next;
};

struct List{
  node *head, *tail;
};

void init(List &l){
  l.head = l.tail = nullptr;
}

node *get_node(point x){
  node *p = new node;
  p->value = x;
  p->next = nullptr;
  return p;
}

void add_tail(List &l, point x){
  node *p = get_node(x);
  if(l.head == nullptr)
    l.head = l.tail = p;
  else{
    l.tail->next = p;
    l.tail = p;
  }
}

long long calc(point a){
  return a.x*a.x + a.y*a.y;
}

void del(List &l, node *p){
  if(l.head == nullptr) return;

  if(p == l.head){
    l.head = l.head->next;
    if(l.head == nullptr)
        l.tail = nullptr;
    delete p;
    return;
  }
  node *prev = l.head;
  while(prev != nullptr && prev->next != p)
      prev = prev->next;
  prev->next = p->next;
  if(p == l.tail)
      l.tail = prev;

  delete p;
}

node *find_p(List l){
  if(l.head == nullptr) return nullptr;
  node *p = l.head;
  node *mi = p;
  while(p != nullptr){
    long long d1 = calc(p->value), d2 = calc(mi->value);
    if(d1 < d2)
      mi = p;
    else if(d1 == d2 ){
      long long d1x = p->value.x * p->value.x;
      long long d2x = mi->value.x * mi->value.x;
      if(d1x < d2x)
        mi = p;
      else if(d1x == d2x){
        if(p->value.y * p->value.y < mi->value.y * mi->value.y)
          mi = p;
      }
    }
    p = p->next;
  }
  return mi;
}

void output(List &l){
  if(l.head == nullptr) return;
  while(l.head != nullptr){
    node *p = find_p(l);
    cout << p->value.x << " " << p->value.y << '\n';
    del(l,p);
  }
}

int main(){
  List l;init(l);
  int n;
  cin >> n;
  while(n--){
    point a;
    cin >> a.x >> a.y;
    add_tail(l, a);
  }
  output(l);
}