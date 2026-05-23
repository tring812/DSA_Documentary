#include <iostream>

using namespace std;

int main(){
  int n, m, x;
  cin >> n >> m;

  int *a = new int[m]{0};
  for(int i = 0;i < n;++i){
    cin >> x;
    a[x % m]++;
  }
  
  int mi = n + 1;
  for(int i = 0;i < m;++i){
    if(a[i] >= 2){
      mi = min(mi, a[i]);
    }
  }
  for(int i = 0;i < m;++i){
    if(a[i] == mi){
      cout << i << " ";
    }
  }
}