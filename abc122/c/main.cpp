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
    int sum = 0;
    vector<int> ans_sum(s.length()); // 何回出たか
    for(int i = 0 ; i < ans.size() ; ++i) {
        ans_sum[i] = sum;
        if (s[i] == 'A' && s[i + 1] == 'C') {
            ans[i] = 1;
            sum++;
        } else {
            ans[i] = 0;
        }
    } 
    ans_sum[ans.size()] = sum; // 最後

    for(int i = 0 ; i < q ; ++i) {
        int l,r;
        cin >> l;
        cin >> r;

        int a = ans_sum[l - 1];
        int b = ans_sum[r - 1];
        auto count = b - a;
        cout << count << endl;
    }
    return 0;
}