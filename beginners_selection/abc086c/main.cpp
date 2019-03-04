#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>

using namespace std;
int main(void){
    int n;
    vector<tuple<int, int,int>> points; // time, x, y

    cin >> n;
    for(int i = 0 ; i < n ; ++i) {
        int t, x, y;
        cin >> t;
        cin >> x;
        cin >> y;
        points.push_back(make_tuple(t, x, y));
    }

    // start point
    points.push_back(make_tuple(0, 0, 0));
    n = points.size();

    // マンハッタン距離なので、どうとっても一緒
    for(int i = 0 ; i < n - 1 ; ++i) {
        auto& p1 = points[i];
        auto& p2 = points[i + 1];
        auto dt = abs(get<0>(p2) - get<0>(p1));
        auto dx = abs(get<1>(p2) - get<1>(p1));
        auto dy = abs(get<2>(p2) - get<2>(p1));
        auto distance = dx + dy;

        // 条件は2つ
        // 不可到達: dt < distance
        // その場にとどまれない->オーバーランする数が奇数
        if (dt < distance) {
            cout << "No" << endl;
            return 0;
        }
        auto overrun = distance - dt;
        if ((overrun % 2) != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}