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
    std::tuple<T, int> root_withrank(T a, int rank) {
        // 再帰する過程でつなぎ直す
        if(par[a] == a) return {a, rank};
        else {
            auto t = root_withrank(par[a], rank + 1);
            auto dst_root = std::get<0>(t);
            auto dst_rank = std::get<1>(t);
            par[a] = dst_root; // a-r間をすっ飛ばして根をつなぐ
            return {dst_root, dst_rank};
        }
    }
    void unite(T a, T b) {
        auto tuple_a = root_withrank(a, 0);
        auto tuple_b = root_withrank(b, 0);
        auto root_a = std::get<0>(tuple_a);
        auto root_b = std::get<0>(tuple_b);
        auto rank_a = std::get<1>(tuple_a);
        auto rank_b = std::get<1>(tuple_b);
        if (root_a != root_b) {
            if (rank_a < rank_b) {
                // aのほうが短いので、bにつけてあげる
                par[root_a] = root_b;
            } else {
                par[root_b] = root_a;
            }
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