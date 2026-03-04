#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
};


struct Node{
	DONTHUC* data;
	Node* next;

};

typedef struct DATHUC{
	Node* head;
	Node* tail;
}List;

Node *get_node(double heso, int somu){
  Node *p = new Node;
  p->data = new DONTHUC;
  p->data->heso = heso;
  p->data->somu = somu;
  p->next = NULL;
  return p;
}

void Nhap(List &l, double heso, int somu){
  Node *p = get_node(heso,somu);
  if(l.head == NULL){
    l.head = l.tail = p;
  }  
  else{
    l.tail->next = p;
    l.tail = p;
  }
}

void Xuat(List l){
  Node *p = l.head;
  bool c = true;
  while(p != NULL){
    double x = p->data->heso;
    int y = p->data->somu;
    if(x != 0){
      if(!c){
        if(x > 0) cout << "+";
        else  cout << "-";
      }
      else{
        if(x < 0) cout << "-";
        c = false;
      }
      if(abs(x) != 1 || y == 0) cout << abs(x);
      if(y > 0){
        cout << "x";
        if(y > 1) cout << "^" << y;
      }
    }  
    p = p->next;
  }
  if(c)  cout << 0;
}

double TinhDaThuc(List l, double x){
  double res = 0;
  Node *p = l.head;
  while(p != NULL){
    res += p->data->heso * pow(x, p->data->somu);
    p = p->next;
  }
  return res;
}

int main() {
    DATHUC B;
    B.head=B.tail=NULL;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
