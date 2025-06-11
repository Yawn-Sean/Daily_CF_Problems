
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
void solve(int _) 
{
    int n, q;
    cin >> n >> q;
    vector<int> l(q), r(q), cnt(n+1);
    for (int i = 0; i < q; i ++ ) {
        cin >> l[i] >> r[i];
        for (int j = l[i]; j <= r[i]; j ++ ) {
            cnt[j] ++;
        }
    }


    int ans = 0;
    for (int i = 0; i < q; i ++ ) {
        for (int j = l[i]; j <= r[i]; j ++ ) {
            cnt[j] --;
        }

        int tol = 0;
        vector<int> sum(n+1);
        for (int j = 1; j <= n; j ++ ) {
            sum[j] = sum[j-1];
            if (cnt[j] >= 1) tol ++;
            if (cnt[j] == 1) {
                sum[j] ++;
            }
        }

        for (int j = 0; j < i; j ++ ) {
            ans = max(ans, tol - sum[r[j]] + sum[l[j] - 1]);
        }

        for (int j = l[i]; j <= r[i]; j ++ ) {
            cnt[j] ++;
        }
    }

    cout << ans << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
   // cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}