#include <bits/stdc++.h>
// #include <ctime>
using namespace std;

typedef long long i64;

struct Node
{
    i64 l, r, lazytag;
};

class SegTree {
public:
    vector<Node> tree;    

    SegTree(int n) 
    {
        tree.resize(n * 4);
        build(1, 0, n - 1);
    }

    void build(int id, int l, int r)
    {
        tree[id] = {l, r, 0};
        if(l == r) return;

        int mid = (l + r) >> 1;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
    }

    void pushdown(int x)
    {
        if(tree[x].lazytag != -1) 
        {
            int lt = tree[x].lazytag;
            tree[2 * x].lazytag = lt;
            tree[2 * x + 1].lazytag = lt;
            tree[x].lazytag = -1;
        }
    }

    void modify(int id, int l, int r, int k)
    {   
        if(tree[id].l >= l && tree[id].r <= r)
        {
            tree[id].lazytag = k;
        } 
        else 
        {
            pushdown(id);
            int mid = (tree[id].l + tree[id].r) >> 1;
            if(tree[2 * id].r >= l) modify(2 * id, l, r, k);            
            if(tree[2 * id + 1].l <= r) modify(2 * id + 1, l, r, k);
        }
    }

    i64 query(int id, int idx)
    {
        if(tree[id].lazytag != -1) return tree[id].lazytag;            
        if(tree[2 * id].r >= idx) return query(2 * id, idx);            
        return query(2 * id + 1, idx);
    }

    void rangeModify(int l, int r, int k)
    {  
        modify(1, l, r, k);
    }
    
    i64 query(int idx) 
    {
        return query(1, idx);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> l(m+1, -1), r(m+1, -1);
    for(int i=0; i<n; i++) {
        if(l[a[i]] == -1) l[a[i]] = i;
        r[a[i]] = i;
    }

    SegTree st(n);
    st.rangeModify(0, n-1, 1);

    for(int i=1; i<=m; i++) {
        if(l[i] != -1) {
            st.rangeModify(l[i], r[i], i);
        }        
    }

    vector<int> res(n);

    for(int i=0; i<n; i++) {
        int t = st.query(i);
        if(a[i] == 0 || a[i] == t) res[i] = t;
        else {
            cout << "NO" << endl;
            return;
        }
    }

    bool flag = l[m] == -1;
    if(l[m] == -1) {
        for(int i=0; i<n; i++) {
            if(a[i] == 0) {
                res[i] = m;
                flag = false;
                break;
            }
        }
    }

    if(flag) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for(int i: res) cout << i << ' ';
    cout << endl;

}
