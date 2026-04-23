#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;




struct Hash
{
    int hashtable[M];
    int n; //số phần tử hiện có trên bảng băm
};
int hashfunc (int key)
{	return (key % M); 	}

void initHash(Hash& h){
    for(int i = 0;i < M;++i){
        h.hashtable[i] = NULLKEY;
    }
    h.n = 0;
}

bool insert(Hash&h, int x){
    int mod_temp = hashfunc(x);
    for(int i = 0;i < 9;++i){
        int mod = (mod_temp + i * i + i) % M;
        if(h.hashtable[mod] == NULLKEY && h.n < 10){
            h.hashtable[mod] = x;
            h.n++;
            return 1;
        }
    }
    return 0;
}

int insertHash(Hash& h, int x){
    bool c = insert(h, x);
    if(!c)  return -1;
    else    return 1;
    
}

void traverseAllHash(Hash h){
    for(int i = 0;i < M;++i){
        cout << i;
        if(h.hashtable[i] != NULLKEY){
            cout << " --> " << h.hashtable[i];
        }
        cout << '\n';
    }
}

int main()
{
    Hash H;
    initHash(H);
    vector<int> b;
    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;        
        int k=insertHash(H,x);// them 1 gia tri du lieu vao bang bam       
        if(k==-1) b.push_back(x); // neu khong them duoc thi bo vao vector, de khi can thi co the xu ly nhung so nay
    }
    cout<<"\nBang bam:"<<endl;
    traverseAllHash(H);
    if(!b.empty())cout<<"Co "<<b.size()<<" gia tri khong them duoc";
    return 0;
}

