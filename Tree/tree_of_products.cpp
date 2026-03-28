#include <iostream>
#include <string>
using namespace std;

typedef struct Product
{
    int id;
    string name;
    string type;
    int year;
    int warranty;
} PRO;

struct Node
{
	PRO info;
	Node *pLeft;
	Node *pRight;
};
typedef struct Node* Tree;

void printProduct(PRO x)
{
    cout <<x.id<<"\t"<<x.name<<"\t"<<x.type<<"\t"<<x.year<<"\t"<<x.warranty<<endl;

}

Node *get_node(PRO x){
    Node *p = new Node;
    p->info = x;
    p->pLeft = nullptr;
    p->pRight = nullptr;
    return p;
}

void add_node(Tree &t, PRO x){
    Node *p = get_node(x);
    if(!t){
        t = p;
        return;
    }

    if(x.id == t->info.id)    return;

    if(x.id > t->info.id)   add_node(t->pRight, x);
    else add_node(t->pLeft, x);
}

void inputTree(Tree &t){
    int n;
    PRO x;
    cin >> n;
    while(n--){
        cin >> x.id;
        cin.ignore();
        getline(cin, x.name);
        getline(cin, x.type);
        cin >> x.year >> x.warranty;
        add_node(t, x);
    }
}

void LNR(Tree t){
    if(!t)  return;
    LNR(t->pLeft);
    printProduct(t->info);
    LNR(t->pRight);
}

int countProducts(Tree t, int year){
    int count = 0;
    if(!t)  return 0;
    if(t->info.year == year)    count++;
    return count + countProducts(t->pLeft, year) + countProducts(t->pRight, year);
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"List of products: ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    LNR(T);

    int year;cin>>year;
    cout<<"Number of products produced in "<<year<<": "<<countProducts(T,year)<<endl;

	return 0;
}

