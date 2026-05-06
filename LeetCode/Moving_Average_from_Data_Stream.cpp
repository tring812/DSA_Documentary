#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int k, n;
  cin >> k >> n;

  queue <int> q;
  
  cout << fixed << setprecision(5);
  double res = 0;
  int x;

  while(n--){
    cin >> x;
    res += x * 1.0;
    if(q.size() < k){
      q.push(x);
    }  
    else{
      res -= q.front() * 1.0;
      q.pop();
      q.push(x);
    }
    cout << res / q.size() << '\n';
  }
}