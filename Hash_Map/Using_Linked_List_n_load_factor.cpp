#include<iostream>
using namespace std;
struct node
{
    int info;
    node* next;
};
struct List
{
    node *head, *tail;

};
struct Hash
{
    int m;
    int n;
    float load;
    List *pL; //con tro quan ly 1 mang chua cac List
};

node* get_node(int x){
    node *p = new node;
    p->info = x;
    p->next = nullptr;
    return p;
}

void add_tail(List& l, int x){
    node *p = get_node(x);
    if(!l.head){
        l.head = l.tail = p;
        return;
    }
    l.tail->next = p;
    l.tail = p;
    return;
}

void output(List l){
    node* p = l.head;
    while(p){
        cout << p->info << " ";
        p = p->next;
    }
}

int search(List l, int k){
    node *p = l.head;
    if(!p)  return 0;
    int count = 1;
    while(p){
        if(p->info == k)    return count;
        p = p->next;
        count++;
    }
    return 0;
}

void inputHash(Hash &h, int n){
    h.pL = new List[h.m];
    h.pL->head = h.pL->tail = nullptr;
    int x, count = 0;
    float check = 0;
    for(int i = 0;i < n;++i){
        cin >> x;
        check = ((float)count + 1.0) / h.m;
        if(check <= h.load){
            int mod = x % h.m;
            add_tail(h.pL[mod], x);
            count++;
        }
    }
}

void printHash(Hash h){
    for(int i = 0;i < h.m;++i){
        cout << "List " << i << ": ";
        output(h.pL[i]);
        cout << '\n';
    }
}

void searchHash(Hash h, int k){
    int res = search(h.pL[k % h.m], k);
    if(res == 0)    cout << "KHONG\n";
    else    cout << res << '\n';
}

int main()
{
    Hash H;  cin>>H.m>>H.load;
    int n;cin>>n;
    inputHash(H,n);
    printHash(H);
    int nkey,key;cin>>nkey;

    for(int i=0;i<nkey;i++)
    {
        cin>>key;
        searchHash(H,key);
    }
    return 0;
}
