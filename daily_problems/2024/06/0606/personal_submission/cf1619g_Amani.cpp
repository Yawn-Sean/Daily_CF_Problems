#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rank_;
// 初始化并查集
void init_union_find(int n) {
    parent.resize(n);
    rank_.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

int find(int u) {
    if (u != parent[u]) {
        u = find(parent[u]);
    }
    return u;
}
// 根据rank将深度较小的集合合并到深度较大的集合中
void merge(int u, int v) {
    int pos_u = find(u);
    int pos_v = find(v);
    if (pos_u != pos_v) {
        if (rank_[pos_u] > rank_[pos_v]) {  // 若rank_u > rank_v，则合并v到u中
            parent[pos_v] = pos_u;
        } else if (rank_[pos_u] < rank_[pos_v]) {  // 若rank_u < rank_v，则合并u到v中
            parent[pos_u] = pos_v;
        } else {  // 若rank相等，则都可以，并将该rank+1
            parent[pos_v] = pos_u;
            rank_[pos_u]++;
        }
    }
}

int solve(vector<int>& xs, vector<int>& ys, vector<int>& ts, int k) {
    int n = xs.size();
    map<int, vector<int>> dx, dy;  // 记录每一个坐标对应炸弹的x，y坐标轴的序号
    for (int i = 0; i < n; ++i) {
        dx[xs[i]].push_back(i);  // dx加入位于当前x坐标轴上的炸弹序号
        dy[ys[i]].push_back(i);  // dy加入位于当前y坐标轴上的炸弹序号
    }
    init_union_find(n);
    for (auto& [key, indices] : dx) {
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return ys[a] < ys[b];
        });  // x轴上的炸弹按y坐标排序
        for (size_t i = 0; i < indices.size() - 1; ++i) {
            if (ys[indices[i + 1]] - ys[indices[i]] <= k) {  // 若相邻炸弹的y坐标差小于等于k（可以引爆），则合并
                merge(indices[i], indices[i + 1]);
            }
        }
    }
    for (auto& [key, indices] : dy) {
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return xs[a] < xs[b];
        });  // y轴上的炸弹按x坐标排序
        for (size_t i = 0; i < indices.size() - 1; ++i) {
            if (xs[indices[i + 1]] - xs[indices[i]] <= k) {  // 若相邻炸弹的x坐标差小于等于k（可以引爆），则合并
                merge(indices[i], indices[i + 1]);
            }
        }
    }
    unordered_map<int, int> timers;
    for (int i = 0; i < n; ++i) {
        int p = find(i);  // 找到该炸弹所属的集合p
        // 若p还未被记录，或者当前时间小于p的最后自爆时间，则更新p的最后自爆时间
        if (timers.find(p) == timers.end() || ts[i] < timers[p]) {  // 每个连通块最后的自爆时间是当前连通块中最早的自爆时间
            timers[p] = ts[i];
        }
    }
    vector<int> nums;
    for (auto& [key, value] : timers) {
        nums.push_back(value);  // 记录每个集合的最后自爆时间
    }
    sort(nums.begin(), nums.end());
    int size = nums.size();  // 连通块个数
    int ans = size - 1;  // 因为可以从第0秒开始手动引爆连通块，故答案初始化为size-1（这也是手动引爆所有连通块的时间）
    for (int i = 0; i < size; ++i) {  // 枚举让前i+1个连通块自爆
        // 因为nums已经排序，所以当从i之后开始引爆时，i以及i前面的已经自爆，而i后面的要逐秒引爆
        ans = min(ans, max(nums[i], size - 2 - i));  // max(等待第i个自爆的时间，剩下的需要手动引爆的个数 * 1秒)
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> xs(n), ys(n), ts(n);
        for (int i = 0; i < n; ++i) {
            cin >> xs[i] >> ys[i] >> ts[i];  // 记录坐标和时间
        }
        int res = solve(xs, ys, ts, k);
        cout << res << endl;
    }
    return 0;
}
