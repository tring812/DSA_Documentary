#include <iostream>

using namespace std;

void add(int *a, int x, int m){
  int mod = x % m;
  for(int i = 0; i < m;++i){
    int mod_tmp = (mod + i) % m;
    if(a[mod_tmp] == 0){
      a[mod_tmp]++;
      return;
    }
    a[mod_tmp]++;
  }
}

int main(){
  int n, m;
  cin >> n >> m;

  int *a = new int[m + 1]{0};
  int x, res = 0;
  for(int i = 0; i < n;++i){
    cin >> x;
    add(a, x, m);
  }

  for(int i = 0; i < m;++i){
    if(a[i] >= 2){
      res = max(res, a[i] - 1);
    }
  }
  
  for(int i = 0; i < m;++i){
    if(a[i] - 1 == res) cout << i << " ";
  }

}