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
  if(s.top == nullptr)  return;
  node *p = s.top;
  s.top = s.top->next;
  delete p;
}

bool isEmpty(stack s){
  return (s.top == nullptr)? 1: 0;
}

int main(){
  stack s;
  init(s);
  string a;
  getline(cin, a);
  for(auto x: a){
    if(x == '{' || x == '[' || x == '(')
      push(s, x);

    else if(x=='}' || x==']' || x==')'){  
      if(isEmpty(s)){
        cout << 0;
        return 0;
      }  
      char ss = s.top->value;
      if((ss == '{' && x == '}') || (ss == '(' && x == ')') || (ss == '[' && x == ']'))
        pop(s);
      else{
        cout << 0;
        return 0;
      }
    }
  }
  cout << isEmpty(s);
}