#include <bits/stdc++.h>
using namespace std;

const int maxd = 1e5;
int v, n;
vector <pair<int, int>> List(v);
vector <int> parent(v);
map <string, int> toId;

void dijkstra(string s){
  vector <int> d(v, maxd);
  d[toId[s]] = 0;
  priority_queue <pair<int, string>, vector<pair<int,string>>, greater<pair<int, string>>> q;
  q.push({0, s});
  while(!q.empty()){
    pair<int, string> top = q.top(); q.pop();
    int kc = top.first;
    string u = top.second;
    if(kc > d[toId[u]]) continue;

    for(auto it : List[u]){
      int v = toId[it.first];
      int w = it.second;
      if(d[v] > d[u] + w){
        d[v] = d[u] + w;
        q.push({d[v], v});
        parent[
      }
    }
  }
}

int main(){
  
}