#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
  int n;
  cin >> n;
  string require;
  int num;

  queue <int> st;
  while(n--){
    cin.ignore();
    cin >> require;
    if(require == "push"){
      cin >> num;
      st.push(num);
    }
    else if(require == "empty"){
      (st.empty()) ? cout << "true\n" : cout << "false\n";
    }
    else if(require == "peek"){
      cout << st.front() << '\n';
    }
    else{
      cout << st.front() << '\n';
      st.pop();
    }
  }
}