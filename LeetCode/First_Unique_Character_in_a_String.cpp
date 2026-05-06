#include <iostream>
#include <map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  map <char, int> mp;
  string s;
  cin >> s;
  for(int i = 0;i < s.size();++i){
    mp[s[i]]++;
  }

  for(int i = 0;i < s.size();++i){
    if(mp[s[i]] == 1){
      cout << i;
      return 0;
    }
  }
  cout << -1;
}