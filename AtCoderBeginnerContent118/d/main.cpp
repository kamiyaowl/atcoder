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

// n: 残り本数 -> ret: (最大の本数, 使った数字履歴)
map<int, int> calc_order_memo{ {0, 1} }; // n->桁数: 0本で使い切ったときは終了条件なので1本としておく
map<int, mp::cpp_int> calc_num_memo{ {0, 0} }; // n->使った数字をメモしておきたい

tuple<int, mp::cpp_int> calc_order(int n) {
    if(calc_order_memo.count(n)) {
        return { calc_order_memo[n], calc_num_memo[n] };
    } else {
        // 本数を使い切らずに一番コストの低い数字を選択する
        int max_result = -1; // 帰ってきた桁数で最大の藻を
        int select_n = -1; // max_result時にこのCall上で選んだ数字
        mp::cpp_int max_num = -1; // 帰ってきた関数の具体的な数値

        for(const auto& c: costs) {
            // cout << "[DEBUG] n=" << n << ", c=(" << c.first << ", " << c.second << ")" << endl;
            // つくれないので失敗
            if (c.second > n) {
                continue; 
            }
            // 作れるので再帰する
            auto t = calc_order(n - c.second);
            auto result = get<0>(t);
            auto num = get<1>(t);

            if(result > max_result) {
                max_result = result;
                select_n = c.first;
                max_num = num;
            }
        }
        if (max_result == -1) {
            return { -1, 0 }; // つくれない
        } else {
            calc_order_memo[n] = max_result + 1; // 桁数
            calc_num_memo[n] = (max_num * 10) + select_n; // 使った数字+これまでの桁を足しておく
            cout << "[DEBUG] ret {" << calc_order_memo[n] << ", " << calc_num_memo[n] << "}" << endl;

            return { calc_order_memo[n], calc_num_memo[n] }; // 桁数を一個足して返す
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
    auto r = calc_order(n);
    auto order = get<0>(r);
    auto num = get<1>(r);
    cout << "order: " << order << ", num:" << num << endl;

    return 0;
}