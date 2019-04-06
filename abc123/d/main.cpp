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


// label: a=0, b=1, c=2
void insert(map<mp::cpp_int, vector<int>>& cakes, int n, int label) {
    for(int i = 0 ; i < n ; ++i) {
        mp::cpp_int v;
        cin >> v;
        if(!cakes.count(v)) {
            cakes[v] = vector<int>(3);
            cakes[v][0] = 0;
            cakes[v][1] = 0;
            cakes[v][2] = 0;
        }
        cakes[v][label]++;
    }
}
int main(void) {
    int x,y,z;
    mp::cpp_int count;
    cin >> x;
    cin >> y;
    cin >> z;
    cin >> count;

    map<mp::cpp_int, vector<int>> cakes;
    insert(cakes, x, 0);
    insert(cakes, y, 1);
    insert(cakes, z, 2);

    mp::cpp_int now_count = 0;
    auto e = cakes.rend();
    for(auto i = cakes.rbegin() ; i != e ; ++i) {
        // select a
        while (i->second[0]) {
            mp::cpp_int sum = 0;
            i->second[0]--;
            sum += i->first;
            cout << "sel a sum:" << sum << " num:" << i->first << endl;
            // select b
            for(auto j = cakes.rbegin() ; j != e ; ++j) {
                while (j->second[1]) {
                    j->second[1]--;
                    sum += j->first;
                    cout << "sel b sum:" << sum << " num:" << j->first << endl;
                    // select c
                    for(auto k = cakes.rbegin() ; k != e ; ++k) {
                        while (k->second[2]) {
                            k->second[2]--;
                            sum += k->first;
                            cout << "sel c sum:" << sum << " num:" << k->first << endl;
                            cout << sum << endl;
                            // increment and halt
                            now_count++;
                            if(count <= now_count) {
                                return 0;
                            }
                            sum -= k->first;
                        }
                    }
                    // c
                    sum -= j->first;
                }
            }
            // b
        }
        // a
    }
    return 0;
}