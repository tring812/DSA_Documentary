#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

struct Node {
    Hocsinh data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

void Output(List ds) {
    Node *p = ds.head;
    if (p == NULL) {
        cout << "EMPTY";
    }
    while(p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

Node *get_node(Hocsinh x){
    Node *p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void add_tail(List &l, Hocsinh x){
    Node *p = get_node(x);
    if(l.head == nullptr)
        l.head = l.tail = p;
    else{
        l.tail->next = p;
        l.tail = p;
    }
}

double dtb(Hocsinh x){
    return (x.Anh + x.Toan + x.Ly + x.Hoa + x.Sinh + x.Van) / 6.0;
}

int main(){
    List l;
    l.head = l.tail = nullptr;
    int n;
    cin >> n;
    while(n--){
        Hocsinh x;
        InputElement(x);
        if(dtb(x) >= 9.0)
            add_tail(l, x);
    }
    Output(l);
}