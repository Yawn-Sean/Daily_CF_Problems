/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-31 19:15 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, k;
    cin >> n >> k;
    vector cnt(140, 0);
    int dx = 20;
    // debug(1ll << 62);
    int tot = 0;
    for (int i = 0; i < 62; i ++) {
        if ((n >> i) % 2) cnt[i + dx] ++, tot ++; 
        debug(n >> i);
    }
    if (tot > k) {
        cout << "No" << endl;
    } else {
        int now = dx + 61;
        while (tot < k) {
            if (cnt[now] + tot <= k) {
                tot += cnt[now];
                cnt[now - 1] += 2 * cnt[now];
                cnt[now] = 0;
            } else {
                break;
            } 
            now --;
        }
        if (tot != k) {
            for (int i = now; i >= 0; i --) {
                if (cnt[i]) {
                    now = i;
                    // break;
                }
            }
            cout << "Yes" << endl;
            // tot += cnt[now] - 1;
            cnt[now] --;
            for (int i = dx + 61; i >= now; i --) {
                while (cnt[i]) {
                    cout << i - dx << ' ';
                    cnt[i] --;
                }
            }
            for (int i = 1; i < k - tot; i ++) {
                cout << now - dx - i << ' ';
            }
            cout << now - dx - k + tot << ' ' << now - dx - k + tot;
        } else {
            cout << "Yes" << endl;
            for (int i = dx + 61; i >= 0; i --) {
                while (cnt[i]) {
                    cout << i - dx << ' ';
                    cnt[i] --;
                }
            }
        }
    }
    return 0;
}


/*

*/
