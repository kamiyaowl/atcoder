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
int main(void) {
    int a,b,c;
    cin >> a; // 一回あたりの価格
    cin >> b; // 持ってる価格
    cin >> c; // upper limit

    auto max = b / a;
    if (max > c) {
        cout << c << endl;
    } else  {
        cout << max << endl;
    }
    return 0;
}