#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
  long long a, b;
  unordered_set <long long> s;
  cin >> a;
  while(a != 0){
    cin >> b;
    switch(a){
      case 1:
        s.insert(b);
        break;
      case 3:
        s.erase(b);
        break;
      case 2:
        if(s.count(b))  cout << 1 << '\n';
        else  cout << 0 << '\n';
        break;
    }
    cin >> a;
  }
}