// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define i64 long long
#define double long double
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ull unsigned long long
#define vi vector<int>
using i128 = __int128;
#define endl '\n'
#define vpii  vector<pii>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define pqpii priority_queue<pii, vector<pii>, greater<pii>>
#define pqi priority_queue<int,vector<int>, greater<int>>
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define INF 1e18
#define exp 1e-12
void slove(){
    int n,m;
    cin >> n>>m;
    vi a(m);
    for(int i = 0;i < m;i++) cin >> a[i];
    for(int i=0;i<m;i++)a[i]=min(a[i],n/2);
    if(accumulate(all(a),0LL)<n){
        cout << -1 << endl;
        return;
    }
    priority_queue<pii> q;
    for(int i = 0;i < m;i++)q.push(mp(a[i],i+1));
    int t=0;
    vi ans(n);
    while(t<n){
        int x = q.top().f;
        int id = q.top().s;
        q.pop();
        while(x--&&t<n){
            ans[t++]=id;
        }
    }
    for(int i = 0;i < n;i++){
        if(i%2==0){
            cout<<ans[i/2]<<" ";
        }else{
            cout<<ans[(n+1)/2+i/2]<<" ";
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
   // cin >> t;
    while (t--)slove();
    return 0;
}
