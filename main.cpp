#include <iostream>
#include <list>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    list<int> p;
    for(int i=0;i<10;i++){
        p.push_back(i);
    }
    int tmp;
    for(int i=0;i<10;i++){
        tmp=p.back();
        cout<<tmp<<endl;
        p.pop_back();
    }
    return 0;
}