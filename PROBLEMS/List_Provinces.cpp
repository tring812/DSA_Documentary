
#include <iostream>
#include <cstring>
#include <string>
using namespace std;


struct prov{
  int id, pop;
  double area;
  string name;
};

struct node{
  prov info;
  node *next;
};

struct List{
  node *head, *tail;
};

void Init(List &l){
  l.head = l.tail = nullptr;
}

node *get_node(int a, string b, int c, double d){
  node *p = new node;
  p->info.id = a, p->info.name = b, p->info.pop = c, p->info.area = d;
  p->next = nullptr;
  return p;
}

void add_tail(List &l, int a, string b, int c, double d){
  node *p = get_node(a,b,c,d);
  if(l.head == nullptr){
    l.head = l.tail = p;
  }
  else{
    l.tail->next = p;
    l.tail = p;
  }
}

void inputListProvinces(List &l){
  int t;
  cin >> t;
  while(t--){
    int a, c;
    double d;
    string b;
    cin >> a;
    cin.ignore();
    getline(cin, b);
    cin >> c >> d;
    add_tail(l,a,b,c,d);
  }
}

void outputListProvinces(List &l){
  cout << "ID    |Province    |Population    |Area\n";
  if(l.head == nullptr){
    cout << "List is empty";
    return;
  } 
  node *p = l.head;
  while(p != nullptr){
    cout << p->info.id << '\t' << p->info.name << '\t' << p->info.pop << '\t' << p->info.area << '\n';
    p = p->next;
  }
}

string f(node *p){
  string s = "", ss = p->info.name;
  int idx = ss.size() - 1;
  while(ss[idx] != ' '){
    s = ss[idx] + s;
    idx--;
  }
  return s;
}

void find(List &l){
  cout << "Enter the last word of name to search:\n";
  string s;
  cin >> s;
  node *p = l.head;
  node *nu = nullptr;
  bool c = 0;
  while(p != nullptr){
    if(f(p) == s){
      c = 1;
      if(p == l.head){
        l.head = p->next;
        delete p;
        p = l.head;
      }
      else{
        nu->next = p->next;
        if(p == l.tail){
          l.tail = nu;
        }
        delete p;
        p = nu->next;
      }
    }
    else{
      nu = p;
      p = p->next;
    }
  }
  if(c == 0){
    cout << "Not found";return;
  }
  cout << "Updated List:\n";
  outputListProvinces(l);
}

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout << "List of provinces:\n";
    outputListProvinces(L);
    find(L);
    
}



