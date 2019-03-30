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
    int n; // マスの総数
    int q; // 呪文の数
    string s; // 各盤面のidentify
    cin >> n;
    cin >> q;
    cin >> s;

    vector<int> golems(n, 1); // 各マス1体で初期化
    // 呪文の適用範囲をマップにする
    vector<vector<int>> applies(26, vector<int>(0));
    for(int i = 0 ; i < s.length(); ++i) {
        char c = s[i];
        applies[c - 'A'].push_back(i);
    }

    // 頭からやる
    for(int i = 0 ; i < q ; ++i) {
        char t; // 適用するマス
        char d; // 方向 L or R
        cin >> t;
        cin >> d;
        int index = t - 'A';
        if (d == 'L') {
            // 普通にやる
            for(int j = 0 ; j < applies[index].size() ; ++j) {
                auto target = applies[index][j];
                if(target == 0) {
                    golems[target] = 0;
                } else {
                    golems[target - 1] += golems[target];
                    golems[target] = 0;
                }
            }
        } else {
            // 右からやる
            for(int j = applies[index].size() - 1 ; j >= 0 ; --j) {
                auto target = applies[index][j];
                if(target == n - 1) {
                    golems[target] = 0;
                } else {
                    golems[target + 1] += golems[target];
                    golems[target] = 0;
                }
            }
        }
    }

    int sum = 0;
    for(int i = 0 ; i < golems.size() ; ++i) {
        sum += golems[i];
    }
    cout << sum << endl;

    return 0;
}