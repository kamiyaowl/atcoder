#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <stdbool.h>
#include <bitset>
#include <string>

using namespace std;

int main(void) {
    int n, m;
    cin >> n; // コマの数
    cin >> m; // 目標地点の数

    // 置くだけで終わるなら終わり
    if(n >= m) {
        cout << "0" << endl;
        return 0;
    }
    vector<int> x(m);
    for(int i = 0 ; i < m ; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    // 各区間の移動回数を求める
    vector<int> l(m-1);
    for(int i = 0 ; i < l.size() ; ++i) {
        l[i] = x[i + 1] - x[i];
    }
    sort(l.begin(), l.end(), greater<int>());
    // n=1だったときの最悪移動回数
    int max = x[x.size() - 1] - x[0];
    int diff = 0;
    for(int i = 0 ; i < n - 1 ; ++i) {
        diff += l[i];
    }
    int result = max - diff;
    cout << result << endl;
    return 0;
}