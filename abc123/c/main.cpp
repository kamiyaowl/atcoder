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
    mp::cpp_int n;
    cin >> n;

    vector<mp::cpp_int> arr(6); // 移動時間
    vector<mp::cpp_int> term(6); // ターン数
    arr[0] = INT64_MAX;
    term[0] = 0; // dummy
    for(int i = 0 ; i < 5 ; ++i) {
        cin >> arr[i + 1];
    }

    for(int i = 0 ; i < 5 ; ++i) {
        if (arr[i + 1] > arr[i]) {
            // 前回の移動手段のほうが遅いので、そっちに引っ張られる
            term[i + 1] = term[i] + 1; // +1は1ターンのディレイ
        } else {
            mp::cpp_int t = (n / arr[i + 1]) + (n % arr[i + 1] == 0 ? 0 : 1) + i;
            mp::cpp_int recent = term[i] + 1;
            term[i + 1] = t < recent ? recent : t;
        }
    }
    auto result = term[term.size() - 1];
    cout << result << endl;
    return 0;
}