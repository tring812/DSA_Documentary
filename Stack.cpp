#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

    //USING AMOUNT OF ELEMENT
/*
struct Stack
{
  int arr[MAX];
  int n; // so luong phan tu cua stack
};

void Init(Stack &s){
  s.n = 0;
  for(int i = 0;i < MAX;++i){
    s.arr[i] = NULLDATA;
  }
}

int isEmpty(Stack s){
  return (s.n == 0);
}

int isFull(Stack s){
  return (s.n == MAX);
}

void Push(Stack &s, int x){
  if(isFull(s)) return;
  s.arr[s.n++] = x;
}

void Pop(Stack &s){
  if(isEmpty(s))  return;
  s.arr[s.n - 1] = NULLDATA;
  s.n--;
}

int Top(Stack s){
  if(isEmpty(s))  return -1;
  return s.arr[s.n - 1];
}

void printStack(Stack s){
  if(isEmpty(s)) cout << "Stack is empty";
  else{
    for(int i = 0;i <= s.n - 1;i++){
      cout << s.arr[i] << " ";
    }
  }
}
*/

    //USING TOP ELEMENT
/*
struct Stack
{
  int arr[MAX];
  int t; // t là chỉ số của phần tử cuối mảng, tức là đỉnh stack
};

void Init(Stack &S)
{
  S.t=-1; //Khi stack chưa có phần tử nào thì top được khởi tạo là -1,
  // nếu khởi tạo t = 0 là SAI vì khi đó sẽ hiểu top tại a[0]
}

int isEmpty(Stack s){
  return (s.t == -1);
}

int isFull(Stack s){
  return (s.t == MAX - 1);
}

void Push(Stack &s, int x){
  if(isFull(s))  return;
  s.arr[++s.t] = x;
}

void Pop(Stack &s){
  if(isEmpty(s)) return;
  s.arr[s.t] = NULLDATA;
  s.t--;
}

int Top(Stack &s){
  if(isEmpty(s))  return -1;
  return s.arr[s.t];
}

void printStack(Stack s){
  if(isEmpty(s)) cout << "Stack is empty";
  else{
    for(int i = 0;i <= s.t;++i)
    cout << s.arr[i] << " ";
  }
}
*/

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
}