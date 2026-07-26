#include <iostream>

using namespace std;

void output(int *a, int n){
    for(int i = 0;i < n;++i)
        cout << a[i] << " ";
    cout << '\n';
}

void heapify(int *a, int i, int n){
    int j = 2 * i + 1;
    while(j < n){
        if(j + 1 < n && a[j] < a[j + 1]) j++;
        if(a[i] > a[j]) return;
        swap(a[i], a[j]);
        i = j;
        j = 2 * i + 1;
    }
}

void buildHeap(int *a, int n){
    int i = n / 2 - 1;
    while(i >= 0){
        heapify(a, i, n);
        i--;
    }
}

void heapSort(int *a, int n){
    buildHeap(a, n);
    while(n > 1){
        swap(a[0], a[n - 1]);
        n--;
        heapify(a, 0, n);
    }
}

int main(){
    int n;
    cin >> n;
    int *a = new int [n];
    for(int i = 0;i < n;++i)    cin >> a[i];
    heapSort(a, n);
    output(a, n);

}
