#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;

int h, w;
vector<vector<char>> map;

bool dfs(int x, int y){
    // out of map
    if (x < 0 || y < 0 || x >= w || y >= h) return false;
    switch(map[y][x]){
        case 'g':
            return true;
        case '#':
        case 'x':
            return false;
        case 's':
        case '.':
            // 探索済
            map[y][x] = 'x';
            // 4方向に広げる
            if (dfs(x + 1, y    )) return true;
            if (dfs(x - 1, y    )) return true;
            if (dfs(x    , y + 1)) return true;
            if (dfs(x    , y - 1)) return true;
            // だめ
            return false;
    }
}

int main(void){
    cin >> h;
    cin >> w;

    int sx,sy;
    // s - start
    // g - goal
    // # - wall
    // . - empty
    // x - walked
    map = vector<vector<char>>(h, vector<char>(w, '#'));
    for(int j = 0 ; j < h ; ++j){
        for(int i = 0 ; i < w ; ++i){
            char c;
            cin >> c;
            map[j][i] = c;
            if(c == 's'){
                sx = i;
                sy = j;
            }
        }
    }
    if (dfs(sx, sy)) {
        cout <<  "Yes" << endl;
    }  else {
        cout << "No" << endl;
    }
    return 0;
}