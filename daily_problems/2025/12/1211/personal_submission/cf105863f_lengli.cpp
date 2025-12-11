#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 线段树节点存储的数据类型
using ValueType = int;
// 无效/中性元素
const ValueType IDENTITY_ELEMENT = 2e9 + 7;

/**
 * @brief 线段树类：实现区间最小值查询和线段树上的二分查找 (find_first)
 */
class SegmentTree {
private:
    int n;
    vector<ValueType> tree;
    vector<ValueType> raw_data;

    ValueType op(ValueType a, ValueType b) {
        return min(a, b);
    }

    // 递归构建线段树
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = raw_data[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = op(tree[2 * node], tree[2 * node + 1]);
    }

    // 递归查询区间 [l, r] 的最小值
    ValueType query_min(int node, int start, int end, int l, int r) {
        if (r < start || end < l || l > r) {
            return IDENTITY_ELEMENT;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        ValueType p1 = query_min(2 * node, start, mid, l, r);
        ValueType p2 = query_min(2 * node + 1, mid + 1, end, l, r);
        return op(p1, p2);
    }

    // 查找第一个满足 A[i] <= x 的元素索引 i，i >= query_start
    // 返回 n 表示未找到
    int find_first_recursive(int node, int start, int end, int query_start, int x) {
        // 1. 当前节点代表的区间 [start, end] 不在查询范围 [query_start, n-1] 内
        if (end < query_start) {
            return n;
        }

        // 2. 当前区间最小值大于 x，则区间内所有元素都大于 x，直接返回未找到
        if (tree[node] > x) {
            return n;
        }

        // 3. 叶子节点且满足条件 (tree[node] <= x)，返回索引
        if (start == end) {
            return start;
        }

        int mid = start + (end - start) / 2;
        int result = n;

        // 优先查找左子树，且左子树至少要与查询范围 [query_start, n-1] 有交集
        // 如果左子树最小值 <= x，则可能有解
        if (mid >= query_start && tree[2 * node] <= x) {
            result = find_first_recursive(2 * node, start, mid, query_start, x);
        }

        // 如果左子树找到了，直接返回结果
        if (result != n) {
            return result;
        }

        // 否则，在右子树查找
        // 只有当右子树的最小值 <= x，才递归
        if (tree[2 * node + 1] <= x) {
            result = find_first_recursive(2 * node + 1, mid + 1, end, query_start, x);
        }

        return result;
    }

public:
    SegmentTree(const vector<ValueType>& data) {
        n = data.size();
        if (n == 0) return;
        raw_data = data;
        // 4 * n 是线段树数组的安全大小
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    // 在 [query_start, n-1] 范围内，找到第一个满足 nums[i] <= x 的索引 i
    int find_first(int query_start, int x) {
        if (query_start >= n) return n;
        return find_first_recursive(1, 0, n - 1, query_start, x);
    }
};

// ------------------- 主函数 -------------------
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    // 初始化自定义线段树
    SegmentTree seg(nums);

    while (q --) {
        int x_query;
        cin >> x_query;

        int current_val = x_query;
        int current_pos = 0; // 从这个位置开始查找

        while (current_val > 0) {
            // 查找从 current_pos 开始，第一个满足 nums[pt] <= current_val 的索引 pt
            int pt = seg.find_first(current_pos, current_val);

            if (pt == n) {
                // 如果没有找到更小的元素，则 current_val 不会再改变
                break;
            }

            // 执行取模操作
            current_val %= nums[pt];
            
            // 下一次查找从 pt + 1 开始
            current_pos = pt + 1;
        }

        cout << current_val << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        solve();
    }

    return 0;
}
