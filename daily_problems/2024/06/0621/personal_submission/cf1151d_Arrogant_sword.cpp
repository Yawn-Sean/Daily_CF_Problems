
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(int *vi, int st, int ed)
{
    for (int i = st; i <= ed; i ++ ) cout << vi[i] << ' ';
    cout << endl;
}

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

    vector<PII> a(n+1);
    vector<int> id(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i].first >> a[i].second;
        id[i] = i;
    }

    sort(id.begin() + 1, id.end(), [&](int i, int j) {
        return a[i].first - a[i].second > a[j].first - a[j].second;
    });

    int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        ans += i * (a[id[i]].first - a[id[i]].second) - a[id[i]].first + n * a[id[i]].second;
    }

    cout << ans << endl;

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