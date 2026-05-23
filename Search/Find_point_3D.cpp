#include <iostream>

using namespace std;

struct point{
  double x, y, z;
};

bool equal(point a, point b){
  return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z));
}

bool lessp(point a, point b){
  if(a.x != b.x)  return (a.x < b.x);
  if(a.y != b.y)  return (a.y < b.y);
  return (a.z < b.z);
} 

void binsearch(point *a, point find, int l, int r, int &id, int &count){
  while(l <= r){
    id = (l + r)/2;
    count++;
    if(equal(a[id], find))  return;
    if(lessp(a[id], find)) l = id + 1;
    else  r = id - 1;
  }
}

int main(){
  int n;
  cin >> n;
  point *a = new point[n + 1];
  for(int i = 0;i < n;++i){
    cin >> a[i].x >> a[i].y >> a[i].z;
  }

  int q;
  cin >> q;
  point find;
  while(q--){
    int l = 0, r = n - 1, count = 0, id;
    cin >> find.x >> find.y >> find.z;
    binsearch(a, find, l, r, id, count);

    if(!equal(a[id], find)) cout << "KHONG\n";
    else{
      cout << count << '\n';
    }
  }
}