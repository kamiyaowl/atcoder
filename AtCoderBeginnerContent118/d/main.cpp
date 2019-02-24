#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

// メモ化再帰。コード汚いのは許して
vector<tuple<int, int>> costs;
mp::uint1024_t temp_max = 0;
int temp_order = 0;

// count: 残り本数
// current: 現在の数字
// order: 桁数
mp::uint1024_t calc_max(int count, mp::uint1024_t current, int order) {
    if(count == 0) {
        return current;
    } else if(count < 0) {
        return 0; // 失敗
    } else {
        for(const auto& c: costs) {
            auto num = get<0>(c);
            auto cost = get<1>(c);
            mp::uint1024_t next = (current * 10) + num; // 一番下の桁に挿入
            auto result = calc_max(count - cost, next, order + 1);
            if(temp_max < result) {
                temp_max = result;
                temp_order = order;
            }
        }
        return temp_max; // 一番大きい値が返るはず
    }
}

int main(void)
{
    mp::uint1024_t x;
    vector<tuple<int, int>> costs_src;
    costs_src.push_back(make_tuple(1, 2));
    costs_src.push_back(make_tuple(2, 5));
    costs_src.push_back(make_tuple(3, 5));
    costs_src.push_back(make_tuple(4, 4));
    costs_src.push_back(make_tuple(5, 5));
    costs_src.push_back(make_tuple(6, 6));
    costs_src.push_back(make_tuple(7, 3));
    costs_src.push_back(make_tuple(8, 7));
    costs_src.push_back(make_tuple(9, 6));

    int n, m;
    cin >> n; // マッチ本数
    cin >> m; // 使える数字の種類
    vector<int> a(m);
    for (int i = 0; i < m; ++i)
    {
        int an;
        cin >> an;
        a.push_back(an);
    }
    // 使えない数字は刈っておく
    copy_if(costs_src.begin(), costs_src.end(), back_inserter(costs), [a](tuple<int, int> t) {
        return count_if(a.begin(), a.end(), [&](int x) {
                   return get<0>(t) == x;
               }) > 0;
    });
    sort(costs.begin(), costs.end(), [](tuple<int,int> t1, tuple<int,int> t2){ 
        return get<1>(t2) !=  get<1>(t1) ? get<1>(t2) > get<1>(t1) : get<0>(t2) > get<0>(t1);
    });
    for(const auto& c: costs) {
        cout << get<0>(c) << ", " << get<1>(c) << endl;
    }
    auto result = calc_max(n, 0, 0);
    cout << result << endl;

    return 0;
}