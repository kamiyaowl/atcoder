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
    int n,q;
    cin >> n;
    cin >> q;
    string s;
    cin >> s;
    for(int i = 0 ; i < q ; ++i) {
        int l,r;
        cin >> l;
        cin >> r;

        int count = 0;
        for(int j = l - 1 ; j < r - 1; ++j) {
            if (s[j] == 'A' && s[j + 1] == 'C') {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}