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
    for(int i = 0 ; i < 5 ; ++i) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    // 総当たり
    for(int i = 0 ; i < arr.size() ; ++i) {
        for(int j = 0 ; j < arr.size() ; ++j) {
            int d = abs(arr[i] - arr[j]);
            if(d > k) {
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    cout << "Yay!" << endl;
    return 0;
}