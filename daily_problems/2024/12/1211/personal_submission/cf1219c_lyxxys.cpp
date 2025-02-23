#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    auto create = [&](int n)->string{
        string ans("1");
        n -= 1;
        while (n--) ans += '0';
        return ans;
    };
    int L;
    string s;
    cin >> L;
    cin >> s;

    int n = s.size();
    string res;
    if (n%L){
        int cnt = (n+L-1)/L;
        while (cnt--) res += create(L);
    } else {
        int cnt = n/L;
        if (string(n, '9') == s){ // 99999··· 特判
            cnt += 1;
            while (cnt--) res += create(L);
        } else {
            string t = s.substr(0, L);
            bool jg = 0;
            for (int i = L; i < n; ++ i){
                if (t[i%L] == s[i]) continue;
                jg = t[i%L] > s[i];
                break;
            }
            if (!jg){
                for (int i = L-1, cur = 1; i >= 0; -- i){
                    cur += t[i]-'0';
                    if (cur < 10){
                        t[i] = char(int(t[i])+1);
                        break;
                    } else {
                        assert(cur == 10);
                        t[i] = '0';
                        cur /= 10;
                    }
                }
            }
            while (cnt--) res += t;
        }
    }

    cout << res << "\n";
}
