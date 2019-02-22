#include<iostream>
#include<string>
#include<array>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
    array<string, 4> words;
    words[0] = "dreamer";
    words[1] = "eraser";
    words[2] = "dream";
    words[3] = "erase";

    string s;
    cin >> s;
    // 後ろから全て処理すればいいのでは
    for(auto& w : words){
        reverse(w.begin(), w.end());
    }
    reverse(s.begin(), s.end());

    while(s.length() > 0) {
        auto currentLen = s.length();
        for(const auto& w: words) {
            auto target = s.substr(0, w.length());
            if(w == target) {
                s.replace(0, w.length(), "");
                break;
            }
        }
        if (currentLen == s.length()) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}