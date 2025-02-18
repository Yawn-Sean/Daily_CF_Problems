#include <bits/stdc++.h>  //803ms
using namespace std;
using ll = long long;
const int limi = 1e9;
struct Node {
    int v;
    Node *l, *r;
    int id;
    Node(int v=0, Node*l=nullptr, Node*r=nullptr, int id=-1):v(v),l(l),r(r),id(id){}
    Node* insert(int lt, int rt, int v, int nul);
};
Node *Null = new Node();
Node *Node::insert(int lt, int rt, int pos, int num){
    if (pos >= lt && pos <= rt){
        if (lt==rt) return new Node(v+1, Null, Null, num);
        int mid = lt + rt >> 1;
        return new Node(v+1, l->insert(lt,mid,pos,num), r->insert(mid+1,rt,pos,num), (id==-1?num:id));    }
    return this;
}
 
void solve(){
    int n;
    cin >> n;
    map <int, int> mps;
    vector <array<int,2>> xys;
    for (int i = 0, x, y; i < n; ++ i){
        cin >> x >> y;
        xys.push_back({x, y});
        mps[x] = 0;
    }
 
    int len = mps.size();
    vector <int> dic(len);
    int tot = -1;
    for (auto &j : mps){
        j.second = ++ tot;
        dic[tot] = j.first;
    }
    vector <Node*> root(n+1);
    root[0] = Null;
    vector <int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int a, int b){
        return xys[a][0]!=xys[b][0] ? xys[a][0] < xys[b][0] : xys[a][1] < xys[b][1];
    });
 
    for (int i = 0; i < n; ++ i){
        int j = p[i];
        int y = xys[j][1];
        root[i+1] = root[i]->insert(1, limi, y, j+1);
    }
 
    auto query = [&](auto &self, Node *u, int l, int r, int lt, int rt)->int{
        if (u==Null || u->v == 0) return -1;
        if (lt >= l && rt <= r){
            return u->id;
        }
        int mid = lt+rt >> 1, res = -1;
        if (mid >= l) res = self(self, u->l, l, r, lt, mid);
        if (res==-1 && mid < r) res = self(self, u->r, l, r, mid+1, rt);
        return res;
    };
    auto find = [&](int x)->int{
        int l = 0, r = n-1;
        while (l < r){
            int mid = l+r >> 1, j = p[mid];
            if (xys[j][0] >= x) r = mid;
            else l = mid+1;
        }
        return l;
    };
 
    vector <int> ans(n, -1);
    
    for (int i = 0; i < n; ++ i){
        auto &j = xys[i];
        int x = find(j[0]), y = j[1];
        ans[i] = query(query, root[x], 1, y-1, 1, limi);
        if (ans[i] == -1){
            x = find(j[1]), y = j[0];
            if (j[1] > xys[p[x]][0]) x += 1; 
            ans[i] = query(query, root[x], 1, y-1, 1, limi);
        }
    }
 
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
 
