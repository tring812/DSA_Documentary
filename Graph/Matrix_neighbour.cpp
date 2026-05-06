/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -
class Graph{
private:
    vector <string> dinh;
    vector <vector<int>> matrix;
    map <string, int> toId;
public:
    void nhap(int v, int e){
        string x, y;
        for(int i = 0;i < v;++i){
            cin >> x;
            dinh.push_back(x);
            toId[x] = i;
        }
        
        matrix.resize(v, vector<int>(v, 0));
        for(int i = 0;i < e;++i){
            cin >> x >> y;
            matrix[toId[x]][toId[y]] = 1;
        }
    }

    void myProcess(int n){
        int t;
        string x, y;
        while(n--){
            cin >> t;
            if(t == 1){
                cin >> x >> y;
                if(matrix[toId[x]][toId[y]]){
                    cout << "TRUE\n";
                }
                else  cout << "FALSE\n";
            }
            else{
                int c = 0;
                cin >> x;
                for(auto tmp : dinh){
                    if(matrix[toId[x]][toId[tmp]]){
                        cout << tmp << " ";
                        c = 1;
                    }
                }
                if(!c)  cout << "NONE";
                cout << '\n';
            }
        }
    }
};

int main()
{
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

