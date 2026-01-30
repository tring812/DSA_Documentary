#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct node{
  int info;
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
  p->info = x;
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
    cout << p->info << " ";
    p = p->next;
  }
}

node *findMax(List L){
  node *p = L.head;
  //Set first point as max value
  node *p1 = p;
  int ma = p->info;
  if(p == nullptr){
    cout << "List is empty";
    return nullptr;
  }
  else{
    while(p != nullptr){
      if(p->info > p1->info){
        //Update max value pointer
        p1 = p;
      }
      p = p->next;
    }
    return p1;
  }
}

int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);


    cout<<"\nThe maximum value: ";
    node *p = findMax(L);
    if(p) cout<<p->info;

    return 0;
}
