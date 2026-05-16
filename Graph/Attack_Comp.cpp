#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int i, vector<int>& visited,const vector<vector<int>>& l){
  queue<int> q;
  visited[i] = 1;
  q.push(i);
  while(!q.empty()){
    int top = q.front(); q.pop();
    for(auto id : l[top]){
      if(visited[id] == 0){
        q.push(id);
        visited[id] = 1;
      }
    }
  }
}

int main(){
  int m, n;
  cin >> m >> n;

  vector<vector<int>> List(m + 1);
  vector<int> visited(m + 1, 0);
  int x, y;
  for(int i = 0;i < n;++i){
    cin >> x >> y;
    List[x].push_back(y);
    List[y].push_back(x);
  }
  int id;
  cin >> id;
  bfs(id, visited, List);

  int res = 0;
  for(int i = 1;i <= m;++i){
    if(visited[i])
      res++;
  }

  cout << res << '\n';
  for(int i = 1;i <= m;++i){
    if(visited[i]){
      cout << i << " ";
    }
  }
}