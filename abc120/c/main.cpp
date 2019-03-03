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

using namespace std;

map<string, int> reduce_memo { {"", 0} , {"1", 0}, {"0", 0}, };
int reduce(const string str) {
    // メモしてある結果
    if (reduce_memo.count(str) > 0) {
        // cout << "[dbg] mem_ret result:" << reduce_memo[str] << " " << str << endl;
        return reduce_memo[str];
    }

    // 順番に検索
    set<string> calced;
    int max_index = -1;
    int max_result = -1;
    for(int last_index = 0; ;) {
        int index = str.find("01", last_index);
        if (index == string::npos) break;
        last_index = index + 1;

        string tmp(str);
        tmp.replace(index, 2, "");
        // すでにやった内容と一致している可能性があるので枝刈りする
        if(calced.count(tmp) > 0) {
            continue;
        }
        calced.insert(tmp);
        // いい結果を
        auto result = reduce(tmp) + 2;
        // cout << "\t[dbg] result:" << result << " " << str << " -> " << tmp << endl;
        if (max_result < result) {
            max_index = index;
            max_result = result;
        }
    }
    for(int last_index = 0; ;) {
        int index = str.find("10", last_index);
        if (index == string::npos) break;
        last_index = index + 1;

        string tmp(str);
        tmp.replace(index, 2, "");
        // すでにやった内容と一致している可能性があるので枝刈りする
        if(calced.count(tmp) > 0) {
            continue;
        }
        calced.insert(tmp);
        // いい結果を
        auto result = reduce(tmp) + 2;
        // cout << "\t[dbg] result:" << result << " " << str << " -> " << tmp << endl;
        if (max_result < result) {
            max_index = index;
            max_result = result;
        }
    }
    // 置換不可能
    if (max_index < 0) {
        return 0;
    }
    // メモって返す
    // cout << "[dbg] new_ret result:" << max_result << " " << str << endl;
    reduce_memo[str] = max_result;
    return max_result;
}
int main(void) {
    string str;
    cin >> str;

    auto result = reduce(str);
    cout << result << endl;
    return 0;
}