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
    map<char, vector<int>> applies;
    for(int i = 0 ; i < s.length(); ++i) {
        char c = s[i];
        if(!applies.count(c)) {
            applies[c] = vector<int>();
        }
        applies[c].push_back(i);
    }

    // 頭からやる
    for(int i = 0 ; i < q ; ++i) {
        char t; // 適用するマス
        char d; // 方向 L or R
        cin >> t;
        cin >> d;
        if(applies.count(t)) {
            if (d == 'L') {
                // 普通にやる
                for(int j = 0 ; j < applies[t].size() ; ++j) {
                    auto target = applies[t][j];
                    if(target == 0) {
                        golems[target] = 0;
                    } else {
                        golems[target - 1] += golems[target];
                        golems[target] = 0;
                    }
                }
            } else {
                // 右からやる
                for(int j = applies.size() - 1 ; j >= 0 ; --j) {
                    auto target = applies[t][j];
                    if(target == n - 1) {
                        golems[target] = 0;
                    } else {
                        golems[target + 1] += golems[target];
                        golems[target] = 0;
                    }
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