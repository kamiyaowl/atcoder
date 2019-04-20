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
    int n;
    string s; // '#' or '.'
    cin >> n >> s;
    string s2(s);

    // 短い場合
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    } else if(n == 2) {
        cout << ((s[0] == '#' && s[1] == '.') ? 1 : 0) << endl;
        return 0;
    }

    // main
    int count = 0;
    for(int i = 0 ; i < n ; ++i) {
        auto before = (i > 0) ? s[i-1] : '.'; // 無害
        auto current = s[i];
        auto next =  (i < n - 1) ? s[i] : '#'; // 境界なので、最後は無害なので黒にしておく
        // 関係ない
        if (before != '#') continue;
        if (current != '.') continue;
        // 処置がいる
        s[i] = '#';
        count++;
    }
    int count2 = 0;
    for(int i = 0 ; i < n ; ++i) {
        auto before = (i > 0) ? s2[i-1] : '.'; // 無害
        auto current = s2[i];
        auto next =  (i < n - 1) ? s2[i] : '#'; // 境界なので、最後は無害なので黒にしておく
        // 関係ない
        if (before != '#') continue;
        if (current != '.') continue;
        // 処置がいる
        s2[i-1] = '.';
        count2++;
    }
    // result
    cout << min(count, count2) << endl;

    return 0;
}