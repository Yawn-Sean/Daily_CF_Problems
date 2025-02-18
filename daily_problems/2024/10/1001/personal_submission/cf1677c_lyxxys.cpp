#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> A(n), B(n), p(n), ps(n), vis(n);
    for (int i = 0; i < n; ++ i) cin >> A[i], A[i] -= 1;
    for (int i = 0; i < n; ++ i) cin >> B[i], B[i] -= 1, ps[B[i]] = i;
    for (int i = 0; i < n; ++ i){
        p[i] = ps[A[i]];
    }

    long long k = 0;
    for (int i = 0; i < n; ++ i){
        if (vis[i]) continue;
        int cur = i;
        int c = 0;
        while (!vis[cur]){
            vis[cur] = 1;
            cur = p[cur];
            c += 1;
        }
        k += c/2;
    }

    cout << 2*k*(n-k) << "\n";
}
 
