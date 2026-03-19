
#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};
struct List
{
    node *head,*tail;
};
node* getNode(int x)
{
    node *p=new node;
    if (p)
    {
        p->info=x;
        p->next=NULL;
    }
    return p;
}
void Init (List &L)
{
    L.head=L.tail=NULL;
}



void addTail(List &L, int x)
{
    node* p = getNode(x);
    if (L.head==NULL)
        L.head=L.tail=p;
    else
    {
        L.tail->next=p;
        L.tail = p;
    }
}
void inputList(List &L,int n)
{

    int x;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        addTail(L,x); // them phan tu moi vao cuoi danh sach
    }
}

void outputList(List L)
{
    if (L.head==NULL)
    {
        cout<<"List is empty"; return;
    }

    node *p=L.head;
    while (p)
    {
       cout<<p->info<<" ";
        p=p->next;
    }
}

void insertList(List &l, int x){
    if(l.head == nullptr){
        l.head = getNode(x);
        return;
    }

    if(l.head->info >= x){
        node *p = getNode(x);
        p->next = l.head;
        l.head = p;
        return;
    }

    node *p = l.head, *p1 = getNode(x);
    while(p != l.tail && p->next->info <= x)
        p = p->next;

    if(p == l.tail){
        l.tail->next = p1;
        l.tail = p1;
    }
    else{
        p1->next = p->next;
        p->next = p1;
    }
}

int main()
{
    List L;
    Init(L);
    int n,x; cin>>n;
    inputList(L,n);
    cout<<"Created List: ";
    outputList(L);
    cout<<"\nEnter a number to add to the list: ";
    cin>>x;
    insertList(L,x);
    cout<<"\nUpdated List: ";
    outputList(L);
    return 0;
}

