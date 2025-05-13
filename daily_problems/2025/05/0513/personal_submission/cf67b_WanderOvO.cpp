/*
显然，对于 i >= n - k + 1，b[i] = 0，所以这些 i 怎么排都可以
题目要求字典序最小的排列，那么上面那些元素当然是小的在前，大的在后
对于 i <= n - k，怎么办？
从 i = 1 开始填可以吗？1 前面肯定有至少 b[1] 个 >= k + 1 的数
我们肯定希望比较小的排前面，所以我们要先看 b[k + 1]
倘若 b[k + 1] < b[1]，则 k + 1 是可以在 1 前面的
k + 1 前面至少有 b[k + 1] 个 >= k + 1 + k 的数
这样分析下去，好像先填大的数比较好，不会影响小的数填
注意到数据范围并不大，好像可以暴力看插入的位置
*/

int n, k, cnt[N];

void meibao() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
    }

    vector<int> ans;
    for (int i = n; i > 0; i--) {
        int c = 0;
        bool finished = false;
        for (int j = 0; j < ans.size(); j++) {
            if (c == cnt[i]) {
                ans.push_back(i);
                for (int l = ans.size() - 1; l > j; l--) {
                    swap(ans[l], ans[l - 1]);
                }
                finished = true;
                break;
            }
            if (ans[j] >= i + k) {
                c++;
            }
        }
        if (!finished) {
            assert(c == cnt[i]);
            ans.push_back(i);
        }
    }
    for (auto v : ans) {
        cout << v << " ";
    }
}   
