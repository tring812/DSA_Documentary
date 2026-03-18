#include <iostream>
#include <cmath>

using namespace std;

struct point{
  double X, Y, Z;
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

node *get_node(double x, double y, double z){
  node *p = new node;
  p->value.X = x, p->value.Y = y, p->value.Z = z;
  p->next = nullptr;
  return p; 
}

void add_tail(List &l, double x, double y, double z){
  node *p = get_node(x, y, z);
  if(l.head == nullptr){
    l.head = l.tail = p;
  }
  else{
    l.tail->next = p;
    l.tail = p;
  }
}

void search(List l, double x, double y, double z){
  node *p = l.head;
  int id = 0;
  while(p != nullptr){
    if(p->value.X == x && p->value.Y == y && p->value.Z == z){
      cout << id << '\n';
      return;
    }
    id++;
    p = p->next;
  }
  cout << "KHONG\n";
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  List l; init(l);
  int n;
  cin >> n;
  while(n--){
    double x, y, z;
    cin >> x >> y >> z;
    add_tail(l, x, y, z);
  }
  int m;
  cin >> m;
  while(m--){
    double x, y, z;
    cin >> x >> y >> z;
    search(l, x, y, z);
  }
}