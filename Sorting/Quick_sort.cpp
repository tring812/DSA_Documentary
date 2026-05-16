#include <iostream>
using namespace std;

void sorting(int* a, int l, int r, int& res){
  if(l >= r)  return;
  int mid = a[(l + r) / 2];
  int i = l, j = r;
  while(i <= j){
    while(a[i] > mid) i++;
    while(a[j] < mid) j--;
    if(i <= j){
      swap(a[i], a[j]);
      res++;
      i++;
      j--;
    }
  }
  if(l < j) sorting(a, l, j, res);
  if(i < r) sorting(a, i, r, res);
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int n;
  cin >> n;
  int *a = new int[n + 1];
  for(int i = 0;i < n;++i){
    cin >> a[i];
  }
  int res = 0;

  sorting(a, 0, n - 1, res);
  cout << "Sorted Array: ";
  for(int i = 0;i < n;++i){
    cout << a[i] << " ";
  }
  cout << "\nNumber of times to swap 2 numbers: " << res;
}