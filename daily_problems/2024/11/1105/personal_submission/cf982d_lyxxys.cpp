#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    vector <int> A(n), p(n), ids(n), sz(n, 1);
    for (auto &x : A) cin >> x;
    iota(p.begin(), p.end(), 0);
    iota(ids.begin(), ids.end(), 0);

    auto find = [&](auto &&self, int x)->int{
        return p[x] = p[x] == x ? x : self(self, p[x]);
    };

    sort(ids.begin(), ids.end(), [&](int x, int y){
        return A[x] < A[y];
    });

    int res = 0, by = 0, Max = 1;
    map <int,int> mps;
    auto merge = [&](int x, int y)->void{
        x = find(find, x);
        y = find(find, y);
        if (sz[x] < sz[y]) swap(x, y);

        mps[sz[x]] -= 1, mps[sz[y]] -= 1;
        p[y] = x;
        sz[x] += sz[y];
        mps[sz[x]] += 1;
        fmax(Max, sz[x]);
    };

    // 从小到大合并，并更新 mps[i]， 表示连通块大小为 i 的 有 mps[i] 个

    for (int i = 0; i < n; ++ i){
        int x = A[ids[i]];
        mps[1] += 1;
        int u = ids[i]-1, v = ids[i]+1;

        // 将小于等于 x 的合并成一个集合
        if (u >= 0 && x > A[u]) merge(ids[i], u);
        if (v < n && x > A[v]) merge(ids[i], v);
        // 如果 最大值 * 连通块大小为最大值的个数 == 所有，则所有连通块大小相同
        // 选择 连通块个数 严格大于 by 的
        if (Max*mps[Max] == i+1 && mps[Max] > by){
            res = x+1;
            by = mps[Max];
        }
    }

    cout << res << "\n";
}   
