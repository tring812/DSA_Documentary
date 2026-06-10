

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector<long long> majorityNK(const vector<long long> &arr, int k)
{
  vector<long long> v;
  int comp = arr.size() / k;
  unordered_map<int, int> mp{0};
  for(auto i : arr){
    mp[i]++;
  }
  
  for(auto i : mp){
    if(i.second > comp){
      v.push_back(i.first);
    }
  }
  sort(v.begin(), v.end());
  return v;
}

int main()
{
  int n, k;
  cin >> n >> k;
  
  vector<long long> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<long long> ans = majorityNK(arr, k);
  if (ans.empty())
  {
    cout << -1 << "\n";
  }
  else
  {
    for (size_t i = 0; i < ans.size(); i++)
    {
      if (i)
        cout << " ";
      cout << ans[i];
    }
    cout << "\n";
  }
  return 0;
}
