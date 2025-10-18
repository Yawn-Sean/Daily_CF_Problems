#include <bits/stdc++.h>
#define ll long long

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int gcd = 0;
    int MAX = 0;
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
        gcd = std::gcd(a[i],gcd);
        MAX = std::max(MAX,a[i]);
    }
    for(int i = 0; i < n; ++i){
        a[i] /= gcd;
    }

    std::vector<int> minPrim(MAX + 1);
    std::iota(minPrim.begin(),minPrim.end(),0);

    for(int i = 2; i <= MAX; ++i){
        if(minPrim[i] == i){
            for(int j = i;j <= MAX; j += i){
                minPrim[j] = i;
            }
        }
    }

    std::vector<bool> vis(MAX + 1);
    for(int i = 0; i < n; ++i){
        while(a[i] > 1){
            int mp = minPrim[a[i]];
            if(vis[mp]){
                std::cout << "NO\n";
                return;
            }
            vis[mp] = 1;
            while(a[i] % mp == 0) a[i] /= mp;
        }
    }
    std::cout << "YES\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int t;
    // std::cin >> t;
    // while(t--){
        solve();
    // }
    std::cout << std::flush;
    return 0;
}