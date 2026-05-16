#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int i, vector<int>& visited, vector<vector<int>> l){
  queue<int> q;
  q.push(i);
  while(!q.empty()){
    int top = q.front(); q.pop();
    if(visited[top] == 0){
      for(auto id : l[top]){
        q.push(id);
      }
    }
    visited[top] = 1;
  }
}

int main(){
  int m, n;
  cin >> m >> n;

  vector<vector<int>> List(m);
  vector<int> visited(m, 0);
  int x, y;
  for(int i = 0;i < n;++i){
    cin >> x >> y;
    List[x].push_back(y);
    List[y].push_back(x);
  }
  int res = 0;
  for(int i = 0;i < m;++i){
    if(visited[i] == 0){
      res++;
      bfs(i, visited, List);
    }
  }

  cout << res;
}