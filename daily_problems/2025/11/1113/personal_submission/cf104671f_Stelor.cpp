#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll n, k, q;
const int N = 2E5 + 10;
ll a[N];
ll tree[N << 2];
ll mx = (1 << 31) - 1;
void push_up(int p){
    tree[p]=tree[p<<1] & tree[p<<1|1];
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p]=a[pl];
        return;
    }
    int mid=pl+pr>>1;
    build(p<<1,pl,mid),build(p<<1|1,mid+1,pr);
    push_up(p);
}
ll query(int L,int R,int p,int pl,int pr){
    if(L<=pl&&R>=pr) {
        return tree[p];
    }
    ll ret=mx;
    int mid=pl+pr>>1;
    if(L<=mid) ret=query(L,R,p<<1,pl,mid);
    if(R>mid) ret = ret & query(L,R,p<<1|1,mid+1,pr);
    return ret;
}

void solve(){
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        for (int j = 31; j >= 0; --j){
            if ((a[i] & k) == k){

            }else{
                a[i] = mx;
            }
        }
    }
    build(1, 1, n);
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << ((k == query(l, r, 1, 1, n)) ? "YES\n" : "NO\n"); 
    }   
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}