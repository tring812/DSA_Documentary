#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector <vector<int>> valid;

struct graph{
  vector <string> name;
  map <string, int> mp;
  int n;
};

void input(graph& a){
  int v;
  string x1;
  cin >> a.n >> v;
  valid.resize(a.n, vector<int>(a.n, 0));
  for(int i = 0;i < a.n;++i){
    cin >> x1;
    a.name.push_back(x1);
    a.mp[x1] = i;
  }

  string x, y;
  for(int i = 0;i < v;++i){
    cin >> x >> y;
    valid[a.mp[x]][a.mp[y]] = 1;
    valid[a.mp[y]][a.mp[x]] = 1;
  }
}

void calc(graph g){
  for(int i = 0;i < g.n;++i){
    int count = 0;
    for(int j = 0;j < g.n;++j){
      if(valid[g.mp[g.name[i]]][g.mp[g.name[j]]])
        count++;
    }
    cout << count << " ";
  }
}

int main(){
  graph G;
  input(G);
  calc(G);
}