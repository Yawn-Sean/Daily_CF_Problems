#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
// 支持单点赋值、区间加减、区间查询最大值 的 线段树
struct Tree {
    vector <int> info, tag;
    vector <int> on;
    vector <bool> vis;
    Tree(int n): info(4*n), tag(4*n), on(4*n), vis(4*n){}
    void apply(int u, long long x){
        info[u] += x, tag[u] += x, on[u] = 1;
    }
    void push(int u){
        apply(u*2, tag[u]), apply(u*2+1, tag[u]);
        on[u] = tag[u] = 0;
    }
    void pull(int u){
        if (vis[u*2] && vis[u*2+1]){
            info[u] = max(info[u*2], info[u*2+1]);
        } else {
            info[u] = vis[u*2] ? info[u*2] : info[u*2+1];
        }
    }
    void set(int u, int pos, int v, int lt, int rt){
        vis[u] = 1;
        if (lt == rt){
            info[u] += v;
            return;
        }
        if (on[u]) push(u);
        int mid = (lt+rt) >> 1;
        if (mid >= pos) set(u*2, pos, v, lt, mid);
        else set(u*2+1, pos, v, mid+1, rt);
        pull(u);
    }
    void update(int u, int l, int r, int v, int lt, int rt){
        if (lt >= l && rt <= r){
            apply(u, v);
            return;
        }
        if (on[u]) push(u);
        int mid = (lt+rt) >> 1;
        if (mid >= l) update(u*2, l, r, v, lt, mid);
        if (mid < r) update(u*2+1, l, r, v, mid+1, rt);
        pull(u);
    }
};

void solve(){
    int n, m, p;
    cin >> n >> m >> p;

    vector <array<int,2>> A(n), B(m);
    vector <array<int,3>> C(p);
    vector <int> minB(m);
    for (auto &it : A) cin >> it[0] >> it[1];
    for (auto &it : B) cin >> it[0] >> it[1];
    for (auto &it : C) cin >> it[0] >> it[1] >> it[2];
    // 对 B 和 C 排序
    sort(B.begin(), B.end(), [&](array<int,2>&a, array<int,2>&b){
        return a[0] < b[0];
    });
    sort(C.begin(), C.end(), [&](array<int,3>&a, array<int,3>&b){
        return a[0] < b[0];
    });
    // 求 大于等于 B[i][0] 的最小利润
    int minb = 1e9, mina = 1e9;
    for (auto &it : A) mina = min(mina, it[1]);
    for (auto &it : B) minb = min(minb, it[1]);
  
    for (int i = m-1, Min = 1e9; i >= 0; -- i){
        Min = min(Min, B[i][1]);
        minB[i] = Min;
    }
    // modi_map 是 线段树的 的初始化
    map <int,int> modi_map;
    for (auto &it : C){
        if (B[m-1][0] > it[1]){
            modi_map[it[1]] = 0;
        }
    }
    auto call = [&](int x)->int{ 
        int l = 0, r = m-1;
        while (l < r){
            int mid = (l+r) >> 1;
            if (B[mid][0] > x) r = mid;
            else l = mid+1;
        }
        int j = l;  // 找第一个大于 x 的
        return minB[j];
    };
    for (auto &it : modi_map){
        it.second = call(it.first);
    }
    // 线段树初始化
    const int N = 1e6;
    Tree Y(N);
    vector <long long> ans(p);
    set <int> modi_st;
    for (int i = 0; i < p; ++ i){
        int x = C[i][1], y = C[i][2];
        if (x >= B[m-1][0]){
            ans[i] = i == 0 ? -1e18 : ans[i-1];
            continue;
        }
        if (modi_st.find(x) == modi_st.end()){
            Y.set(1, x, -modi_map[x], 1, N);  // 增加选一个盔甲的影响
            modi_st.insert(x);
        }
        Y.update(1, x, N, y, 1, N);
        ans[i] = Y.info[1];  // 考虑盔甲的影响，选前i个怪兽的最大值
    }
    // 枚举所有 A
    long long res = -(mina + minb);
    for (int i = 0; i < n; ++ i){
        long long x = A[i][0], all = -A[i][1];
        int l = 0, r = p-1;
        while (l < r){
            int mid = (l+r+1) >> 1;
            if (C[mid][0] < x) l = mid;
            else r = mid-1;
        }
        int j = l;  // 找 最后一个 小于 x 的
        if (x > C[j][0]){
            res = max(res, ans[j]+all);
        }
    }

    cout << res << "\n";
}
