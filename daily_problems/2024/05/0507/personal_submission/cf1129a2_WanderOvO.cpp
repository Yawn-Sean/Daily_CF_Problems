/*
假如某个火车站有 cnt 个糖果，则至少需要跑 cnt 圈才能把这个站所有的糖果送完
其实我们只关心最大的 cnt 的那些车站的最后 1 个糖果选谁
以及个数为 cnt - 1 的那些车站的最后一个糖果选谁
对于 cnt - 1 的最后一个，显然我们想选不会进入下一圈的，如果没有，则选下一圈终点最近的
对于 cnt 的最后一个，其最好不要进下一圈，尽可能近
*/

int T;
LL n, m;
LL cnt[N], mn[N];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        mn[i] = n;
        cnt[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        LL st, ed;
        cin >> st >> ed;
        if (ed < st) {
            ed += n;
        }
        mn[st] = min(mn[st], ed - st);
        cnt[st]++;
    }
    LL mxcnt = 0;
    for (int i = 1; i <= n; i++) {
        mxcnt = max(cnt[i], mxcnt);
    }
    
    for (int st = 1; st <= n; st++) {
        LL t = 0;
        for (int i = st; i <= n; i++) {
            // 先走到 i 位置，再走若干圈，最后一圈走
            if (mxcnt == cnt[i]) {
                t = max(t, i - st + (mxcnt - 1) * n + mn[i]);
            } else if (mxcnt - 1 == cnt[i] && cnt[i] > 0) {
                t = max(t, i - st + (mxcnt - 2) * n + mn[i]);
            }
        }
        for (int i = 1; i < st; i++) {
            if (mxcnt == cnt[i]) {
                t = max(t, i + n - st + (mxcnt - 1) * n + mn[i]);
            } else if (mxcnt - 1 == cnt[i] && cnt[i] > 0) {
                t = max(t, i + n - st + (mxcnt - 2) * n + mn[i]);
            }
        }
        cout << t << " ";
    }
}       