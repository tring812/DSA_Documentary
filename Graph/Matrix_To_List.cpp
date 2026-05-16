#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector <vector<int>> matrix(n, vector<int>(n, 0));
  vector <vector<int>> List(n);
  for(int i = 0;i < n;++i){
    for(int j = 0;j < n;++j){
      cin >> matrix[i][j];
    }
  }

  for(int i = 0;i < n;++i){
    for(int j = 0;j < n;++j){
      if(matrix[i][j]){
        List[i].push_back(j);
      }
    }
  }

  for(int i = 0;i < n;++i){
    if(!List[i].empty()){
      cout << i + 1 << "->";
      for(auto x : List[i]){
        cout << x + 1 << " ";
      }
      cout << '\n';
    }
  }
}