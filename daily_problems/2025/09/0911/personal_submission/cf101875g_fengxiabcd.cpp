// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define i64 long long
#define db long double
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ull unsigned long long
#define vi vector<int>
using i128 = __int128;
#define endl '\n'
#define vpii vector<pii>
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
double get(pii x,pii y){
    if(x.s<=y.s)return INF;
    else return (y.f-x.f)*1.0/(x.s-y.s);
}
void slove(){
    int n;
    cin>>n;
    vpii a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i].f>>a[i].s;
    }
    sort(all(a));
    double ans=0;
    vector<double> ff(n);
    //cout<<"0.0000000000"<<endl;
    ff[n-1]=INF;
    stack<int> s;
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!s.empty()&&ff[s.top()]<get(a[i],a[s.top()]))s.pop();
        ff[i]=get(a[i],a[s.top()]);
        s.push(i);
    }
    // for(int i=0;i<n;i++)cout<<ff[i]<<" ";
    // cout<<endl;
    for(int i=0;i<n;i++)if(ff[i]<INF)ans=max(ans,ff[i]);
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(10);
    int t=1;
    //cin>>t;
    while (t--) slove();
    return 0;
}
