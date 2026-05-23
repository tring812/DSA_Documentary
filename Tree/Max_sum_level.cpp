#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TNode
{
	int key;
	TNode *left, *right;
};

typedef TNode *TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE)
{
	int i;
	TREE root;
	if (inE < inB)
		return NULL;
	root = new TNode;
	if (root != NULL)
	{
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB])
				break;
		root->left = CreateTree(pre, in, preB + 1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB + i - inB + 1, preE, i + 1, inE);
	}
	return root;
}

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0)
	{
		v.push_back(tmp);
		cin >> tmp;
	}
}

int MaxLevel(TREE);

int main()
{
	vector<int> nlr, lnr;
	int n, key, m, lvl;

	Input(nlr);
	Input(lnr);

	TREE r = CreateTree(nlr, lnr, 0, nlr.size() - 1, 0, lnr.size() - 1);

	cout << MaxLevel(r) << endl;

	return 0;
}

int depth(TREE t)
{
	if (!t)
		return -1;
	return 1 + max(depth(t->left), depth(t->right));
}

void ksum(TREE t, int k, int &sum){
	if(!t)	return;
	if(k == 0) sum += t->key;
	ksum(t->left, k - 1, sum);
	ksum(t->right, k - 1, sum);
}

int MaxLevel(TREE t){
	if(!t)	return 0;
	int sum = 0, d = depth(t), maxSum = 0, maxK = 0;
	for(int i = 0;i <= d;++i){
		sum = 0;
		ksum(t, i, sum);
		if(sum > maxSum){
			maxSum = sum;
			maxK = i;
		}
	}
	return maxK;
}