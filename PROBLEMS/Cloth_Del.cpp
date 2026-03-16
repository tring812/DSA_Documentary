#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct cloth{
  string type;
  int size;
};

struct node{
  cloth value;
  node *next;
};

struct stack{
  node *top;
};

void init(stack &s){
  s.top = nullptr;
}

node *get_node(cloth t){
  node *p = new node;
  p->value = t;
  p->next = nullptr;
  return p;
}

void push(stack &s, cloth t){
  node *p = get_node(t);
  p->next = s.top;
  s.top = p;
}

void pop(stack &s){
  if(s.top == nullptr)  return;
  node *p = s.top;
  s.top = s.top->next;
  delete p;
}

int main(){
  stack s;
  init(s);
  cloth t;
  while(1){
    cin >> t.type;
    if(t.type == "-1")  break;
    cin >> t.size;
    push(s, t);
  }
  int n;
  cin >> n;
  while(n--)
    pop(s);
  cout << s.top->value.type << " " << s.top->value.size;
}