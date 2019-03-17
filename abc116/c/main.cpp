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
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

int mizuyari(vector<int> h) {
    // 0が含まれない区間で分割統治する
    // for(const auto& x : h) {
    //     cout << x << ", ";
    // }
    // cout << endl;

    int count = 0;
    for(int i = 0 ; i < h.size() ; ) {
        if (!h[i]) {
            i++;
            continue;
        }
        vector<int> sub; // 分割統治するvector
        int j;
        for(j = i ; j < h.size() ; ++j ) {
            if(!h[j]) {
                break;
            } else {
                sub.push_back(h[j] - 1); // 水やりする
            }
        }
        // (i, j]区間でいける
        count++; // 今回の水やり分
        count += mizuyari(sub); // 水をやった後の残りはまかした
        // 後処理
        i = j;
    }
    return count;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> h[i];
    }
    auto ans = mizuyari(h);
    cout << ans << endl;
    return 0;
}