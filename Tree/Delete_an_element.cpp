
#include <iostream>
using namespace std;

struct node{
    int info;
    node *left, *right;
};

typedef node* Tree;

node *get_node(int x){
    node *p = new node;
    p->info = x;
    p->left = p->right = nullptr;
    return p;
}

void add_node(Tree &t, int x){
    node *p = get_node(x);
    if(!t){
        t = p;
        return;
    }
    if(x > t->info) add_node(t->right, x);
    else    add_node(t->left, x);
}

void inputTree(Tree &t){
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        add_node(t, x);
    }
}

void NLR(Tree t){
    if(!t)  return;
    cout << t->info << " ";
    NLR(t->left);
    NLR(t->right);
}

void replace(node *&p, node *&t){
    if(t->right)   replace(p, t->right);
    else{
        p->info = t->info;
        p = t;
        t = t->left;
    }
}

void deleteNode(Tree &t, int x){
    if(!t){
        cout << "Not found";
        return;
    }

    if(x > t->info) deleteNode(t->right, x);
    else if(x < t->info)    deleteNode(t->left, x);

    else{
        cout<<"\nDo you want to delete "<<x<< "?(y/n):";
        char s;
        cin >> s;
        if(s == 'y' || s == 'Y'){
            node *p = t;
            if(!p->left)
                t = t->right;
            else if(!p->right)
                t = t->left;
            else
                replace(p, t->left);
            delete p;
        }
    }
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
    int x; cout<<"\nEnter the element you want to delete: ";cin>>x;
    deleteNode(T,x);
    cout<<"\nNLR: "; NLR(T);

	return 0;
}
