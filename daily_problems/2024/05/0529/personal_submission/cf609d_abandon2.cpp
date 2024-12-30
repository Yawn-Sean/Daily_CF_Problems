#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
typedef long long LL;
int a[N],b[N],c[N],d[N],p[N];
struct node{
    LL c;
    int id,f;
    bool operator<(const node&v)const{
        return c<v.c;
    }
}f[N];

void solve(){
    int n,m,k;LL s;cin>>n>>m>>k>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=m;i++)cin>>c[i]>>d[i];//标号与花费


    auto check=[&](int x)->int{
        LL mna=1e9,mnb=1e9;
        int mnai=-1,mnbi=-1;
        for(int i=1;i<=x;i++){
            if(mna>a[i]){
                mna=a[i];
                mnai=i;
            }
        }
        for(int i=1;i<=x;i++){
            if(mnb>b[i]){
                mnb=b[i];
                mnbi=i;
            }
        }
        for(int i=1;i<=m;i++){
            if(c[i]==1){
                f[i].c=(LL)mna*d[i],f[i].f=1;
            }
            else{
                f[i].c=(LL)mnb*d[i],f[i].f=2;
            }
            f[i].id=i;
        }
        sort(f+1,f+1+m);
        //cout<<f[1].c<<"  d   "<<f[2].c<<"\n";
        LL sum=0;
        for(int i=1;i<=k;i++)sum+=f[i].c;
        //cout<<mna<<" "<<mnb<<" "<<x<<" "<<sum<<"  "<<s<<"  cc\n";
        if(sum<=s){
            memset(p,0,sizeof p);
            for(int i=1;i<=k;i++){
                if(f[i].f==1){
                    p[f[i].id]=mnai;
                }
                else{
                    p[f[i].id]=mnbi;
                }
            }
            return true;
        }

        return false;
    };


    int l=0,r=n+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    
    if(r==n+1){
        cout<<"-1\n";return;
    }
    cout<<r<<"\n";
    for(int i=1;i<=m;i++){
        if(p[i]){
            cout<<i<<" "<<p[i]<<"\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
