#include <iostream>

using namespace std;

int main(){
  int n, m, x, count = 0;
  cin >> n >> m;
  int *a = new int[m + 1]{0};

  for(int i = 0;i < n;++i){
    cin >> x;
    if(a[x % m] >= 1) count++;
    a[x % m]++;
  }

  if(count > n * 0.33)  cout << "BAD";
  else  cout <<  "GOOD";
}