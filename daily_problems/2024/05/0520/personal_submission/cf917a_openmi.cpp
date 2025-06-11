// 去除多余思考，无需考虑 ？？？） 是否有()(), (())这两种情况
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    long long ans = 0;

    rep (l, 0, n) {
        int cur = 0, q = 0;
        rep (r, l, n) {
            if (s[r] == '(') cur += 1;
            else if (s[r] == ')') cur -= 1;
            else cur -= 1, q += 1;
            
            if (cur < 0 and q > 0) cur += 2, q -= 1;
            if (cur < 0) break;
            if (r - l & 1 and cur == 0) {
                ans += 1;
            }
        }
    }
    cout << ans << nl;
}
/*
cur表示当前值，q表示可转变的数量；
cur与q一起判断是否correct；
先出现的cur==0时第一个？必是 (;

wrong ????)( 待头脑清醒思考
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    long long ans = 0;
 
    rep (l, 0, n) {
        int cur = 0, q = 0;
        rep (r, l, n) {
            if (s[r] == '(') cur += 1;
            else if (s[r] == ')') cur -= 1;
            else q += 1;
 
            if (cur + q < 0) break;
            if (cur == 0 and q & 1) cur = 1, q -= 1; // ?( 情况
            if (r - l + 2 & 1 and cur - q <= 0) {
                ans += 1;
            }
        }
    }
    cout << ans << nl;
}
貌似思路类似的正解 yefei162
# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()

s = input()
n = len(s)
tot = 0
for i in range(n):
    a, b = 0, 0
    for j in range(i, n):
        if s[j] == '(':
            a += 1
        elif s[j] == ')':
            a -= 1
        else:
            b += 1
        if a + b < 0:
            break
        if b > a:
            a, b = b, a
        if a == b:
            tot += 1
print(tot)
*/
