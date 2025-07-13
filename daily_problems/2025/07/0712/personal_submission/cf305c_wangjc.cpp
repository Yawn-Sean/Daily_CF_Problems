#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve(){
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        auto it = mp.find(x);
        while (it != mp.end() && it -> second > 1) {
            int y = it -> first + 1;
            mp[y] += it -> second / 2;
            it -> second %= 2;
            it++;
        }
    }
    auto it = --mp.end();
    int ans = it -> first;
    for (auto it2 = mp.begin(); it2 != --mp.end(); it2++) {
        if (it2 -> second > 0) {
            ans--;
        }
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
