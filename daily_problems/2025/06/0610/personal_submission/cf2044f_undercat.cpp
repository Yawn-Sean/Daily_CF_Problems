#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    long long suma = 0, sumb = 0;
    for (auto &i : a)
        cin >> i, suma += i;
    sort(a.begin(), a.end());
    for (auto &i : b)
        cin >> i, sumb += i;
    sort(b.begin(), b.end());
    // __int128 sum=suma*sumb;
    // sum-a[i]*sumb-b[j]*suma+a[i]*b[j]  ==  x
    // (suma-a[i])*(sumb-a[j]) == x
    set<long long> U, V;
    for (int i = 0; i < n; i++)
        U.insert(suma - a[i]);
    for (int j = 0; j < m; j++)
        V.insert(sumb - b[j]);
    while (q--){
        int x;
        cin >> x;
        bool ok = false;
        long long ax = llabs(x);
        for (long long d = 1; d * d <= ax; d++){
            if (ax % d)
                continue;
            long long e = ax / d;
            if (x > 0){
                if ((U.count(d) && V.count(e)) || (U.count(-d) && V.count(-e))){
                    ok = true;
                    break;
                }
                if (d != e && ((U.count(e) && V.count(d)) || (U.count(-e) && V.count(-d)))){
                    ok = true;
                    break;
                }
            }else{
                // x < 0 时，一正一负
                if ((U.count(d) && V.count(-e)) || (U.count(-d) && V.count(e))){
                    ok = true;
                    break;
                }
                if (d != e && ((U.count(e) && V.count(-d)) || (U.count(-e) && V.count(d)))){
                    ok = true;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}