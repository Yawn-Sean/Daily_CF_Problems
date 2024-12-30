/*
p 只有 0 和 100 是确定的，中间其他数本质上一样
第一轮：1 打 2，2 到 n 打 1
第二轮：
- 如果 1 2 都挂了：3 打 4，4 到 n 打 3
- 如果 1 挂了：2 打 3，3 到 n 打 2
- 如果 2 挂了：1 到 3，3 到 n 打 1
- 如果 1 2 都没挂：无需考虑，因为局面已经被统计到答案里了
第三轮：
- 第二轮的第一大种情况，比较简单
- 第二轮的第二大种情况，比较简单
- 第二轮的第三大种情况，本质上其实也是一样的
打 k 轮，每轮至多淘汰两个人，所以最后 n - 2 * k 个人一定存活（如果 n > 2 * k）
下面主要就是关心后缀中有没有必杀的，以及是不是全必定打空
最后能存在的方案，大约有 O(n^2) 个，先是有第一个活着的人，然后后面加上一段后缀
*/

int n, k, p[N];
bool must_kill[N], kill_nobody[N];
int dp[N][N];

void meibao() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    kill_nobody[n + 1] = true;
    for (int i = n; i > 0; i--) {
        kill_nobody[i] = (kill_nobody[i + 1] && (p[i] == 0));
    }
    must_kill[n + 1] = false;
    for (int i = n; i > 0; i--) {
        must_kill[i] = (must_kill[i + 1] || (p[i] == 100));
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }
    memset(dp, 0x3f, sizeof dp);
    dp[1][2] = 0;
    queue<PII> q;
    q.push({1, 2});
    int res = 0;
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        int i = s.x, j = s.y;
        if (j >= n + 1) continue;
        if (p[i] > 0 && !must_kill[j]) {
            if (dp[i][j + 1] == INF) {
                dp[i][j + 1] = dp[i][j] + 1;
                q.push({i, j + 1});
            }
        }
        if (!kill_nobody[j] && p[i] != 100) {
            if (dp[j][j + 1] == INF) {
                dp[j][j + 1] = dp[i][j] + 1;
                q.push({j, j + 1});
            }
        }
        if (p[i] > 0 && !kill_nobody[j]) {
            if (dp[j + 1][j + 2] == INF) {
                dp[j + 1][j + 2] = dp[i][j] + 1;
                q.push({j + 1, j + 2});
            }
        }
    }
    for (int i = 1; i <= n + 2; i++) {
        for (int j = i + 1; j <= n + 2; j++) {
            if (dp[i][j] <= k) {
                assert(!(i <= n && j == n + 2));
                res++;
            }
        }
    }
    cout << res << "\n";
}
