#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct stack{
  char arr[MAX];
  int t;
};

void init(stack &s){
  s.t = NULLDATA;
}

int isEmpty(stack s){
  return (s.t == -1);
}

int isFull(stack s){
  return (s.t == MAX - 1);
}

void Push(stack &s, char x){
  if(isFull(s))  return;
  s.arr[++s.t] = x;
}

void Pop(stack &s){
  if(isEmpty(s)) return;
  s.arr[s.t] = NULLDATA;
  s.t--;
}

char Top(stack &s){
  if(isEmpty(s))  return -1;
  return s.arr[s.t];
}

bool isValid(string x){
  stack s;
  init(s);
  for(auto i : x){
    if(i == '(' || i == '[' || i == '{')
      Push(s, i);
    else{
      if(isEmpty(s))
        return 0;
      char top = Top(s);
      if( (i == ')' && top != '(') ||
          (i == ']' && top != '[') ||
          (i == '}' && top != '{') )
        return 0;
      Pop(s);
    }
  }
  return (isEmpty(s));
}

int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}
