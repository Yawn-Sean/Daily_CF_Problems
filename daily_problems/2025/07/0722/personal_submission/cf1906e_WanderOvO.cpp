/*
n = 1000，不大，2N 的排列
假设两个序列为 a, b，给的序列为 c
假设该分析 c[i] 分配到哪里了
- 如果 c[i - 1] > c[i]，则 c[i - 1] 和 c[i] 必须在同一个序列中，否则 c[i - 1] 不应该在 c[i] 前面
- 否则呢？18 7 8，18 和 7 一定在一个序列中，而 8 < 18 且在后面，所以 8 也必须在同一个序列中，直到遇到一个 > 18 的数字，才是分段了

建图，同一个序列中的那些关系我们连边，这些需要打包分配给某个序列
于是关键问题就变成了那些模棱两可的咋分配
这样就有点背包问题的意思了，我们把打包的那些看成一个数
考虑前 i 个压缩数中，包含 j 个未压缩数是否可行，使用 dp 搞
只要 dp[m][n] 可行，就有方案
我们还关心上一个压缩数是否被选了，所以还得额外维护一个维度，dp[i][j][0/1]
dp[i][j][0] |= dp[i - 1][j][0]
dp[i][j][0] |= dp[i - 1][j][1]
dp[i][j][1] |= dp[i - 1][j - cnt[i]][0]
dp[i][j][1] |= dp[i - 1][j - cnt[i]][1]
from[i][j][0/1] 记录从哪里转移过来的
*/

struct Choice {
    int i, j, pick;
};

int n, c[N], cnt[N];
bool dp[N][N][2];
Choice from[N][N][2];
vector<PII> segs;

void meibao() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> c[i];
    }

    segs.push_back({0, 0});

    int l = 1, r = 1;
    for (int i = 2; i <= 2 * n; i++) {
        if (c[i - 1] > c[i]) {
            r++;
        } else {
            if (c[i] < c[l]) {
                r++;
            } else {
                segs.push_back({l, r});
                r++;
                l = r;
            }
        }
    }
    
    segs.push_back({l, r});

    int m = segs.size() - 1;
    for (int i = 1; i <= m; i++) {
        cnt[i] = segs[i].y - segs[i].x + 1;
        // cout << segs[i].x << " " << segs[i].y << " " << cnt[i] << "\n";
    }
    dp[0][0][0] = true;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i - 1][j][0]) {
                dp[i][j][0] |= dp[i - 1][j][0];
                from[i][j][0] = {i - 1, j, 0};
            }
            if (dp[i - 1][j][1]) {
                dp[i][j][0] |= dp[i - 1][j][1];
                from[i][j][0] = {i - 1, j, 1};
            }
            if (j >= cnt[i] and dp[i - 1][j - cnt[i]][0]) {
                dp[i][j][1] |= dp[i - 1][j - cnt[i]][0];
                from[i][j][1] = {i - 1, j - cnt[i], 0};
            }
            if (j >= cnt[i] and dp[i - 1][j - cnt[i]][1]) {
                dp[i][j][1] |= dp[i - 1][j - cnt[i]][1];
                from[i][j][1] = {i - 1, j - cnt[i], 1};
            }
        }
    }

    if (!(dp[m][n][0] or dp[m][n][1])) {
        cout << "-1\n";
    } else {
        vector<int> a, b;
        Choice cur_choice;
        if (dp[m][n][0]) {
            cur_choice = {m, n, 0};
        } else {
            cur_choice = {m, n, 1};
        }

        while (true) {
            int i = cur_choice.i, j = cur_choice.j, pick = cur_choice.pick;
            if (pick) {
                for (int k = segs[i].y; k >= segs[i].x; k--) {
                    a.push_back(c[k]);
                }
            } else {
                for (int k = segs[i].y; k >= segs[i].x; k--) {
                    b.push_back(c[k]);
                }
            }
            cur_choice = from[i][j][pick];
            if (cur_choice.i == 0) {
                break;
            }
        }   

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (auto val : a) {
            cout << val << " ";
        }
        cout << "\n";
        for (auto val : b) {
            cout << val << " ";
        }
    }
}
