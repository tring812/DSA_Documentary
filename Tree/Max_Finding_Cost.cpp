#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct TNode
{
    int key;
    TNode *left, *right;
};

typedef TNode *TREE;

void CreateTree(TREE &t)
{
    t = NULL;
}

TNode *CreateTNode(int x)
{
    TNode *p = new TNode;
    if (p == NULL)
        return NULL;
    p->left = p->right = NULL;
    p->key = x;
    return p;
}

void InsertNode(TREE &t, int x)
{
    TNode *p = CreateTNode(x);

    if (t == NULL)
    {
        t = p;
        return;
    }
    TREE q = t;
    while (q != NULL)
    {
        if (x == q->key)
            return;
        if (x > q->key)
        {
            if (q->right == NULL)
            {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else
        {
            if (q->left == NULL)
            {
                q->left = p;
                return;
            }
            q = q->left;
        }
    }
}

void LoadTree(TREE &t)
{
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        InsertNode(t, k);
    }
}

void MaxFindingCost(TREE);

int main()
{
    vector<int> keys;
    TREE t;
    CreateTree(t);
    LoadTree(t);
    MaxFindingCost(t);
    return 0;
}


int depth(TREE t){
    if(!t)  return -1;
    return 1 + max(depth(t->right), depth(t->left));
}

void find(TREE t, int d){
    if(!t) return;
    if(d == 0) cout << t->key << " ";
    find(t->left, d - 1);
    find(t->right, d - 1);
}

void MaxFindingCost(TREE t){
    int d = depth(t);
    find(t, d);
}