#include <iostream>

using namespace std;

void out(int *a, int n){
  for(int i = 0;i < n;++i){
    cout << a[i] << " ";
  }
  cout << '\n';
}

void sort(int *a, int n){
  for(int i = 0;i < n - 1;++i){
    int mi = i;
    cout << "\ni = " << i;
    cout << "\nMang truoc khi swap: "; out(a, n);
    for(int j = i + 1;j < n;++j){
      if(a[j] > a[mi]){
        mi = j;
      }
    }
    cout << "Phan tu lon nhat trong doan [" << i + 1 << ", " << n - 1 << "]: " << a[mi];
    cout << "\nSwap " << a[i] << " va " << a[mi];
    swap(a[i], a[mi]);
    cout << "\nMang sau khi swap: "; out(a, n);
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