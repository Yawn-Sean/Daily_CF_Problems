// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
#define double long double
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ull unsigned long long
#define f first
#define s second
//#define endl '\n'
#define vi vector<int>
#define vii vector<vector<int>>
#define vc vector
#define vpii vector<pair<int, int>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define INF 1e18
#define exp 1e-12
const int N=2e5+5;
void slove(){
    int n;
    cin>>n;
    vpii a(n+1);
    vi b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].f;
        a[i].s=i;
    }
    b[0]=INF;
    a[0].f=0;
    a[0].s=0;
    for(int i=1;i<=n;i++)b[a[i].f]++;
    sort(all(a),[&](pii c,pii d){
        if(b[c.f]==b[d.f])return c.s<d.s;
        return b[c.f]>b[d.f];
    });
    if(b[a[0].f]<2){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    vi p(n+1),j(n+1);
    vpii ans(n+1);
    vi as(n+1);
    p[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i].f==0){
            p[i]=1;
            j[i]=a[i].s;
            continue;
        }
        if(a[i].f<i){
            p[i]=p[i-a[i].f];
            j[i]=a[i-a[i].f].s;
        }else{
            p[i]=a[i].f-i+2;
            j[i]=a[1].s;
        }
    }
    if(a[1].f!=0)j[1]=a[2].s;
    else j[1]=a[1].s;
    for(int i=1;i<=n;i++){
        ans[a[i].s]=mp(i,p[i]);
        as[a[i].s]=j[i];
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i].f<<" "<<ans[i].s<<endl;
    }
    for(int i=1;i<=n;i++)cout<<as[i]<<" ";
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while (t--)slove();
    return 0;
}
