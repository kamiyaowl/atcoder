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
#include <bitset>

namespace mp = boost::multiprecision;
using namespace std;

int main(void) {
    string s;
    cin >> s;
    
    int a = 0;
    int b = 0;
    for(int i = 0 ; i < s.length() ; ++i) {
        if(s[i] == '0') {
            if(i & 0x1) { ++a; }
            else { ++b; }
        } else {
            if(i & 0x1) { ++b; }
            else { ++a; }
        }
    }
    auto ans = min(a, b);
    cout << ans << endl;

    return 0;
}