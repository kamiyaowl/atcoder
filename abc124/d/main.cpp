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

// 領域数量を数える
vector<pair<int, bool>> count(const vector<bool>& src) {
    vector<pair<int, bool>> dst;

    bool label = false;
    int count = 0;
    
    bool reset = true;
    for(const auto& s : src) {
        if(reset) {
            label = s;
            count = 1;
            reset = false;
        } else {
            if(s != label) {
                // 途切れる
                dst.push_back(make_pair(count, label));
                label = s;
                count = 1;
                reset = false;
            } else {
                // 継続
                count++;
            }
        }
    }
    // 最後のラベル
    dst.push_back(make_pair(count, label));

    return move(dst);
}

// 一番大きくなるようにひっくり返せるように探せ
pair<int,int> search_greedy(const vector<pair<int, bool>>& src) {
    bool start = src[0].second; // falseだけ舐めたい
    int loop = src.size() / 2;

    int max_index = -1;
    int max_count = 0;
    for(int i = 0 ; i < loop; ++i) {
        int index = (i * 2) + (start ? 1 : 0);

        int count_before = (index > 0) ? src[index - 1].first : 0;
        int count_now = src[index].first; // ひっくり返されて加算
        int count_after = index < (src.size() - 1) ? src[index + 1].first : 0;
        int count = count_before + count_now + count_after; // ひっくり返されたときの特典

        if (max_count < count) {
            max_count = count;
            max_index = index;
        }
    }
    if (max_index > -1) {
        return make_pair(max_index, max_count); // ここが良さ麻生
    } else {
        return make_pair(-1, 0); // ない
    }
}
void flip(vector<pair<int, bool>>& src, int index) {
    if(index < 0 || index > src.size() - 1) {
        return;
    }
    int count = src[index].first;
    bool label = !src[index].second;
    // まわり
    if (index < src.size() - 1) {
        count += src[index+1].first;
        src.erase(src.begin() + index+1);
    }
    if (index > 0) {
        count += src[index-1].first;
        src.erase(src.begin() + index-1);
        // 手前にしないと参照が死ぬ
        index--;
    }
    // update
    src[index] = make_pair(count, label);
}

// 一番でかいのはどれ
int search_max(const vector<pair<int, bool>>& labels){
    int result = 0;
    for(const auto& l : labels) {
        if(!l.second) continue; // falseは除外

        if(result < l.first) {
            result = l.first;
        }
    }
    return result;
}
int flip_greedy(vector<pair<int, bool>>& labels, int k) {
    int count = 0;
    for(int i = 0 ; i < k ; ++i) {
        auto target = search_greedy(labels);
        if (target.first == -1) {
            if (i == 0) {
                // 一番大きいところを返す
                return search_max(labels);
            } else {
                return target.second; // もう動かすところがない
            }
        }
        count = target.second;
        flip(labels, target.first);
    }
    return count;
}

int main(void) {
    int n,k;
    string s;
    cin >> n >> k >> s;
    // k回の領域反転でsの1の数を増やす
    vector<bool> src;
    for(const auto c : s) {
        src.push_back(c == '1');
    }
    auto labels = count(src);
    auto result = flip_greedy(labels, k);
    cout << result << endl;
    return 0;
}