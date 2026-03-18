#include <bits/stdc++.h>
using namespace std;

struct node{
	int value;
	node *next;
};

struct List{
	node *head, *tail;	
};

void init(List &l){
	l.head = l.tail = nullptr;
}

node *get_node(int x){
	node *p = new node;
	p->value = x;
	p->next = nullptr;
	return p;
}

void add_head(List &l, int x){
	node *p = get_node(x);
	if(l.head == nullptr){
		l.head = p;
		l.tail = p;
	}
	else{
		p->next = l.head;
		l.head = p;
	}
}

void add_tail(List &l, int x){
	node *p = get_node(x);
	if(l.head == nullptr){
		l.head = p;
		l.tail = p;
	}
	else{
		l.tail->next = p;
		l.tail = p;
	}
}

void add_mid(List &l, int a, int b){
	if(l.head == nullptr){
		add_head(l, b);
		return;
	}
	node *aft = get_node(b);
	node *p = l.head;
	while(p != nullptr){
		if(p->value == a){
			if(l.tail == p){
				add_tail(l, b);
				return;
			}
			else{
				aft->next = p->next;
				p->next = aft;
				return;
			}
		}
		p = p->next;
	}
	add_head(l, b);
}

void del(List &l){
	if(l.head == nullptr)	return;
	node *p = l.head;
	l.head = l.head->next;
	p->next = nullptr;
	delete p;
}

void del_n(List &l, int x){
	if(l.head == nullptr)	return;
	node *p = l.head;
	if(p->value == x){
		l.head = p->next;
		delete p;
		return;
	}
	while(p != nullptr){
		node *p1 = p->next;
		if(p1 != nullptr && p1->value == x){
			if(p1 == l.tail){
				p->next = nullptr;
				l.tail = p;
				return;
			}
			else{
				p->next = p1->next;
				p1->next = nullptr;
				delete p1;
				return;
			}
		}
		p = p->next;
	}
	return;
}

void print(List l){
	node *p = l.head;
	if(p == nullptr){
		cout << "blank";
		return;
	}
	while(p != nullptr){
		cout << p->value << " ";
		p = p->next;
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	List l;
	init(l);
	int t;
	cin >> t;
	while(t != 6){
		int x, y;
		switch(t){
			case 0:
				cin >> x;
				add_head(l, x);
				break;
			case 1:
				cin >> x;
				add_tail(l, x);
				break;
			case 2:
				cin >> x >> y;
				add_mid(l, x, y);
				break;
			case 3:
				cin >> x;
				del_n(l, x);
				break;
			case 5:
				del(l);
		}
		cin >> t;
	}
	print(l);
}