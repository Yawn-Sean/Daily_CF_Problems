#include <bits/stdc++.h>
#define ll long long

void solve(){
    int a,b;
    std::cin >> a >> b;
    if((a | b) > a || (a && ((a & -a) == a) && b == 0)){
        std::cout << -1 << '\n';
        return;
    }
    std::vector<int> ans;
    int xor_val = b;
    for(int i = 0; i <= a; ++i){
        if((i | a) == a){
            ans.push_back(i);
            xor_val ^= i;
        }
    }
    int len = ans.size();
    if(!xor_val) xor_val = -1;
    else len--;
    std::cout << len << '\n';
    for(int i = 0; i < ans.size(); ++i){
        if(ans[i] != xor_val)
            std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        solve();
    }
    std::cout << std::flush;
    return 0;
}