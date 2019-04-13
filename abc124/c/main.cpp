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
#include <bitset>

namespace mp = boost::multiprecision;
using namespace std;

int count_bits(uint64_t x) {
    x = ((x & 0xaaaaaaaaaaaaaaaaUL) >> 1) 
      +  (x & 0x5555555555555555UL); 
    x = ((x & 0xccccccccccccccccUL) >> 2) 
      +  (x & 0x3333333333333333UL); 
    x = ((x & 0xf0f0f0f0f0f0f0f0UL) >> 4) 
      +  (x & 0x0f0f0f0f0f0f0f0fUL); 
    x = ((x & 0xff00ff00ff00ff00UL) >> 8) 
      +  (x & 0x00ff00ff00ff00ffUL); 
    x = ((x & 0xffff0000ffff0000UL) >> 16) 
      +  (x & 0x0000ffff0000ffffUL); 
    x = ((x & 0xffffffff00000000UL) >> 32) 
      +  (x & 0x00000000ffffffffUL); 
    return x; 
}
int main(void) {
    string s;
    cin >> s;
    const size_t length = s.length();
    uint64_t src = bitset<100000>(s).to_ullong();
    // 正解パターンは0スタート化0スタートの2種類しかない
    uint64_t ans_a = 0xaaaaaaaaaaaaaaaaUL & ~((~(uint64_t)0UL) << length);
    uint64_t ans_b = 0x5555555555555555UL & ~((~(uint64_t)0UL) << length);

    uint64_t a = ans_a ^ src;
    uint64_t b = ans_b ^ src;

    auto ans = min(count_bits(a), count_bits(b));
    cout << ans << endl;
    return 0;
}