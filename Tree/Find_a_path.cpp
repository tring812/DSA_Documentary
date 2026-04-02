#include <iostream>

using namespace std;

struct node{
    int info;
    node *left, *right;
};

typedef node* tree;

node *get_node(int x){
    node *p = new node;
    p->info = x;
    p->left = p->right = nullptr;
    return p;
}

void add_node(tree &t, int x){
    node *p = get_node(x);
    if(!t){
        t = p;
        return;
    }
    if(x > t->info) add_node(t->right, x);
    else add_node(t->left, x);
}

void input(tree &t){
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        add_node(t, x);
    }
}

node *search(tree t, int x){
    if(!t)  return nullptr;
    if(t->info == x)    return t;
    if(x > t->info) return search(t->right, x);
    else    return search(t->left, x);
}

void output(tree &t, node *p){
    cout << t->info << " ";
    if(p->info == t->info){
        return;
    }
    else if(p->info > t->info)  output(t->right, p);
    else output(t->left, p); 
}

int main(){
    tree t;
    t = nullptr;
    input(t);
    int x;
    cin >> x;
    node *p = search(t, x);
    if(!p)  cout << "Not found";
    else{
        cout << "Found. Path: ";
        output(t, p);
    }
}