#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n = 0): n(n), bit(n+1, 0) {}

    void add(int i, int v){
        for(++i; i <= n; i += i & -i)
            bit[i] += v;
    }

    int sumPrefix(int i){
        int s = 0;
        for(++i; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    int rsum(int l, int r){
        if(l > r) return 0;
        return sumPrefix(r) - (l ? sumPrefix(l-1) : 0);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    const int MAXB = 20;
    const int LIM = 1 << MAXB;

    vector<int> vis(LIM, 0);
    for(int x : nums) vis[x] = 1;

    vector<Fenwick> fens;
    for(int i = 0; i <= MAXB; ++i){
        int mod = 1 << (i + 1);
        vector<int> cnt(mod, 0);
        for(int j = 0; j < mod; ++j){
            for(int k = j; k < LIM; k += mod){
                cnt[j] += vis[k];
            }
        }
        Fenwick fw(mod);
        for(int j = 0; j < mod; ++j) fw.add(j, cnt[j]);
        fens.push_back(fw);
    }

    while(q--){
        int t, x;
        cin >> t >> x;

        if(t == 1){
            int dx = vis[x] ? -1 : 1;
            for(int i = 0; i <= MAXB; ++i){
                int mod = 1 << (i + 1);
                fens[i].add(x % mod, dx);
            }
            vis[x] ^= 1;
        }else{
            int ans = 0;
            for(int i = 0; i <= MAXB; ++i){
                int mod = 1 << (i + 1);
                int half = 1 << i;
                int l = (half - x % mod + mod) % mod;
                int r = l + half - 1;

                int cnt;
                if(r < mod){
                    cnt = fens[i].rsum(l, r);
                }else{
                    cnt = fens[i].rsum(l, mod-1) + fens[i].rsum(0, r - mod);
                }

                if(cnt & 1) ans |= half;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
