#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node{
  int value;
  node *next;
};

struct List{
  node *head, *tail;
};

void Init(List &l){
  l.head = nullptr, l.tail = nullptr;
}

node *get_node(int x){
  node *p = new node;
  p->next = nullptr;
  p->value = x;
  return p;
}

void add_tail(List &l, int x){
  node *p = get_node(x);
  if(l.head == nullptr){
    //If empty, head and tail will point current node
    l.head = p;
    l.tail = p;
  }
  else{
    //Else, the current TAIL node will point to current node
    l.tail->next = p;
    l.tail = p; 
  }
}


void inputList(List &L, int n){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int x;
  for(int i = 0;i < n;++i){
    cin >> x;
    add_tail(L, x);
  }
}

void outputList(List L){
  node *p = L.head;
  if(p == nullptr){
    cout << "List is empty";return;
  }
   while(p != nullptr){
    cout << p->value << " ";
    p = p->next;
  }
}

void outputGreaterThan(List L, int m){
  node *p = L.head;
  bool exist = 0;
  if(p == nullptr){
    cout << "List is empty";return;
  }
  while(p != nullptr){
    if(p->value > m){
      cout << p->value << " ";
      exist = 1;
    }
    p = p->next;
  }
  if(!exist)  cout << "None";
}

int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout<<"Enter a number: "; cin>>n; // Nhap so luong phan tu cua ds
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout<<"\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"


    cout<<"\nEnter a number: "; int m; cin>>m;
    cout<<"\nValues greater than "<<m<<": ";
    outputGreaterThan(L,m);
    /*Xuat tat ca cac gia tri duoc luu trong ds lon hon m.
     Neu ds rong thi xuat thong bao "List is empty".
     Neu ds khong rong nhung khong co gia tri thoa yeu cau thi xuat "None"*/

    return 0;
}
