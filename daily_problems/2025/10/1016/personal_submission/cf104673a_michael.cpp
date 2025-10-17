#include <bits/stdc++.h>
#define ll long long

std::map<int,int> m;
int MAX = 1e9;

void init(){
    for(int i = 50000; i >= 0; --i){
        ll val = 1;
        for(int j = 0; j <= i; ++j){
            if(val > MAX) break;
            m[val] = i + 1;
            val = val * (i - j) / (j + 1);
        }
    }
}

void solve(){
    int t;
    std::cin >> t;
    while(t--){
        int x;
        std::cin >> x;
        if(m.find(x) == m.end()){
            std::cout << x + 1 << '\n';
        }else{
            std::cout << m.find(x) -> second << '\n';
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int t;
    // std::cin >> t;
    // while(t--){
        init();
        solve();
    // }
    std::cout << std::flush;
    return 0;
}