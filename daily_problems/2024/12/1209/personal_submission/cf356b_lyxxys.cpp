#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    long long n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int k1 = s.size(), k2 = t.size();
    int g = __gcd(k1, k2);
    long long cnt = 0;
    for (int i = 0; i < g; ++ i){
        map <char,int> mps;
        for (int j = i; j < k1; j += g){
            mps[s[j]] += 1;
        }
        for (int j = i; j < k2; j += g){
            cnt += mps[t[j]];
        }
    }

    cout << (n*k1 - __gcd(n,m)*cnt) << "\n";
}
