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
    vector<int> arr(5);
    // 一番最後に端数の小さなものにする
    int lastMod = 100000;
    int lastIndex = -1;
    for(int i = 0 ; i < arr.size() ; ++i) {
        cin >> arr[i];

        int mod = arr[i] % 10;
        if (mod && lastMod > mod) {
            lastMod = mod;
            lastIndex = i;
        }
    }
    int sum = 0;
    for(int i = 0 ; i < arr.size() ; ++i) {
        if(lastIndex == i) {
            sum += arr[i];
        } else {
            int mod = arr[i] % 10;
            if (mod) {
                arr[i] += (10 - mod);
                
            }
            sum += arr[i];
        }
    }
    cout << sum << endl;
    return 0;
}