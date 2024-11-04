/*
所有的可能性：sum(k[x]) * n，但是每种可能的概率并不相同
能否单独考虑每个编号的礼物有多少次在前两次中被拿到的概率，然后第三步的概率就好算了
考虑编号为 i 的礼物被取到的概率
假设某个人有 cnt 个礼物，其中有编号为 i 的礼物，则 i 被取到的概率增加 1 / (cnt * n)
假设最终第 i 个礼物被取到的概率是 probs[i]，第 i 个礼物被 need_cnt[i] 个人需要
则 res += probs[i] * need_cnt[i] / n
*/

int T;
LL n;
vector<LL> probs(N, 0), need_cnt(N, 0);

void solve1() {
    cin >> n;
    int mod = MOD2;
    for (int i = 1; i <= n; i++) {
        LL cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; j++) {
            int x;
            cin >> x;
            probs[x] += qpow(cnt * n % mod, mod - 2, mod);
            probs[x] %= mod;
            need_cnt[x]++;
            need_cnt[x] %= mod;
        }
    }
    LL res = 0;
    for (int i = 1; i < N; i++) {
        res += (probs[i] * need_cnt[i] % mod) * qpow(n, mod - 2, mod) % mod;
        res %= mod;
    }
    cout << res << "\n";
}           
