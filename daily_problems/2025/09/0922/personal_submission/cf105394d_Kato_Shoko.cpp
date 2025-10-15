#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il ll quick_mi(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

il ll inv(ll n){
    return quick_mi(n,mod-2);
}

struct Node{
    //b[i]*r^(-i);
    //b[i]*r^(i);
    ll per,suf;
}tree[N<<2];

il int lson(int i){
    return i<<1;
}
il int rson(int i){
    return i<<1|1;
}

il void up(int i){
    tree[i].per=(tree[lson(i)].per+tree[rson(i)].per+mod)%mod;
    tree[i].suf=(tree[lson(i)].suf+tree[rson(i)].suf+mod)%mod;
}

il void updata(int i,int pl,int pr,int L,int R,ll per_w,ll suf_w){
    if(L<=pl&&pr<=R){
        tree[i].per=(tree[i].per+per_w+mod)%mod;
        tree[i].suf=(tree[i].suf+suf_w+mod)%mod;
        return ;
    }
    int mid=pl+pr>>1;
    if(L<=mid){
        updata(lson(i),pl,mid,L,R,per_w,suf_w);
    }else{
        updata(rson(i),mid+1,pr,L,R,per_w,suf_w);
    }

    up(i);
}

il Node query(int i,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R){
        return tree[i];
    }
    int mid=pl+pr>>1;
    ll x=0,y=0;
    if(L<=mid){
        auto [a,b]=query(lson(i),pl,mid,L,R);
        x=(x+a+mod)%mod;
        y=(y+b+mod)%mod;
    }
    if(R>mid){
        auto [a,b]=query(rson(i),mid+1,pr,L,R);
        x=(x+a+mod)%mod;
        y=(y+b+mod)%mod;
    }

    return {x,y};
}

il void solve(){
    ll n,q;
    double P;
    cin>>n>>q>>P;
    ll p=P*1e6;
    p=p*inv(1e6);
    ll r=(1-p+mod)%mod;

    vector<ll>fact_r(n+5),fact_invr(n+5);
    fact_r[0]=fact_invr[0]=1;

    ll invr=inv(r);

    for(int i=1;i<=n;i++){
        fact_r[i]=fact_r[i-1]*r%mod;
        fact_invr[i]=fact_invr[i-1]*invr%mod;
    }

    while(q--){
        char op;
        cin>>op;
        if(op=='+'){
            ll b,x;
            cin>>b>>x;
            b%=mod;
            ll per_w=b*fact_invr[x]%mod;
            ll suf_w=b*fact_r[x]%mod;
            updata(1,1,n,x,x,per_w,suf_w);
        }else if(op=='-'){
            ll b,x;
            cin>>b>>x;
            b*=-1;
            b=(b%mod+mod)%mod;
            ll per_w=b*fact_invr[x]%mod;
            ll suf_w=b*fact_r[x]%mod;
            updata(1,1,n,x,x,per_w,suf_w);
        }else{
            ll x;
            cin>>x;
            ll ans=0;
            auto [a,b]=query(1,1,n,1,x);
            ans=(fact_r[x]*a%mod+mod)%mod;
            auto [aa,bb]=query(1,1,n,x+1,n);
            ans=(ans+fact_invr[x]*bb%mod+mod)%mod;
            cout<<ans<<'\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
