#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <set>
#include <tuple>
#include <stdbool.h>
#include <bitset>
#include <string>

using namespace std;

// 左から順に処理
tuple<int, string> reduce1(string str) {
    int count = 0;
    for(int last_index = 0; ;) {
        cout << str<< endl;
        int index1 = str.find("01", last_index);
        int index2 = str.find("10", last_index);
        if (index1 != string::npos && index2 == string::npos) {
            str.replace(index1, 2, "");
            last_index = index1;
        } else if (index2 != string::npos && index1 == string::npos) {
            str.replace(index2, 2, "");
            last_index = index1;
        } else if (index1 != string::npos && index1 < index2) {
            str.replace(index1, 2, "");
            last_index = index1;
        } else if (index2 != string::npos && index2 < index1) {
            str.replace(index1, 2, "");
            last_index = index1;
            count++;
        } else {
            break;
        }
    }
    return {count * 2, str};
}
int reduce2(string str) {
    int sum = 0;
    int score = 0;

    string dst;
    dst = str;
    do {
        // cout << "#####################" << endl;
        auto t = reduce1(dst);
        score = get<0>(t);
        dst = get<1>(t);
        sum += score;

    } while(score > 0);
    return sum;
}
int main(void) {
    string str;
    cin >> str;

    auto result = reduce2(str);
    cout << result << endl;
    return 0;
}