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

using namespace std;

unsigned gcd(unsigned a, unsigned b) {
  if(a < b) gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main(void) {
    int a,b,k;
    cin >> a;
    cin >> b;
    cin >> k;

    auto x = gcd(a, b);
    // cout << x << endl;
    vector<int> dst;
    for(int i = 1 ; i <= x ; ++i) {
        if ((x % i) == 0){
            dst.push_back(i);
        }
    }
    cout << dst[dst.size() - k] << endl;
    return 0;
}