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

// 左にあるbの数>wの数であればbwをデクリメントして

int replace(string& s) {
    int b = 0; // 現時点より左にある#の数
    int count = 0;
    for(int i = 0 ; i < s.length() ; ++i) {
        if (s[i] == '#') {
            b++;
            if (s[i + 1] == '.') {
                // #.なので処置が必要。
                if(b < 2) {
                    // ここより左はbがなさそうなので、i-1をb->wにする
                    s[i - 1] = '.';
                    count++;
                    // ..になるのでこれより後ろはbに怯えないためクリア
                    b = 0;
                } else {
                    //###.....みたいなパターン。最寄りのbかwどちらかが消えるまで置き換えが必要？
                    int j;
                    for(j = i + 1 ; (j < s.length()) && (s[j] == '.') ; ++j) {}
                    int w = j - (i + 1); // 右にあるwの数
                    if (b < w) {
                        // 手前のbすべてwに変更
                        count += b;
                        b = 0;
                    } else {
                        // この後の連続するwをbに変更
                        count += w;
                        b += w; // 黒が増えるので注意
                    }
                    // すすめる
                    i = j - 1; // increment文を引いておく
                }
            }
        } else {
            // .なのでbをクリア
            b = 0;
        }
    }
    return count;
}
int main(void) {
    int n;
    string s; // '#' or '.'
    cin >> n >> s;

    // 短い場合
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    } else if(n == 2) {
        cout << ((s[0] == '#' && s[1] == '.') ? 1 : 0) << endl;
        return 0;
    }

    // result
    auto result = replace(s);
    cout << result << endl;

    return 0;
}