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

int main(void) {
    int n,q;
    cin >> n;
    cin >> q;

    string s;
    cin >> s;

    // 事前計算
    vector<int> ans(s.length() - 1);
    for(int i = 0 ; i < ans.size() ; ++i) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            ans[i] = 1;
        } else {
            ans[i] = 0;
        }
    } 

    map<tuple<int,int>, int> memo;
    for(int i = 0 ; i < q ; ++i) {
        int l,r;
        cin >> l;
        cin >> r;

        int count = 0;
        auto t = make_tuple(l,r);
        if (memo.count(t)) {
            cout << memo[t] << endl;
        } else {
            for(int j = l - 1 ; j < r - 1; ++j) {
                count += ans[j];
            }
            memo[t] = count;
            cout << count << endl;
        }
    }
    return 0;
}