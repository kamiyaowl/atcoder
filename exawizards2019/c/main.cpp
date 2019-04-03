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



typedef enum Result {
    Left,Right,Exists,
};
Result solve(const vector<pair<char, int>>& magics, const string& src, int index) {
    for(const auto& magic: magics) {
        if (src[index] == magic.first) {
            index += magic.second;
        }
        if (index < 0) {
            return Result::Left;
        } else if(index >= src.length()) {
            return Result::Right;
        }
    }
    cout << "[DEBUG] index:" << index << endl; 
    return Result::Exists;
}
int bin_search_left(const vector<pair<char, int>>& magics, const string& src) {
    // 左からどこまで死んでるか求める
    int begin = 0;
    int end = src.length() - 1;
    Result result;
    while(begin != end) {
        int target = (end - begin) / 2;
        result = solve(magics, src, target);
        if(result == Result::Left) {
            if(begin == target) break;
            // 答えはもっと右
            begin = target;
        } else {
            if(end == target) break;
            end = target;
        }
    }
    // にぶたんで見つけられなかったら-1
    return result == Result::Left ? begin : -1;
}
int main(void) {
    int n; // マスの総数
    int q; // 呪文の数
    string s; // 各盤面のidentify
    cin >> n;
    cin >> q;
    cin >> s;

    vector<pair<char, int>> magics(q);
    for(int i = 0 ; i < q ; ++i) {
        char t; // 適用するマス
        char d; // 方向 L or R
        cin >> t;
        cin >> d;
        magics.push_back(make_pair(t, d == 'L' ? -1 : 1));
    }
    auto l = bin_search_left(magics, s);
    cout << l << endl;
    return 0;
}