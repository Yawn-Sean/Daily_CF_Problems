#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5E5 + 10;
int n, tree[N << 2];
void push_up(int p){
    tree[p]=min(tree[p<<1], tree[p<<1|1]);
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p] = 0;
        return;
    }
    int mid=pl+pr>>1;
    build(p<<1,pl,mid),build(p<<1|1,mid+1,pr);
    push_up(p);
}
void update(int idx,int p,int pl,int pr,int d){
    if(idx == pl && idx == pr) {
        tree[p] = max(tree[p], d);
        return;
    }
    int mid=pl+pr>>1;
    if(idx <= mid) update(idx,p<<1,pl,mid,d);
    else update(idx,p<<1|1,mid+1,pr,d);
    push_up(p);
}
int query(int L,int R,int p,int pl,int pr){
    if(L<=pl&&R>=pr) {
        return tree[p];
    }
    int ret=1E9;
    int mid=pl+pr>>1;
    if(L<=mid) ret=query(L,R,p<<1,pl,mid);
    if(R>mid) ret=min(ret, query(L,R,p<<1|1,mid+1,pr));
    return ret;
}

void solve(){
    int q;
    cin >> n >> q;
    build(1, 1, n);
    while(q--){
        int op, l, r, id;
        cin >> op;
        if (op == 1){
            cin >> l >> r;
            update(l, 1, 1, n, r);
        }else{
            cin >> id;
            int L = 1, R = id;
            if (query(id, id, 1, 1, n) == 0){
                cout << "1\n";
                continue;
            }
            while(L < R){
                int mid = (L + R) / 2;
                int tmp = query(mid, id, 1, 1, n);
                if (tmp >= id){
                    R = mid;
                }else{
                    L = mid + 1;
                }
            }
            cout << (id - L + 2) << endl;

        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}