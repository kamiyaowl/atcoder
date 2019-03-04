#include <iostream>
#include <vector>
#include<stdbool.h>

template<typename T>
struct union_find {
    std::vector<T> par; //[target_value] -> root_value

    union_find(int count) : par(count) {
        for(int i = 0 ; i < count ; ++i) {
            par[i] = i; // 自身がrootであるということで初期化
        }
    }
    T root(T a) {
        // 再帰する過程でつなぎ直す
        if(par[a] == a) return a;
        else {
            auto r = root(par[a]);
            par[a] = r; // a-r間をすっ飛ばして根をつなぐ
            return r;
        }
    }
    void unite(T a, T b) {
        auto root_a = root(a);
        auto root_b = root(b);
        if (root_a != root_b) {
            // bの集合をaにつける
            par[root_b] = root_a;
        }
    }
    bool is_same(T a, T b) {
        auto root_a = root(a);
        auto root_b = root(b);
        return root_a == root_b;
    }
};

using namespace std;

int main(void) {
    int n,q;
    cin >> n; // 頂点数
    cin >> q; // クエリ数

    union_find<int> uf(n);    
    for(int i = 0 ; i < q ; ++i) {
        int p, a, b;
        cin >> p; // 0なら連結、1なら判定してYes/Noを出力
        cin >> a;
        cin >> b;
        if (p) {
            cout << (uf.is_same(a, b) ? "Yes" : "No") << endl;
        } else {
            uf.unite(a, b);
        }
    }
    return 0;
}
