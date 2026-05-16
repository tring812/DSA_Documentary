#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<string, set<string>> List;
    string x, y;
    while(n--){
        cin >> x >> y;
        List[x].insert(y);
        //List[y].insert(x);
    }

    for(auto id : List){
        if(id.second.size() != List.size() - 1){
            cout << "FALSE";
            return 0;
        }
    }
    cout << "TRUE";
}