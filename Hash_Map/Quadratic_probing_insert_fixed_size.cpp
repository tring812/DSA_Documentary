#include <iostream>
#include <string>
#include <sstream>
#define int long long

using namespace std;

void add(pair<int, int> *hash_map, int key, int a, int b, int m){
  int mod = ((key % m) + m) % m;
  for(int i = 0; i < m;++i){
    int mod1 = (mod + a*i + b*i*i) % m;
    if(hash_map[mod1].second != 0 && hash_map[mod1].first == key){
      return;
    }
    if(hash_map[mod1].second == 0){
      hash_map[mod1].first = key;
      hash_map[mod1].second = 1;
      return;
    }
  }
}

void output(pair<int, int> *hash_map, int m){
  for(int i = 0;i < m;++i){
    if(i > 0) cout << ", ";
    if(hash_map[i].second != 0) cout << hash_map[i].first;
    else  cout << "None";
  }
  cout << '\n';
}

signed main(){

  int m, a, b;
  cin >> m;
  while(m != 0){
    cin >> a >> b;
    cin.ignore();
    pair<int, int> *hash_map = new pair<int,int> [m + 1] {{0,0}};
    string s;
    getline(cin, s);
    stringstream ss(s);

    int key;
    while(ss >> key){
      add(hash_map, key, a, b, m);
    }

    output(hash_map, m);
    cin >> m;
  }

}