#include <iostream>

using namespace std;

int hash_func(int *a, int m,int x){
  int mod = x % m, res = 0;
  for(int i = 0;i < m;++i){
    int mod_tmp = (mod + i) % m;
    if(a[mod_tmp] != 0){
      res++;
    }
    else{
      a[mod_tmp] = x;
      return res;
    }
  }
}

int main(){
  int m, n;
  cin >> m >> n;
  
  int *a = new int [m + 1]{0};
  int x, res = 0;
  for(int i = 0;i < n;++i){
    cin >> x;
    res += hash_func(a, m, x);
  }

  cout << res;
}