#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick_sort(vector<long long>& v, int l, int r){
  long long mid = v[(l + r) / 2];
  int i = l, j = r;
  while(i <= j){
    while(v[i] > mid) i++;
    while(v[j] < mid) j--;
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
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  long long x;
  vector <long long> v;
  while(cin >> x){
    v.push_back(x);
  }

  sort(v.begin(), v.end(), greater<long long>());

  int count = 1;
  for(int i = 1;i < v.size();++i){
    if(v[i] != v[i - 1]){
      cout << v[i - 1] << " " << count << '\n';
      count = 1;
    }
    else{
      count++;
    }
  }
}