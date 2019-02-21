#include<iostream>
#include<set>

using namespace std;

int main(void){
    int n;
    cin >> n;

    set<int> d;
    for(int i = 0 ; i < n ; ++i){
        int tmp;
        cin >> tmp;
        d.insert(tmp);
    }
    cout << d.size() << endl;

    return 0;
}