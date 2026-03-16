#include <iostream>

using namespace std;

struct node{
  char value;
  node *next;
};

struct stack{
  node *top;
};

void init(stack &s){
  s.top = nullptr;
}

node *get_node(char x){
  node *p = new node;
  p->value = x;
  p->next = nullptr;
  return p;
}

void push(stack &s, char x){
  node *p = get_node(x);
  p->next = s.top;
  s.top = p;
}

void pop(stack &s){
  node *p = s.top;
  s.top = s.top->next;
  delete p;
}

bool isEmpty(stack s){
  if(s.top == nullptr)  return 1;
  return 0;
}

int output(stack s, string x){
  for(auto i : x){
    if(i == '(')
      push(s, i);
    else{
      if(isEmpty(s))
        return 0;
      else
        pop(s);
    }
  }
  if(isEmpty(s)) return 1;
  return 0;
}

int main(){
  stack s;
  init(s);
  string x;
  cin >> x;
  cout << output(s, x);
}