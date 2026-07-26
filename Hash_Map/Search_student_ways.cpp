#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

struct student
{
  string code, name, cls;
  double gpa;
};

int main()
{
  int n;
  cin >> n;
  student x;

  map <string, vector<string>> byclass;
  map <string, student> bycode;
  student top;
  top.gpa = 0.0;

  for (int i = 0; i < n; ++i) {
    cin >> x.code >> x.name >> x.gpa >> x.cls;
    bycode[x.code] = x;
    byclass[x.cls].push_back(x.code);

    if(x.gpa > top.gpa){
      top = x;
    }
    else if(x.gpa == top.gpa && x.code < top.code){
      top = x;
    }
  }

  int q;
  string type, cmd;
  cin >> q;
  cout << fixed << setprecision(2);
  while (q--) {
    cin >> type >> cmd;
    if(type == "FIND"){
      if(bycode.count(cmd) == 0)  cout << "NOT_FOUND";
      else cout << bycode[cmd].code << " " << bycode[cmd].name << " " << bycode[cmd].gpa << " " << bycode[cmd].cls;
    }
    else if(type == "LIST"){
      if(byclass[cmd].size() == 0)  cout << "EMPTY";
      else{
        for(string id : byclass[cmd]){
          cout << id << " ";
        }
      }
    }
    else{
      if(n == 0)  cout << "EMPTY";
      else cout << top.code << " " << top.name << " " << top.gpa;
    }
    cout << '\n';
  }
}