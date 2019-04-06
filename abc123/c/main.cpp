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

    vector<int> arr(5);
    vector<int> term(5);
    int result = -1;
    // それぞれなんターン必要？
    for(int i = 0 ; i < 5 ; ++i) {
        cin >> arr[i];
        term[i] = (n / arr[i]) + ((n % arr[i]) == 0 ? 0 : 1) + i; // iは人間が隣町に移動するターンオフセット
        if (term[i] > result) {
            result = term[i];
        }
    }
    cout << result << endl;
    return 0;
}