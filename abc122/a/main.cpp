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
    char c;
    cin >> c;
    switch (c) {
        case 'A':
            cout << "T" << endl;
            break;
        case 'C':
            cout << "G" << endl;
            break;
        case 'G':
            cout << "C" << endl;
            break;
        case 'T':
            cout << "A" << endl;
            break;
    }
    return 0;
}