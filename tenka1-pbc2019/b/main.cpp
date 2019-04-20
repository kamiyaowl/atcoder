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


int main(void) {
    int n,k;
    string s;
    cin >> n >> s >> k;

    auto target = s[k - 1];
    for(const auto& c : s) {
        cout << (c == target ? c : '*');
    }
    cout << endl;
    return 0;
}