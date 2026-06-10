

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// adj la danh sach ke. Tra ve so thanh phan lien thong co dung k dinh.

int bfs(int s, vector<bool> &visit, const vector<vector<int>> &adj){
  queue <int> q;
  q.push(s);
  int count = 0;
  visit[s] = false;
  while(!q.empty()){
    int top = q.front(); q.pop();
    count++;
    for(auto id : adj[top]){
      if(visit[id]){
        visit[id] = false;
        q.push(id);
      }
    }
  }
  return count;
}

int countComponentsWithK(vector<vector<int>> adj, int n, int k){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  vector <bool> visit(n, true);
  int res = 0;
  for(int i = 0;i < n;++i){
    if(visit[i] && bfs(i, visit, adj) == k)
      res++;
  }
  return res;
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int k;
  cin >> k;

  cout << countComponentsWithK(adj, n, k) << "\n";

  return 0;
}
