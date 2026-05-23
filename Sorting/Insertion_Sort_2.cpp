#include <iostream>

using namespace std;

void out(int *a, int n){
  for(int i = 0;i < n;++i){
    cout << a[i] << " ";
  }
  cout << '\n';
}

void sort(int *a, int n){
  for(int i = 1;i < n;++i){
    int mi = i, tmp = a[i];
    cout << "\ni = " << i;
    cout << "\nMang truoc khi xu ly: "; out(a, n);
    cout << "Phan tu dang xet A[" << i << "] = " << a[i];
    for(int j = i - 1;j >= 0 && tmp > a[j];--j){
      a[j + 1] = a[j];
      mi = j;
    }
    cout << "\nChen " << tmp << " vao vi tri k = " << mi;
    a[mi] = tmp;
    cout << "\nMang sau khi xu ly: "; out(a, n);
  }
}

int main(){
  int n;
  cin >> n;
  int *a = new int [n + 1];
  for(int i = 0;i < n;++i){
    cin >> a[i];
  }

  cout << "Mang truoc khi sap xep:\n";
  out(a, n);
  cout << "\nSap xep:";
  sort(a, n);

  cout << "\nMang sau khi sap xep:\n"; out(a, n);
}