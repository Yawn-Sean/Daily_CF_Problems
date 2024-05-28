// https://codeforces.com/contest/900/submission/262345702
int n, m;
int p[MAXN], maxv[MAXN];
bool isRec[MAXN]; 
int cnt[MAXN];  //p[i]右侧有cnt[i]个数字y满足：y小于p[i]且y右侧只有p[i]一个比y大
void sol()
{
    cin >> n;
    int old = 0;    // 本来的record数量
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        maxv[i] = max(maxv[i - 1], p[i]);   // p[1, i]中的最大值maxv[i]
        if (maxv[i] == p[i]) {  // p[i]是一个record
            isRec[i] = true;
            old++;
        }
    }
    map<int, int> ord;
    ord[p[1]] = 1;
    for (int i = 2; i <= n; i++) {
        int cur = p[i];
        auto last = prev(ord.end());
        auto llast = prev(last);
        if ((ord.size() == 1 && cur < last->first) || (cur < last->first && cur > llast->first))
            cnt[last->first]++;
        ord[cur] = 1;
    }
    int ans = p[1], num = 1;
    for (int i = 1; i <= n; i++) {
        int cur = p[i], tmp = old;
        if (isRec[i]) {
            tmp--;
        } 
        tmp += cnt[cur];
        if ((tmp > num) || (tmp == num && cur < ans)) {
            ans = cur;
            num = tmp;
        }
    }   
    cout << ans << '\n';
}
