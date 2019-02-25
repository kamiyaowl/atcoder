#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;
// 使えるマッチ棒の数字 -> 作るのに必要な本数
map<int, int> costs;

// n: 残り本数 -> ret: 最大の本数
map<int, int> calc_order_memo{ {0, 1} };
int calc_order(int n) {
    if(calc_order_memo.count(n)) {
        return calc_order_memo[n];
    } else {
        // 本数を使い切らずに一番コストの低い数字を選択する
        int max_dst_n = -1;
        int max_result = -1;

        for(const auto& c: costs) {
            // cout << "[DEBUG] n=" << n << ", c=(" << c.first << ", " << c.second << ")" << endl;
            // つくれないので失敗
            if (c.second > n) {
                continue; 
            }
            // 作れるので再帰する
            auto dst_n = n - c.second;
            auto result = calc_order(dst_n);
            if(result > max_result) {
                max_dst_n = dst_n;
                max_result = result;
            }
        }
        if (max_result == -1) {
            return -1; // つくれない
        } else {
            calc_order_memo[n] = max_result + 1;
            return max_result + 1; // 桁数を一個足して返す
        }
    }
}

int main(void) {
    map<int, int> costs_src;
    costs_src[1] = 2;
    costs_src[2] = 5;
    costs_src[3] = 5;
    costs_src[4] = 4;
    costs_src[5] = 5;
    costs_src[6] = 6;
    costs_src[7] = 3;
    costs_src[8] = 7;
    costs_src[9] = 6;

    int n, m;
    cin >> n; // マッチ本数
    cin >> m; // 使える数字の種類
    for (int i = 0; i < m; ++i) {
        int an;
        cin >> an;
        costs[an] = costs_src[an];
    }
    for (const auto &c : costs) {
        cout << c.first << ", " << c.second << endl;
    }
    // 作れる最大の桁数を求める
    int order = calc_order(n);
    cout << order << endl;

    return 0;
}