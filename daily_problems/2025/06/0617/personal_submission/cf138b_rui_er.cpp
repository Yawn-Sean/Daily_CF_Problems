string s;
int cnt[10], cnt1[10], cnt2[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for(char c: s) ++cnt[c - '0'];
    int best = -1, val = cnt[0];
    rep(s, 1, 5) {
        rep(d, 0, 9) cnt1[d] = cnt2[d] = cnt[d];
        if(cnt1[s] && cnt2[10 - s]) {
            --cnt1[s];
            --cnt2[10 - s];
            int now = 1;
            rep(d, 0, 9) {
                int tmp = min(cnt1[d], cnt2[9 - d]);
                now += tmp;
                cnt1[d] -= tmp;
                cnt2[9 - d] -= tmp;
            }
            now += min(cnt1[0], cnt2[0]);
            if(now > val) val = now, best = s;
        }
    }
    rep(d, 0, 9) cnt1[d] = cnt2[d] = cnt[d];
    string ans1, ans2;
    if(best != -1) {
        --cnt1[best];
        --cnt2[10 - best];
        ans1 += char(best + '0');
        ans2 += char(10 - best + '0');
        rep(d, 0, 9) {
            while(cnt1[d] && cnt2[9 - d]) {
                --cnt1[d];
                --cnt2[9 - d];
                ans1 += char(d + '0');
                ans2 += char(9 - d + '0');
            }
        }
    }
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    while(cnt1[0] && cnt2[0]) {
        --cnt1[0];
        --cnt2[0];
        ans1 += '0';
        ans2 += '0';
    }
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    rep(d, 0, 9) while(cnt1[d]--) ans1 += char(d + '0');
    rep(d, 0, 9) while(cnt2[d]--) ans2 += char(d + '0');
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
