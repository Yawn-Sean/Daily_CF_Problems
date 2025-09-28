#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    cin>>T;
    while (T--) {
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<int> A(N + 1);
        vector<int> cnt(M + 1, 0);
        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
            ++cnt[A[i]];
        }

        vector<int> oddpos;
        oddpos.reserve(M);
        for (int v = 1; v <= M; ++v)
            if (cnt[v] & 1) oddpos.push_back(v);

        long long K = 0;              
        vector<int> dist;             
        if (!oddpos.empty()) {
            dist.assign(M + 1, 0);
            for (int v = 1; v <= M; ++v) {
                auto it = lower_bound(oddpos.begin(), oddpos.end(), v);
                if (it != oddpos.end()) dist[v] = *it - v;             
                else dist[v] = oddpos[0] + M - v;                  
            }
        }

        while (Q--) {
            int type; 
            cin >> type;
            if (type == 1) {
                ++K; 
            } else {
                int i; 
                cin >> i;
                int v0 = A[i];
                int ans;
                if (oddpos.empty()) {
                    long long t = K % M;
                    ans = int((v0 - 1 + t) % M) + 1;
                } else {
                    long long step = K;
                    int d = dist[v0];              
                    if (step > d) step = d;
                    long long x = v0 + step;
                    if (x > M) x -= M;            
                    ans = int(x);
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}
