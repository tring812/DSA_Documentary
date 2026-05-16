#include <iostream>

using namespace std;

void output(int *a, int n){
    for(int i = 0;i < n;++i)    cout << a[i] << " ";
    cout << '\n';
}

// --------Description--------
// Mỗi lần duyệt mảng, hoán vị 2 phần tử cạnh nhau nếu trước lớn hơn sau
// Có n phần tử nên tối đa n lần thay đổi để đúng vị trí, nên cần for ngoài để kiếm soát số lần lặp

void output_sort(int *a, int n){
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n - 1;++j){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                output(a, n);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    int *a = new int[n];
    for(int i = 0;i < n;++i)
        cin >> a[i];

    output_sort(a, n);
}