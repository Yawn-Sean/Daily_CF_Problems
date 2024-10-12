/*
    Bonelight * V *
    20241004: 放假的懒惰之日 
    No Coding, No Bug 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14
void solve()
{
    int n,k; cin >> n >> k;
    set<int> st;
    for(int i = 1; i <= k; i ++){
        if(st.count(n % i)){
            cout << "NO" << endl;
            return;
        } else {
            st.insert(n % i);
        }
    }
    cout << "YES" << endl;
}  

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
