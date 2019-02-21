#include<iostream>

using namespace std;

int main(void) {
    int n;
    int y;
    cin >> n;
    cin >> y;

    for(int i = 0 ; i <= n ; ++i) {
        for(int j = 0 ; (i + j) <= n ; ++j) {
            for (int k = 0 ; (i + j + k) <= n ; ++k) {
                if ((i + j + k) < n) continue;
                int sum = (i * 1000 + j * 5000 + k * 10000);
                if (sum == y) {
                    cout << k << " " << j << " " << i << endl;
                    return 0;
                } else if(sum > y) {
                    break;
                }
            }

        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}