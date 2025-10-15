#include <bits/stdc++.h>

using namespace std;

/*
唯一有用的观察：
我们考虑一下全局最大值 mx，假如 h[i] = mx，则 mx 的右边不可能分出新的段了
mx 左边的话，我们可以任取一个点作为左端点
现在，我们把最后一个区间划分好了，接着划分前面的区间

羊的提示：我们分出来的最后一段，由于最大值一定比前面所有的值都大，所以最大值点一定是前缀 max 更新的点
一直往前分，我们会发现每段的最大值点都一定是前缀 max 更新时的点
max 最后一次更新之后，后边是不能分段的
接下来考虑如何分段
显然，每个段应该至少包含一个前缀 max 更新的点
我们考虑每一段的右端点应该怎么选
注意，1 一定是前缀 max 更新的点
最后一个前缀 max 更新的点以及之后只有唯一一种右端点选法
假设有 cnt 个前缀 max 更新点，则在前 cnt - 1 个区间里都可以选或不选一个右端点
*/

typedef long long LL;

const int mod = 1e9 + 7;
const int N = 5e5 + 10;
const int M = 510;

LL n, h[N], s[N];
vector<LL> pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        s[i] = max(h[i], s[i - 1]);
        if (h[i] > s[i - 1]) {
            pos.push_back(i);
        }
    }

    LL res = 1;
    for (int i = 0; i + 1 < pos.size(); i++) {
        res *= (pos[i + 1] - pos[i] + 1);
        res %= mod;
    }
    cout << res << endl;

    return 0;
}
