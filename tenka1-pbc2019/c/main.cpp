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
    for(int i = 1 ; i < n ; ++i) {
        auto before = s[i-1];
        auto current = s[i];
        auto next =  (i < n - 1) ? s[i] : '#'; // 境界なので、最後は無害なので黒にしておく
        // 関係ない
        if (before != '#') continue;
        if (current != '.') continue;
        // 処置がいる
        if (next == '#') {
            // 右隣が黒なら色を変えても問題ない
            s[i] = '#';
            count++;
        } else {
            s[i-1] = '.';
            count++;
        }
    }
    // debug
    cout << s << endl;

    // result
    cout << count << endl;

    return 0;
}