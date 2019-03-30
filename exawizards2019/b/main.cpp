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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int r = 0, b = 0;
    for(const auto& c : s) {
        switch(c) {
            case 'R':
                r++;
                break;
            case 'B':
                b++;
                break;
        }
    }
    if (r > b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}