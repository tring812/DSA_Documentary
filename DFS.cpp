#include <bits/stdc++.h>
using namespace std;

//---------Description---------
// DFS: luôn xét các đỉnh sinh ra sau trước (dùng stack)

class graph{
    map <string, int> toId;
    vector<vector<int>> matrix;
    vector<string> name;
public:
    void input(int v){
        name.resize(v);
        matrix.resize(v, vector<int>(v, 0));
        for(int i = 0;i < v;++i){
            cin >> name[i];
            toId[name[i]] = i;
        }

        for(int i = 0;i < v;++i){
            for(int j = 0;j < v;++j){
                cin >> matrix[i][j];
            }
        }
    }
    void dfs(int x, int y, int v){
        stack <int> point;
        point.push(x);
        bool valid = 0;
        int count_point_use = 0;
        vector <bool> visit(v, 0);
        map <int, int> path; 
        // path dùng để lưu đường đi, thông qua gắn đỉnh con = đỉnh cha
        // Không để gắn ngược lại vì 1 cha có thể nhiều con (nhiều đường), nhưng 1 con chỉ 1 cha (1 đường)

        while(!point.empty()){
            int top = point.top(); point.pop();
            count_point_use++;

            if(visit[top] == 1)  continue;
            visit[top] = 1;

            if(top == y){
                valid = 1;
                break;
            }

            for(auto id : name){
                if(matrix[top][toId[id]] != 0 && visit[toId[id]] == 0){
                    point.push(toId[id]);
                    path[toId[id]] = top;
                }
            }
        }

        if(!valid)  {
            cout << "-unreachable-\n" << count_point_use << " " << 0 << '\n';
        }
        else{
            long length = 0;
            stack <int> route;
            route.push(y);

            while(y != x){
                length += matrix[path[y]][y];
                y = path[y];
                route.push(y);
            }

            while(!route.empty()){
                cout << name[route.top()] << " ";
                route.pop();
            }
            cout << '\n';
            cout << count_point_use << " " << length << '\n';
        }
    }
    void process(int q, int v){
        string x, y;
        while(q--){
            cin >> x >> y;
            dfs(toId[x], toId[y], v);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int v, q;
    cin >> v >> q;
    graph g;
    g.input(v);
    g.process(q, v);
}