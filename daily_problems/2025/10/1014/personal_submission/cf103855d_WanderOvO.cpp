#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 3e5 + 10;
const int M = 1e6 + 10;

/*
如果只能打一下，当然是选值之和最大的直线
注意，直线是平行于坐标轴的
我们枚举怪兽，把值加到行和列上，看看谁最大，就把谁删掉即可
假如我们是打掉了一行，那么下一次打的时候，其他行的和不受影响
其他列中，每个列的和都要减去一个数
有没有这样的可能：第一次有两行并列第一大，打的顺序不同会导致第二次的和不一样
这是不会的，因为你都说了是两行并列第一大的，打行对其他行没影响
那如果是一行和一列并列第一大呢？
会有影响的，考虑下面的数据
 x  x  9
 x 10
 5  2  6  3
11  4
考虑这个数据，显然最大的行和列都是 16，且有好多个
假设我们打两次，看如何最大
首先，第 1 轮选的时候，我们可能想贪最大的，所以我们可能会选某个 16 的行或者列
只有选第 1 列和第 2 列时，才能达到最大，16 + 16 = 32
如果选第 2 行，则后边只能选和为 14 的第 2 列，达到 16 + 14 = 30
我们似乎可以枚举的样子，一行两列、两行一列、三行、三列，都看一下
如果钦定了必须拿 1 行 2 列，先拿行或者先拿列有影响吗
由于每个被拿的数只会贡献一次，所以完全可以先拿了 1 行，再去找最大的两列
注意，这里不一定是拿最大的 1 行，需要枚举一下
我们需要在删掉这一行后，快速维护列的前 2 大，使用什么结构去维护？
可以使用一个 multiset
*/

LL n, x[N], y[N], v[N];
LL res = 0;
LL x_sum[M], y_sum[M];
vector<vector<int>> x_id(M), y_id(M);

LL calc(int c1, int c2) {
    memset(x_sum, 0, sizeof x_sum);
    memset(y_sum, 0, sizeof y_sum);
    for (int i = 0; i < M; i++) {
        x_id[i].clear();
    }
    for (int i = 0; i < M; i++) {
        y_id[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        x_sum[x[i]] += v[i];
        y_sum[y[i]] += v[i];
        x_id[x[i]].push_back(i);
        y_id[y[i]].push_back(i);
    }
    
    if (c1 == 0) {
        sort(y_sum, y_sum + M);
        return y_sum[M - 1] + y_sum[M - 2] + y_sum[M - 3];
    } else if (c2 == 0) {
        sort(x_sum, x_sum + M);
        return x_sum[M - 1] + x_sum[M - 2] + x_sum[M - 3];
    } else if (c1 == 1) {
        multiset<LL> st;
        for (int i = 0; i < M; i++) {
            st.insert(y_sum[i]);
        }
        
        LL ans = 0;
        for (int i = 0; i < M; i++) {
            LL cur = x_sum[i];
            // 枚举第 i 行的点，删掉
            for (auto id : x_id[i]) {
                auto it = st.find(y_sum[y[id]]);
                st.erase(it);
                y_sum[y[id]] -= v[id];
                st.insert(y_sum[y[id]]);
            }
            
            LL v1 = *prev(st.end());
            auto it = st.find(v1);
            st.erase(it);
            LL v2 = *prev(st.end());
            cur += v1 + v2;
            ans = max(ans, cur);
            st.insert(v1);
            
            for (auto id : x_id[i]) {
                auto it = st.find(y_sum[y[id]]);
                st.erase(it);
                y_sum[y[id]] += v[id];
                st.insert(y_sum[y[id]]);
            }
        }
        return ans;
    } else {
        multiset<LL> st;
        for (int i = 0; i < M; i++) {
            st.insert(x_sum[i]);
        }
        
        LL ans = 0;
        for (int i = 0; i < M; i++) {
            LL cur = y_sum[i];
            // 枚举第 i 行的点，删掉
            for (auto id : y_id[i]) {
                auto it = st.find(x_sum[x[id]]);
                st.erase(it);
                x_sum[x[id]] -= v[id];
                st.insert(x_sum[x[id]]);
            }
            
            LL v1 = *prev(st.end());
            auto it = st.find(v1);
            st.erase(it);
            LL v2 = *prev(st.end());
            cur += v1 + v2;
            ans = max(ans, cur);
            st.insert(v1);
            
            for (auto id : y_id[i]) {
                auto it = st.find(x_sum[x[id]]);
                st.erase(it);
                x_sum[x[id]] += v[id];
                st.insert(x_sum[x[id]]);
            }
        }
        return ans;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> v[i];
    }
    
    res = max(res, calc(0, 3));
    res = max(res, calc(1, 2));
    res = max(res, calc(2, 1));
    res = max(res, calc(3, 0));
    
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
