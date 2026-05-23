#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int *a = new int [n + 1];
  for(int i = 0;i < n;++i){
    cin >> a[i];
  }

  int x, count = 1, id, l = 0, r = n - 1;
  cin >> x;
  while(l <= r){
    id = (l + r) / 2;
    if(a[id] == x)  break;
    if(a[id] > x) r = id - 1;
    else  l = id + 1;
    count++;  
  }

  if(a[id] == x){
    cout << id << '\n' << count;
  }
  else  cout << -1;
}