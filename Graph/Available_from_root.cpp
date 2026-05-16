#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <queue>  
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int m, n;
  cin >> m >> n;
  stack <int> st;
  set <int> res;
  vector <int> visit(m, 0);
  vector <vector<int>>List(m);
  int x, y;
  for(int i = 0;i < n;++i){
    cin >> x >> y;
    List[x].push_back(y);
    List[y].push_back(x);
  }

  for(auto id : List[0]){
    res.insert(id);
    st.push(id);
  }

  while (!st.empty()) {
      int u = st.top(); 
      st.pop();
      for (auto v : List[u]) {
          if (!visit[v]) {
              visit[v] = 1;
              res.insert(v);
              st.push(v);
          }
      }
  }
  
  res.erase(0);
  if(res.size() != 0){
    for(auto id : res){
      cout << id << " ";
    }
  }
  else{
    cout << "KHONG";
  }
}