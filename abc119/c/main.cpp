#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <stdbool.h>
#include <bitset>

using namespace std;

vector<int> takes;
// diff: 作りたい残りの長さ(target-current)
// select_takes: 使った竹index -> 使用有無
//
// diff -> mp
map<int,int> synth_memo { {0, 0} };
map<int, int> synth_memo_select { { 0, 0 } }; // bitmaskで管理する

tuple<int,int> synth(int diff, int select_takes, bool is_initial) {
    // cout << "\tdbg: on synth(" << diff << ", " << select_takes << ")" << endl;
    if(synth_memo.count(diff)){
        // cout << "\t\tdbg: call synth(0, ...)" << endl;
        return {synth_memo[diff], synth_memo_select[diff] };
    } else if (diff < 0) {
        // マイナスの場合はMP消費して削るしかない
        synth_memo[diff] = -diff;
        synth_memo_select[diff] = select_takes;
        // cout << "\t\tdbg: return neg. mp:" << synth_memo[diff] << endl;
        return { synth_memo[diff], synth_memo_select[diff] };
    } else {
        // 伸ばしたほうが良い場合、先に確定してしまう
        if (!is_initial && ((diff <= 10))) {
            synth_memo[diff] = diff;
            synth_memo_select[diff] = select_takes;
            // cout << "\t\tdbg: return pos. mp:" << synth_memo[diff] << endl;
            return { synth_memo[diff], synth_memo_select[diff] };
        }

        // プラスの場合、竹を選ぶかMPで埋めるかどっちか(竹合成はMP10)
        int min_index = -1;
        int min_mp = INT_MAX;
        int min_mask = 0;

        int index = 0;
        for(const auto& t: takes) {
            if (select_takes & (1 << index)) {
                index++;
                continue;
            }

            int dst_diff = diff - t;
            auto x = synth(dst_diff, select_takes | (1 << index), false);
            auto mp = get<0>(x);
            auto mask = get<1>(x);
            // 2本目以降だとつなぐのに10MP
            if (!is_initial) {
                mp += 10;
            }

            // validation
            if (mp < min_mp) {
                min_index = index;
                min_mp = mp;
                min_mask = mask;
            }
            index++;
        }
        // 一番良さげな選択を返す
        if(min_index != -1){
            select_takes |= (1 << min_index);
            synth_memo[diff] = min_mp;
            synth_memo_select[diff] = select_takes | min_mask;
            // cout << "\t\tdbg: return sel. mp:" << synth_memo[diff] << ", select:" << min_index << " select_takes:" << select_takes << endl;
            return { synth_memo[diff], synth_memo_select[diff] };
        } else {
            // 失敗
            cout << "Not Implemented" << endl;
            exit(1);
        }
    }
}
int get_min_mp(const vector<int>& targets) {
    int result = INT_MAX;
    // j: どれから求めるか
    for(int j = 0 ; j < targets.size() ; ++j) {
        // i: 今計算中のやつ(% sizeして)
        int current_mp = 0;
        int current_mask = 0;
        for(int i = 0 ; i < targets.size() ; ++i) {
            // clear memo
            synth_memo.clear();
            synth_memo_select.clear();
            synth_memo[0] = 0;
            synth_memo_select[0] = 0;

            auto index = (j + i) % targets.size();
            auto x = synth(targets[index], current_mask, true);
            // cout << "\tdbg: index:" << index << "\tmp:" << get<0>(x) << "\tmask:" << bitset<8>(get<1>(x)) << "\tmask_diff:" << bitset<8>(current_mask ^ get<1>(x)) << endl;
            current_mp += get<0>(x);
            current_mask = get<1>(x);
        }
        // cout << "dbg: j:" << j << "\tmp:" << current_mp << "\tmask:" << current_mask << endl;
        if (result > current_mp) {
            result = current_mp;
        }
    }
    return result;
}
int main(void) {
    int n;
    vector<int> targets(3);
    cin >> n;
    cin >> targets[0];
    cin >> targets[1];
    cin >> targets[2];

    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        takes.push_back(x);
    }
    // cout << "dbg: start" << endl;
    auto x = get_min_mp(targets);
    cout << x << endl;

    return 0;
}