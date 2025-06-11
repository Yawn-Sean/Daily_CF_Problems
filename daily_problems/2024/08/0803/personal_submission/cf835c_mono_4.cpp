#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define mem(a) memset(a,0, sizeof(a))
#define db(x) cout<<x<<"\n";
#define _db(a,n) for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
const int N=1e5+5;
//int a[N];
int _=0;
int a[11][101][101],sum[11][101][101];
void solve(){
    int n,q,c;cin>>n>>q>>c;
    rep(i,1,n){
        int x,y,s;cin>>x>>y>>s;
        rep(j,0,c){
            a[j][x][y]+=(s+j)%(c+1);
        }
    }
    rep(k,0,c){
        rep(i,1,100){
            rep(j,1,100){
                sum[k][i][j]=sum[k][i-1][j]+sum[k][i][j-1]-sum[k][i-1][j-1]+a[k][i][j];
            }
        }
    }
    auto get=[&](int t,int x1,int y1,int x2,int y2){
        return sum[t][x2][y2]-sum[t][x2][y1-1]-sum[t][x1-1][y2]+sum[t][x1-1][y1-1];
    };
    rep(i,1,q){
        int t,x1,y1,x2,y2;cin>>t>>x1>>y1>>x2>>y2;
        t%=(c+1);
        cout<<get(t,x1,y1,x2,y2)<<"\n";
    }
    //cout<<"#"<<(++_)<<" "<<endl;
}
signed main()
{
std::ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    // int t;cin>>t;while(t--)
    solve();
    return 0;
}
