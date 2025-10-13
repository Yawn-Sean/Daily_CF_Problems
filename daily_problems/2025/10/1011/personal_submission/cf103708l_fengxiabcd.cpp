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
using ll = long long;
using i128 = __int128;
//#define endl '\n'
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
const int mod = 1e9+7;
vpii get(int n,vi a){
    vpii d(n+1);
    stack<int>s;
    s.push(0);
    for(int i=1;i<=n;i++){
        while(a[s.top()]<=a[i])s.pop();
        d[i].f=s.top();
        s.push(i);
    }
    stack<int>s2;
    s2.push(n+1);
    for(int i=n;i>=1;i--){
        while(a[s2.top()]<=a[i])s2.pop();
        d[i].s=s2.top();
        s2.push(i);
    }
    return d;
}
void slove(){
    int n;
    cin>>n;
    vi a(n+2);
    a[0]=a[n+1]=INF;
    for(int i=1;i<=n;i++) cin>>a[i];
    vi b(n+2),sum(n+2);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    vpii d(n+1);
    for(int i=1;i<=n;i++)b[i]=(b[i-1]+a[i]*i)%mod;
    d=get(n,a);
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=d[i].f,r=d[i].s;
        ans+=((b[i]-b[l])-(sum[i]-sum[l])*(l))%mod*(r-i);
        ans%=mod;
    }
    reverse(all(a));
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)b[i]=(b[i-1]+a[i]*i)%mod;
    d=get(n,a);
    for(int i=1;i<=n;i++){
        int l=d[i].f,r=d[i].s;
        ans+=((b[i-1]-b[l])-(sum[i-1]-sum[l])*(l))%mod*(r-i);
        ans%=mod;
    }
    if(ans<0)ans+=mod;
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
