#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a, b, c;
    cin >> a >> b >> c;
    map <char, int> mpa, mpb, mpc;

    for (auto &ch : a) ++ mpa[ch];
    for (auto &ch : b) ++ mpb[ch];
    for (auto &ch : c) ++ mpc[ch];

    int minb = 1e9, minc = 1e9;
    for (auto &[ch, cnt] : mpb){
        minb = min(minb, mpa[ch]/cnt);
    }
    for (auto &[ch, cnt] : mpc){
        minc = min(minc, mpa[ch]/cnt);
    }

    array<int,2> ans = {};
    if (minb > minc){
        for (int i = 0; i <= minb; ++ i){
            minc = 1e9;
            for (auto &[ch, cnt] : mpc){
                minc = min(minc, (mpa[ch]-i*mpb[ch])/cnt);
            }
            if (i+minc > ans[0]+ans[1]) ans[0] = i, ans[1] = minc;
        }
    } else {
        for (int i = 0; i <= minc; ++ i){
            minb = 1e9;
            for (auto &[ch, cnt]: mpb){
                minb = min(minb, (mpa[ch]-i*mpc[ch])/cnt);
            }
            if (minb+i > ans[0]+ans[1]) ans[0] = minb, ans[1] = i;
        }
    }
    string res;
    for (int i = 0; i < ans[0]; ++ i) res += b;
    for (int i = 0; i < ans[1]; ++ i) res += c;
    for (auto &[ch, cnt] : mpb) mpa[ch] -= ans[0]*cnt;
    for (auto &[ch, cnt] : mpc) mpa[ch] -= ans[1]*cnt;
    for (auto &[ch, cnt] : mpa){
        for (int i = 0; i < cnt; ++ i) res += ch;
    }

    cout << res << "\n";
}
