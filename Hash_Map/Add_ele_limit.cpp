#include <iostream>
#include <vector>

using namespace std;

struct hash_table{
  int n; //số phần tử đã add
  int m; //số phần tử max
  vector<vector<int>> a; // thêm dồn các phần tử có cùng h(key)
};

void add(hash_table& h, double load, int x){
  int mod = x % h.m;

  // Kiểm tra nếu như add phần tử vào có bị quá hệ số tải không
  // Hệ sổ tải = n / m; (sổ phần tử đã thêm / số phần tử max)
  if(((float)h.n + 1.0) / h.m <= load){
    h.a[mod].push_back(x);
    h.n++;
  }
}

int main(){
  hash_table h;
  h.n = 0;
  double load;
  int n, x, q;
  cin >> h.m >> load >> n;
  h.a.resize(h.m);

  for(int i = 0;i < n;++i){
    cin >> x;
    add(h, load, x);
  }

  cin >> q;
  while(q--){
    cin >> x;
    int mod = x % h.m, count = 0, check = 0;
    for(int i = 0;i < h.a[mod].size();++i){
      count++;
      if(h.a[mod][i] == x){
        cout << count << '\n';
        check = 1;
        break;
      }
    }

    if(!check)  cout << "KHONG\n";
  }
}