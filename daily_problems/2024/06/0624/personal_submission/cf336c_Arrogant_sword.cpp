
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int N = 2e5 + 10;

void solve(int _) 
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i, n) {
        cin >> a[i];
    }

    for (int i = 30; i >= 0; i -- ) {
        vector<int> cnt(i, 1);
        vector<int> ans;
        rep(j, n) {
            int x = (a[j] >> i) & 1;
            if (x == 1) {
                ans.push_back(a[j]);
                for (int k = 0; k < i; k ++ ) {
                    if (((a[j] >> k) & 1) == 0) {
                        cnt[k] = 0;
                    }
                }
            }
        }
        if (i == 0 || *max_element(all(cnt)) == 0) {
            if (SZ(ans)) {
                cout << SZ(ans) << endl;
                print(ans);
                return;
            }
            
        }
    }

    cout << -1 << endl;
} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}