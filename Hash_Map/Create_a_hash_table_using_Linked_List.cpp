
#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

struct node{
  int info;
  node *next;
};

struct List{
  node *head, *tail;
};

struct Hash{
  int m;
  List b[MAX];
};

void initHash(Hash &h){
  for(int i = 0;i < h.m;++i){
    h.b[i].head = nullptr;
  }
}

node *get_node(int x){
  node *p = new node;
  p->info = x;
  p->next = nullptr;
  return p;
}

void add_node(List &l, int x){
  if(l.head == nullptr){
    l.head = l.tail = get_node(x);
    return;
  }

  node *p = l.head,
       *p1 = get_node(x);
  if(p->info > x){
    p1->next = p;
    l.head = p1;
    return;
  }

  while(p != l.tail){
    if(p->next->info > x) break;
    p = p->next;
  }
  if(p == l.tail){
    l.tail->next = p1;
    l.tail = p1;
  }
  else{
    p1->next = p->next;
    p->next = p1;
  }
}

void output(List l){
  if(!l.head) return;
  node *p = l.head;
  while(p){
    cout << p->info << " ";
    p = p->next;
  }
}

void insertHash(Hash &h, int x){
  int id = x % h.m;
  add_node(h.b[id], x);
}

void traverseAllHash(Hash h){
  for(int i = 0;i < h.m;++i){
    cout << "Bucket " << i << ": "; output(h.b[i]);
    cout <<'\n';
  }
}

int main()
{
    Hash H;
    cin>>H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"Created Hash:"<<endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}

