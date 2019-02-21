#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    int alice = 0;
    int bob = 0;
    for(int i = 0 ; i < n ; ++i) {
        if(i % 2 == 0) {
            alice += a[i];
        } else {
            bob += a[i]
        }
    }
    auto result = alice - bob;
    cout << result << endl;    

    return 0;
}