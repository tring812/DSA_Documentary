#include <iostream>
#include <stack>

using namespace std;

int main(){
  stack <char> s;
  string ss;
  cin >> ss;
  for(int i = 0;i < ss.size();i++){
    if(s.empty()){
      s.push(ss[i]);
    }
    else{
      if(s.top() == ss[i])  s.pop();
      else  s.push(ss[i]);
    }
  }
  if(s.empty()) cout << " ";
  else{
    stack <char> tmp;
    while(!s.empty()){
      tmp.push(s.top());
      s.pop();
    }

    while(!tmp.empty()){
      cout << tmp.top();
      tmp.pop();
    }
  }
}