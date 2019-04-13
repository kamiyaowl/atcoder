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
    int a,b;
    cin >> a >> b;
    auto result = max(a + a - 1, max(a + b, b + b - 1));
    cout << result << endl;
    return 0;
}