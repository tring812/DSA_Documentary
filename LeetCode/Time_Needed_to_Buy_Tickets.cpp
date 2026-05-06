#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int n, k;
  cin >> n >> k;
  long long *a = new long long [100007];

  for(int i = 0;i < n;++i)
    cin >> a[i];  
  
  long long res = 0;
  for(int i = k + 1;i < n;++i){
    res += min(a[i], a[k] - 1);
  }
  for(int i = 0;i < k;++i){
    res += min(a[i], a[k]);
  }
  cout << res + a[k];
}