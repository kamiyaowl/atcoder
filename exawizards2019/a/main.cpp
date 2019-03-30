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
    int a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;
    if (
        (a == b ) &&
        (b == c ) &&
        (c == a )
    ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}