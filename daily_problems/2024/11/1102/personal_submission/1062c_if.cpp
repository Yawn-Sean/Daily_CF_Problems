#pragma Gcc optimize(3)
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod = 1e9 + 7;
long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}
void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int>cnt1(s.size(), 0);
    vector<int>cnt2(s.size(), 0);
    if(s[0] == '1'){
        cnt2[0] ++;
    }
    else{
        cnt1[0] ++;
    }
    for(int i = 1; i < s.size(); i ++){
        cnt2[i] += cnt2[i - 1];
        cnt1[i] += cnt1[i - 1];
        if(s[i] == '1'){
            cnt2[i] ++;
        }
        else{
            cnt1[i] ++;
        }
    }
    for(int i = 0; i < q; i++){
        int l ,r;
        int n1, n0;
        cin >> l >> r;
        if(l - 2 == -1){
            n1 = cnt2[r - 1];
            n0 = cnt1[r - 1];
        }
        else{
            n1 = cnt2[r - 1] - cnt2[l - 2];
            n0 = cnt1[r - 1] - cnt1[l - 2];
        } 
        
        ll ans = quickPow(2, n1, mod) - 1;
        ans += ans * (quickPow(2, n0 ,mod) - 1);
        ans %= mod;
        cout << ans << endl;

    }


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
