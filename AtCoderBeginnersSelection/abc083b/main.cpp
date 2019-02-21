#include <iostream>
#include <cmath>
using namespace std;

int order_sum(int x) {
    int sum = 0;
    for(int i = 0 ; ; ++i) {
        int order = pow(10, i);
        int tmp = x / order;
        if(tmp == 0) break;
        int dst = tmp % 10;
        sum += dst;
        cout << "[DEBUB] " << dst << endl;
    }
    return sum;
}
int main(void){
    int n, a, b;
    cin >> n;
    cin >> a;
    cin >> b;

    int ans = 0;
    for(int i = 1 ; i <= n ; ++i) {
        int sum = order_sum(i);
        if (a <= sum && sum <= b) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}