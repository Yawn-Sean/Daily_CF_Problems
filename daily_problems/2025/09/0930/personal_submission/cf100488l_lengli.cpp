#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, r; 
    cin >> n >> l >> r;

    string s; 
    cin >> s;

    vector<char> stk_left(s.begin(), s.begin() + (l - 1));
    vector<char> stk_right(s.begin() + r, s.end());
    deque<char>  que_mid(s.begin() + (l - 1), s.begin() + r);
    reverse(stk_right.begin(), stk_right.end()); // 右侧当作栈，末尾为栈顶

    int q; 
    cin >> q;

    int flg = 1; // 方向标记

    auto mid_push_from_left = [&](char v) {
        if (flg) que_mid.emplace_front(v);
        else     que_mid.emplace_back(v);
    };
    auto mid_push_from_right = [&](char v) {
        if (flg) que_mid.emplace_back(v);
        else     que_mid.emplace_front(v);
    };
    auto mid_pop_to_left = [&]() -> char {
        char v;
        if (flg) v = que_mid.front(), que_mid.pop_front();
        else     v = que_mid.back(),  que_mid.pop_back();
        return v;
    };
    auto mid_pop_to_right = [&]() -> char {
        char v;
        if (flg) v = que_mid.back(),  que_mid.pop_back();
        else     v = que_mid.front(), que_mid.pop_front();
        return v;
    };
    auto mid_peek = [&](char side) -> char {
        // side=='L' 看左端；受 flg 影响
        return ((side == 'L') == flg) ? que_mid.front() : que_mid.back();
    };

    while (q--) {
        char t; 
        cin >> t;

        if (t == 'Q') {
            char c; 
            cin >> c;
            cout << mid_peek(c);
        } 
        else if (t == 'R') {
            flg ^= 1;
        } 
        else {
            char c1, c2; 
            cin >> c1 >> c2;
            if (c1 == 'L') {
                if (c2 == 'L') {
                    char v = stk_left.back(); 
                    stk_left.pop_back();
                    mid_push_from_left(v);
                } else {
                    char v = mid_pop_to_left();
                    stk_left.emplace_back(v);
                }
            } else { // c1 == 'R'
                if (c2 == 'L') {
                    char v = mid_pop_to_right();
                    stk_right.emplace_back(v);
                } else {
                    char v = stk_right.back(); 
                    stk_right.pop_back();
                    mid_push_from_right(v);
                }
            }
        }
    }

    return 0;
}
