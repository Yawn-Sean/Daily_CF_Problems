#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    using ll = long long;
    const ll inf = 1e18;
    int q;
    cin >> q;
    vector <int> lg2(q+2);
    for (int i = 1; i <= q+1; ++ i) lg2[i] = log2(i);

    // 为了处理没有祖先 比 它大的情况，我们定义一个超级祖先，编号为0，深度为0，点权为正无穷.
    vector <vector<int>> f1(q+2, vector<int>(20)), f2(q+2, vector<int>(20, 1e9)), loc(q+2, vector<int>(20, -1));
    vector <vector<ll>> Tot(q+2, vector<ll>(20, inf));
    vector <int> dep(q+2);
    // f1[u][i] 表示 u 结点向祖先结点跳 2^i 次， 最后跳到了哪一个结点
    // loc[u][i] 表示 u 结点沿着第一个 点权 大于等于 它当前点权的祖先结点跳，跳 2^i 次跳到了哪里
    // f2[u][i] 表示 u 结点向祖先结点跳 2^i 次， 经过的最大点权是多少(不包括跳完后 当前结点 的 点权)
    // Tot[u][i] 表示 u 结点沿着第一个 点权 大于等于 它当前点权的祖先结点跳，跳 2^i 次 的所有点的点权和是多少(不包括跳完后 当前结点 的 点权)
    // Tot[u][i] 既在 点 u 跳 2^i 次的代价
    
    f2[1][0] = 0, loc[1][0] = 0, Tot[1][0] = 0, dep[1] = 1;
    int idx = 1;

    ll last = 0;
    while(q--){
        int opt;
        ll rt, w;
        cin >> opt >> rt >> w;
        rt ^= last, w ^= last;
        if (opt == 1){
            idx += 1;
            int u = idx;

            f1[u][0] = rt;
            f2[u][0] = w, Tot[u][0] = w;
            dep[u] = dep[rt] + 1;

            for (int i = 1; i <= lg2[dep[u]]; ++ i){
                int p = f1[u][i-1];
                f1[u][i] = f1[p][i-1];
                f2[u][i] = max(f2[u][i-1], f2[p][i-1]);
            }

            loc[u][0] = rt; // loc[u][0] 找到第一个要跳的结点，也就是最后一个往该结点路径(不包括该结点)的最大值 小于 w 的，因为有超级祖先所以一定存在
            for (int i = lg2[dep[u]]; i >= 0; -- i){
                int &p = loc[u][0];
                if (f2[p][i] < w){
                    p = f1[p][i];
                }
            }

            for (int i = 1; i <= lg2[dep[u]]; ++ i){
                int p = loc[u][i-1];
                if (p == -1) break;
                loc[u][i] = loc[p][i-1];
                Tot[u][i] = Tot[u][i-1] + Tot[p][i-1];    
            }

        } else {
            int u = rt;
            last = 0;
            for (int i = lg2[dep[u]]; i >= 0; -- i){
                if (w >= Tot[u][i]){  // 如果在 u 跳 2^i 的代价可以接受，则跳 2^i
                    w -= Tot[u][i];
                    u = loc[u][i];
                    last += 1<<i;
                    assert(u != -1);
                }
            }
            cout << last << "\n";
        }
    }

}
