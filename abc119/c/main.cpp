#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdbool.h>
#include <algorithm>

using namespace std;

vector<int> takes;
// diff: 作りたい残りの長さ(target-current)
// select_takes: 使った竹index -> 使用有無
//
// diff -> mp
map<int,int> synth_memo { {0, 0} };
map<int,map<int, bool>> synth_memo_select { {0, {}} };

int synth(int diff, map<int, bool> select_takes) {
    cout << "dbg: on synth(" << diff << ", ";
    for(const auto& s: select_takes) {
        cout << (s.second ? "1" : "0");
    }
    cout << ")" << endl;
    if(synth_memo.count(diff)){
        cout << "\tdbg: call synth(0, ...)" << endl;
        return synth_memo[diff];
    } else if (diff < 0) {
        // マイナスの場合はMP消費して削るしかない
        synth_memo[diff] = -diff;
        synth_memo_select[diff] = select_takes;
        cout << "\tdbg: return neg. mp:" << synth_memo[diff] << endl;
        return synth_memo[diff];
    } else {
        // プラスの場合、竹を選ぶかMPで埋めるかどっちか(竹合成はMP10)
        int min_index = -1;
        int min_mp = INT_MAX;
        bool is_initial = takes.size() == count_if(select_takes.begin(), select_takes.end(), [](pair<int,bool> p){ return !p.second; });

        int index = 0;
        for(const auto& t: takes) {
            if (select_takes[index]) continue;

            int dst_diff = diff - t;
            select_takes[index] = true;
            auto mp = synth(dst_diff, select_takes);
            select_takes[index] = false;

            // 2本目以降だとつなぐのに10MP
            if (!is_initial) {
                mp += 10;
            }

            // validation
            if (mp < min_mp) {
                min_index = index;
                min_mp = mp;
            }
            index++;
        }
        // 伸ばしたほうが良い場合、先に確定してしまう
        if (!is_initial && (min_mp == INT_MAX || ((diff - min_mp) > 10))) {
            synth_memo[diff] = diff;
            synth_memo_select[diff] = select_takes;
            cout << "\tdbg: return pos. mp:" << synth_memo[diff] << endl;
            return synth_memo[diff];
        }
        // 一番良さげな選択を返す
        if(min_index != -1){
            select_takes[min_index] = true;
            synth_memo[diff] = min_mp;
            synth_memo_select[diff] = select_takes;
            cout << "\tdbg: return sel. mp:" << synth_memo[diff] << ", select:" << min_index << endl;
            return synth_memo[diff];
        } else {
            // 失敗
            cout << "Not Implemented" << endl;
            exit(1);
        }
    }
}

int main(void) {
    int n;
    vector<int> targets(3);
    cin >> n;
    cin >> targets[0];
    cin >> targets[1];
    cin >> targets[2];

    map<int, bool> selected;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        takes.push_back(x);

        selected[i] = false;
    }
    auto result = synth(targets[0], selected);
    cout << result << endl;

    return 0;
}