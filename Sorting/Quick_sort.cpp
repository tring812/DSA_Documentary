#include <iostream>
using namespace std;

//---------Description---------
// Bước 1: Lấy phần tử ở chính giữa làm mốc (tùy yêu cầu bài)
// Bước 2: Tìm vị trí i: lớn hơn (từ trái qua), j: bé hơn (từ phải qua)
// Bước 3: Kiểm tra nếu 2 phần tử nằm 2 phía hoặc trùng nhau (i <=j) thì swap
// Bước 4: Lặp lại quá trình phân hoạch đến khi i > j
// Bước 5: Phân hoạch đến khi chỉ còn 1 tử bằng cách kiểm tra (l,j) , (i,r) và đệ quy

void sorting(int* a, int l, int r, int& res){
  if(l >= r)  return;
  int mid = a[(l + r) / 2];
  int i = l, j = r;
  while(i <= j){
    while(a[i] < mid) i++;
    while(a[j] > mid) j--;
    if(i <= j){
      swap(a[i], a[j]);
      i++;
      j--;

      //Biến res là số lần hoán vị thỏa mãn
      res++;
    }
  }
  if(l < j) sorting(a, l, j, res);
  if(i < r) sorting(a, i, r, res);
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int n;
  cin >> n;
  int *a = new int[n + 1];
  for(int i = 0;i < n;++i){
    cin >> a[i];
  }
  int res = 0;

  sorting(a, 0, n - 1, res);
  cout << "Sorted Array: ";
  for(int i = 0;i < n;++i){
    cout << a[i] << " ";
  }
  cout << "\nNumber of times to swap 2 numbers: " << res;
}