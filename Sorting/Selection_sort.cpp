#include <iostream>

using namespace std;

void output(int *a, int n){
    for(int i = 0;i < n;++i)    cout << a[i] << " ";
    cout << '\n';
}

//----------Description----------
//  Mỗi lần duyệt i: 0->(n-1), tìm min_id từ i + 1 và swap(a[i], a[mid_id])

void output_sort(int *a, int n){
    for(int i = 0;i < n;++i){
        int id = i;
        for(int j = i + 1;j < n;++j){
            if(a[j] < a[id]){
                id = j;
            }
        }
        if(id != i){
            swap(a[i], a[id]);
            output(a, n);
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