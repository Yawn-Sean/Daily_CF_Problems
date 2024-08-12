#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1505, mod = 1e9 + 7, inf = 1e9;
int f[N][26], fs[N][26], fsum[N][26];
/*
    f[p][u]表示最多修改p次，字母u的最大连续长度
*/
void solve(){
    int n, m;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    for (int p = 1; p <= n; ++ p){
        for (int u = 'a'; u <= 'z'; ++ u){
            for (int i=1,j=0,sum=0; i <= n; ++ i){
                while (j+1 <= n && sum < p || j+1 <= n && s[j+1]==u){
                    sum += s[j+1] != u;
                    ++ j;
                }
                f[p][u-'a'] = max(f[p][u-'a'], j-i+1);
                sum -= s[i] != u;
            }
        }
    }

    cin >> m;
    while (m--){
        int len;
        char ch;
        cin >> len >> ch;
        cout << f[len][ch-'a'] << "\n";
    }
}
