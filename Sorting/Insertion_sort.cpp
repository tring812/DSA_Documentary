#include <iostream>

using namespace std;

void output(int *a, int n){
    for(int i = 0;i < n;++i)    cout << a[i] << " ";
    cout << '\n';
}

//------Description-------
// Mỗi lần duyệt i: 0->(n-1), lưu lại giá trị a[i];
// Đẩy các phần tử ở trước mà lớn hơn về sau
// Vd: 3 1 4 2 5 -> 1 (3) 4 2 5 -> 1 2 (3) (4) 5

void output_sort(int *a, int n){
    for(int i = 1;i < n;++i){
        int x = a[i], id = i;
        for(int j = i - 1;j >= 0 && x < a[j];--j){
            id = j;
            a[j + 1] = a[j];
            output(a, n);
        }
        a[id] = x;
        output(a, n);

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