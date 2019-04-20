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
    cin >> a >> b >> c;
    auto ans = (a < b && c < b && a < c) || (a > b && c > b && c < a);
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}