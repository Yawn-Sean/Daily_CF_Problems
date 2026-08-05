#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1), w(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> w[i];
    }
    multiset<int> st;
    sort(a.begin() + 1, a.end(), greater<int>());
    long long ans = 0;
    for(int i = 1, j = n;i <= n;i++){
        if(a[i] > n)    continue;
        while(j >= 1 && j >= a[i]){
            st.insert(w[j]);
            j--;
        }
        if(!st.empty()){
            auto it = prev(st.end());
            ans += *it;
            st.erase(it);
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}