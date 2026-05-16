#include <iostream>
using namespace std;

const int N = 10000 + 7;
int even[N], odd[N];

void quick_sort(int* v, int l, int r){
  if(l >= r)  return;
  int mid = v[(l + r) / 2];
  int i = l, j = r;
  while(i <= j){
    while(v[i] < mid) i++;
    while(v[j] > mid) j--;
    if(i <= j){
      swap(v[i], v[j]);
      i++;
      j--;
    }
  }
  if(l < j) quick_sort(v, l, j);
  if(i < r) quick_sort(v, i, r);
}

int main(){
  int n, x;
  cin >> n;
  int id_e = 0, id_o = 0;
  for(int i = 0; i < n; ++i){
    cin >> x;
    if(x % 2 == 0){
      even[id_e] = x;
      id_e++;
    }
    else{
      odd[id_o] = x;
      id_o++;
    }
  }
  quick_sort(even, 0, id_e - 1);
  quick_sort(odd, 0, id_o - 1);

  for(int i = 0;i < id_e;++i){
    cout << even[i] << '\n';
  }
  for(int i = 0;i < id_o;++i){
    cout << odd[i] << '\n';
  }
}