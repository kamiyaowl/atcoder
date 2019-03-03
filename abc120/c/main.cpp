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

// 置換場所検索用
std::vector<int> find_all(const std::string str, const std::string subStr) {
    std::vector<int> result;
 
    int subStrSize = subStr.size();
    int pos = str.find(subStr);
 
    while (pos != std::string::npos) {
        result.push_back(pos);
        pos = str.find(subStr, pos + subStrSize);
    }
 
    return result;
}

map<string, int> reduce_memo { {"", 0} , {"1", 0}, {"0", 0}, };
int reduce(const string str) {
    // メモしてある結果
    if (reduce_memo.count(str) > 0) {
        // cout << "[dbg] mem_ret result:" << reduce_memo[str] << " " << str << endl;
        return reduce_memo[str];
    }
    // 取り除けそうな場所を列挙
    auto targets = find_all(str, "01");
    auto targets2 = find_all(str, "10");
    targets.insert(targets.end(), targets2.begin(), targets2.end());
    // なければ終了
    if (targets.size() == 0) {
        return 0;
    } else {
        // あれば一番いいところを採用
        int max_index = -1;
        int max_result = -1;
        // cout << "[dbg] targets.size():" << targets.size() << endl;

        set<string> calced;
        for(const int index: targets) {
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

        // 一番良い結果
        if (max_index < 0) {
            cout << "Not Implemented" << endl;
            return -1;
        }
        // メモって返す
        // cout << "[dbg] new_ret result:" << max_result << " " << str << endl;
        reduce_memo[str] = max_result;
        return max_result;
    }
}
int main(void) {
    string str;
    cin >> str;

    auto result = reduce(str);
    cout << result << endl;
    return 0;
}