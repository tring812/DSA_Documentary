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

void add_tail(List &l, int x){
  node *p = get_node(x);
  if(l.head == nullptr)
    l.head = l.tail = p;
  else{
    l.tail->next = p;
    l.tail = p;
  }
}

int get_info(List l, int id){
  if(l.head == nullptr) return 0;
  int i = 0;
  node *p = l.head;
  while(p != nullptr){
    if(i == id){
      return p->value;
    }
    i++;
    p = p->next;
  }
}

int main(){
  List l;
  init(l);
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    add_tail(l, x);
  }
  int m;
  long long sum = 0;
  cin >> m;
  while(m--){
    int x;
    cin >> x;
    sum += get_info(l, x);
  }
  cout << sum;
}