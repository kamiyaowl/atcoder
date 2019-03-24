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
    string src;
    cin >> src;

    bool invalid = false;
    int result = 0;
    int count = 0;
    for(const auto& c: src) {
        switch(c) {
            case 'A':
            case 'C':
            case 'G':
            case 'T':
                invalid = false;
                count++;
                break;
            default:
                if (!invalid) {
                    if(result < count) {
                        result = count;
                        count = 0;
                    }
                }
                invalid = true;
                break;
        }
    }
    if (!invalid) {
        if(result < count) {
            result = count;
        }
    }
    cout << result << endl;
    return 0;
}