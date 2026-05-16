#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;

    map<string, map<string, int>> List;
    string x, y; int x1;
    for(int i = 0;i < n;++i){
        cin >> x >> y;
        cin >> x1;
        List[x][y] = x1;
    }

    string s;
    cin.ignore();
    for(int i = 0;i < q;++i){
        cin >> s;
        stack <string> st;
        bool check = 1;
        long long res = 0;
        while(s != "."){
            if(st.empty())  st.push(s);
            else{
                if(List[st.top()].count(s)){
                    res += List[st.top()][s];
                    st.pop();
                    st.push(s);
                }
                else{
                    check = 0;
                }
            }
            cin >> s;
        }
        if(check)   cout << res << '\n';
        else    cout << "FALSE\n";
    }
}