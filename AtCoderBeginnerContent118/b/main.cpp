#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int main(void) {
    int n,m;
    cin >> n; // 人数
    cin >> m; // 食べ物の種類

    vector<int> count(m, 0);

    for(int i = 0 ; i < n ; ++i) {
        int k, a;
        cin >> k; // 好きな物の数
        for(int j = 0 ; j < k ; ++j) {
            cin >> a;
            count[a - 1]++; // 1 < Aij <= Mなので
        }
    }

    vector<int> dst;
    copy_if(count.begin(), count.end(), back_inserter(dst), [n](int x){ return x == n; });
    cout << dst.size() << endl;

    return 0;
}