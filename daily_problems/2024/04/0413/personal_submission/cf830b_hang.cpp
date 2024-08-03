#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100010;
set<int> s[N];
signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s[a[i]].insert(i);
    }
    sort(a.begin(), a.end());
    int ans = n;
    int idx = 0, cnt = 0;
    for (int x: a){
        auto it = s[x].lower_bound(idx);
        if (it == s[x].end()){
            ans += n - cnt;
            idx = 0;
            it = s[x].lower_bound(idx);
        }
        idx = *it;
        cnt++;
        s[x].erase(it);
 
    }
    cout << ans;

}