#include  <iostream>
using namespace std;

struct DNode
{
  int info;
  DNode *pNext, *pPrev;
};

struct DList
{
  DNode *pHead, *pTail;
};

void init(DList &l){
  l.pHead = l.pTail = nullptr;
}

DNode *get_node(int x){
  DNode *p = new DNode;
  p->info = x;
  p->pNext = p->pPrev = nullptr;
  return p;
}

void addTail(DList &l, int x){
  DNode *p = get_node(x);
  if(l.pHead == nullptr){
    l.pHead = l.pTail = p;
    return;
  }
  p->pPrev = l.pTail;
  l.pTail->pNext = p;
  l.pTail = p;
}

void createList(DList &l){
  int x;
  cin >> x;
  while(x != -1){
    addTail(l, x);
    cin >> x;
  }
}

void printList(DList l){
  if(l.pHead == nullptr){
    cout << "List is empty";
    return;
  }
  DNode *p = l.pHead;
  while(p){
    cout << p->info << " ";
    p = p->pNext;
  }
}

void addHead(DList &l, int x){
  if(l.pHead == nullptr){
    l.pHead = l.pTail = get_node(x);
    return;
  }
  DNode *p = get_node(x);
  l.pHead->pPrev = p;
  p->pNext = l.pHead;
  l.pHead = p;
}

void addAfter(DList &l, int x, int y){
  if(!l.pHead){
    cout << "\nCan't find the value "<< x;
    return;
  }
  DNode *p = l.pHead;
  bool c = 0;
  while(p){
    if(p->info == x){
      c = 1;
      break;
    }
    p = p->pNext;
  }
  if(!c)  cout << "\nCan't find the value "<< x;
  else{
    if(p == l.pTail){
      addTail(l, y);
      return;
    }
    DNode *p1 = p->pNext, *node = get_node(y);
    node->pPrev = p;
    node->pNext = p1;
    p1->pPrev = node;
    p->pNext = node;
  }
}

void addBefore(DList &l, int x, int y){
  if(!l.pHead){
    cout << "\nCan't find the value "<< x;
    return;
  }
  DNode *p = l.pHead;
  if(p->info == x){
    addHead(l, y);
    return;
  }
  bool c = 0;
  while(p){
    if(p->info == x){
      c = 1;
      break;
    }
    p = p->pNext;
  }
  if(!c)  cout << "\nCan't find the value "<<x;
  else{
    DNode *p1 = p->pPrev, *node = get_node(y);
    p1->pNext = node;
    p->pPrev = node;
    node->pPrev = p1;
    node->pNext = p;
  }
}

int main()
{
  DList L;
  init(L);
  int x,y,choice;

  cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

  while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

  return 0;
}
