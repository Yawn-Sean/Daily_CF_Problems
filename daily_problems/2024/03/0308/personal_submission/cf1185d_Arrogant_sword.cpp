// 删a0, 删a1,都不删公差就确定了。

#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////

bool judge(int x, vector<int> &a) {
    vector<int> tmp;
    int n = a.size();
    for (int i = 0; i < n; i ++ ) {
        if (i != x) tmp.pb(a[i]);
    }

    bool ok = true;
    int xx = tmp[1] - tmp[0]; 
    
    for (int i = 2; i < n-1; i ++ ) {
        if (tmp[i] - tmp[i-1] != xx) {
            
            ok = false;
            break;
        }
    }

    return ok;
} 

void solve() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        mp[a[i]] = i+1;
    }
    sort(all(a));
    
    if (judge(0, a)) {
        cout << mp[a[0]] << endl;
        return;
    }

    if (judge(1, a)){
        cout << mp[a[1]] << endl;
        return;
    }

    int x = a[1] - a[0];
    for (int i = 2; i < n; i ++ ) {
        if (a[i] - a[i-1] != x) {
            if (judge(i, a)) {
                cout << mp[a[i]] << endl;
                return;
            }
            cout << -1 << endl;
            return;
        }
    }

    
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}