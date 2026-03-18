#include <iostream>
#include <cmath>

using namespace std;

struct point{
  double x, y, z;
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

double dist(point a){
  return sqrt(pow(a.x, 2) + pow(a.y,2) + pow(a.z, 2));
}

void output(List l, double b, double e){
  if(l.head == nullptr){
    cout << "KHONG";
    return;
  }
  node *p = l.head;
  bool c = 1;
  while(p != nullptr){
    if(dist(p->value) >= b && dist(p->value) <= e){
      cout << p->value.x << " " << p->value.y << " " << p->value.z << '\n';
      c = 0;
    }
    p = p->next;
  }
  if(c) cout << "KHONG";
}

int main(){
  List l;
  init(l);
  int n;
  cin >> n;
  while(n--){
    point a;
    cin >> a.x >> a.y >> a.z;
    add_tail(l, a);
  }
  double b, e;
  cin >> b >> e;
  output(l, b, e);
}