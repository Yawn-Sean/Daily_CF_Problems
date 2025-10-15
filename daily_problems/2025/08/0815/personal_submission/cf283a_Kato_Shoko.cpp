#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-3;
double PI=3.1415926;

ll a[N],tree[N<<2],tag[N<<2],maxn=2e5+1;

il int lson(int i){
    return i<<1;
}
il int rson(int i){
    return i<<1|1;
}

il void up(int i){
    tree[i]=tree[lson(i)]+tree[rson(i)];
}
il void build(int i,int pl,int pr){
    if(pl==pr){
        tree[i]=a[pl];
        return ;
    }
    int mid=pl+pr>>1;
    build(lson(i),pl,mid);
    build(rson(i),mid+1,pr);

    up(i);
}

il void laze(int i,int pl,int pr,ll val){
    tag[i]+=val;
    tree[i]+=val*(pr-pl+1);
}

il void down(int i,int pl,int pr){
    if(tag[i]){
        int mid=pl+pr>>1;
        laze(lson(i),pl,mid,tag[i]);
        laze(rson(i),mid+1,pr,tag[i]);
        tag[i]=0;
    }
}

il void updata(int i,int pl,int pr,int L,int R,ll val){
    if(L<=pl&&pr<=R){
        if(val==-inf){
            // 如果是叶子,清0并且清除tag
            if(pl==pr){
                tree[i]=0;
                tag[i]=0;
                return ;
            } else {
                //如果不是叶子，对非叶子也向下递归处理
                down(i,pl,pr);
                int mid=pl+pr>>1;
                if(L<=mid) updata(lson(i),pl,mid,L,R,val);
                if(R>mid)  updata(rson(i),mid+1,pr,L,R,val);
                up(i);
                return;
            }
        }
        laze(i,pl,pr,val);
        return ;
    }
    down(i,pl,pr);
    int mid=pl+pr>>1;
    if(L<=mid){
        updata(lson(i),pl,mid,L,R,val);
    }
    if(R>mid){
        updata(rson(i),mid+1,pr,L,R,val);
    }

    up(i);
}

il ll query(int i,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R){
        return tree[i];
    }
    down(i,pl,pr);
    int mid=pl+pr>>1;
    ll ans=0;
    if(L<=mid){
        ans+=query(lson(i),pl,mid,L,R);
    }
    if(R>mid){
        ans+=query(rson(i),mid+1,pr,L,R);
    }
    return ans;
}

il void solve(){
    int q;
    cin>>q;
    int n=1;
    a[1]=0;
    cout<<fixed<<setprecision(6);
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            ll id,val;
            cin>>id>>val;
            //将前id个数+val
            updata(1,1,maxn,1,id,val);
        }else if(op==2){
            ll k;
            cin>>k;
            //将k放到末尾
            updata(1,1,maxn,n+1,n+1,k);
            n++;
        }else{
            //取消末尾的一个数
            if(n>=2){
                updata(1,1,maxn,n,n,-inf);
                n--;
            }  
        }
        ll sum=query(1,1,n,1,n);
        double avg=(double)sum/(double)n;
        cout<<avg<<'\n';
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
