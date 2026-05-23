#include <iostream>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  int *a = new int [m + 1]{0};
  int x, ma = 0;
  for(int i = 0;i < n;++i){
    cin >> x;
    a[x % m]++;
  }

  for(int i = 0;i < m;++i){
    ma = max(a[i], ma);
  }
  for(int i = 0;i < m;++i){
    if(a[i] == ma)  cout << i << '\n';
  }
}