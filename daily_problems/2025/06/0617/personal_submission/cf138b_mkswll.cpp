#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> cnt(10, 0);
    for(auto i : s) cnt[i - '0']++;
    int mx = cnt[0];
    int dig = 0;
    for(int i = 1; i <= 5; ++i) {
        if(cnt[i] && cnt[10 - i]) {
            auto acnt = cnt, bcnt = cnt;;
            --acnt[i];
            --bcnt[10 - i];
            int cur = 1;
            for(int j = 0; j <= 9; ++j) {
                int t = min(acnt[j], bcnt[9 - j]);
                acnt[j] -= t;
                bcnt[9 - j] -= t;
                cur += t;
            }
            cur += min(acnt[0], bcnt[0]);
            if(cur > mx){
                mx = cur;
                dig = i;
            }
        }
    }
    if(mx == cnt[0]) {
        sort(s.rbegin(), s.rend());
        cout << s << "\n";
        cout << s << "\n";
        return 0;
    }
    string ansa = "", ansb = "";
    auto acnt = cnt, bcnt = cnt;;
    --acnt[dig];
    --bcnt[10 - dig];
    ansa += (char) ('0' + dig);
    ansb += (char) ('0' + 10 - dig);
    for(int j = 0; j <= 9; ++j) {
        int t = min(acnt[j], bcnt[9 - j]);
        acnt[j] -= t;
        bcnt[9 - j] -= t;
        ansa += string(t, '0' + j);
        ansb += string(t, '0' + 9 - j);
    }
    int tz = min(acnt[0], bcnt[0]);
    acnt[0] -= tz;
    bcnt[0] -= tz;
    for(int i = 0; i <= 9; ++i) for(int j = 1; j <= acnt[i]; ++j) ansa += (char) ('0' + i);
    for(int i = 0; i <= 9; ++i) for(int j = 1; j <= bcnt[i]; ++j) ansb += (char) ('0' + i);
    reverse(ansa.begin(), ansa.end());
    reverse(ansb.begin(), ansb.end());
    ansa += string(tz, '0');
    ansb += string(tz, '0');
    cout << ansa << "\n" << ansb << "\n";
}