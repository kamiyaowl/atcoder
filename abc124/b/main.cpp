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

    int i;
    int highest = 0;
    int miss = 0;
    for(i = 0 ; i < n ; ++i) {
        int h;
        cin >> h;
        if (highest <= h) {
            highest = h;
        } else {
            miss++;
        }
    }
    cout << (n - miss) << endl;
    return 0;
}