#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int e, n;
  
  cin >> e >> n;
  map <string, set<string>> List;
  string x, y;
  for(int i = 0;i < e;++i){
    cin >> x >> y;
    List[x].insert(y);
  }

  int type;
  while(n--){
    cin >> type;
    if(type == 1){
      cin >> x >> y;
      if(List[x].count(y))  cout << "TRUE\n";
      else  cout << "FALSE\n";
    }
    else{
      cin >> x;
      cout << List[x].size() << '\n';
    }
  }
}