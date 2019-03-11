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
    mp::cpp_int n, m;
    cin >> n; // 店の件数
    cin >> m; // ドリンク本数
    map<mp::cpp_int,mp::cpp_int> drinks; // price -> counts

    for(mp::cpp_int i = 0 ; i < n ; ++i) {
        mp::cpp_int  a, b;
        cin >> a;
        cin >> b;
        drinks[a] = b;
    }
    // countが残り本数, sum=合計金額
    mp::cpp_int count = m;
    mp::cpp_int sum = 0;
    for(const auto& d: drinks) {
        if(d.second < count) {
            // 買い占め
            count -= d.second;
            sum += d.first * d.second;
        } else {
            sum += d.first * count;
            count = 0;
            break;
        }
    }
    cout << sum.str() << endl;
    return 0;
}