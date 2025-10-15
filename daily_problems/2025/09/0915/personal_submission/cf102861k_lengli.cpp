/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int P, F;
    std::cin>>P>>F;

    std::vector<std::vector<int>> adj(P);
    for (int i = 0; i < F; ++i) {
        int A, B; 
        std::cin>>A>>B;
        A--,B--;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    std::vector<std::bitset<205>> mat(P);

    for (int i = 0; i < P; ++i) {
        if ((int)adj[i].size() % 2 == 0) {
            for (int v : adj[i]) mat[i].set(v);
            mat[i].set(P); 
        } else {
            mat[i].set(i);
            for (int v : adj[i]) mat[i].set(v);
        }
    }

    int row = 0;
    for (int col = 0; col < P && row < P; ++col) {
        int sel = -1;
        for (int r = row; r < P; ++r) {
            if (mat[r].test(col)) { sel = r; break; }
        }
        if (sel == -1) continue;
        swap(mat[row], mat[sel]);
        for (int r = 0; r < P; ++r) {
            if (r != row && mat[r].test(col)) {
                mat[r] ^= mat[row];
            }
        }
        ++row;
    }

    for (int r = row; r < P; ++r) {
        bool allZero = true;
        for (int c = 0; c < P; ++c) {
            if (mat[r].test(c)) { allZero = false; break; }
        }
        if (allZero && mat[r].test(P)) {
            std::cout << 'N' << '\n';
            return;
        }
    }
    std::cout << 'Y' << '\n';
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
