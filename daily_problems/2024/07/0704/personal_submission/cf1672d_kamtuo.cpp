/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-04 11:19 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 223456;

int cnt[N];
int a[N], b[N];
int n;

bool check() {
    int ai = n, bi = n;
    while (ai || bi) {
        if (a[ai] == b[bi]) ai --, bi --;
        else {
            if (a[ai] == a[ai + 1]) cnt[a[ai]] ++, ai --;
            else {
                if (cnt[b[bi]] == 0) return false;
                cnt[b[bi]] --;
                bi --; 
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; i ++) cnt[i] = 0;
        for (int i = 1; i <= n; i ++) {
            cin >> b[i];
        }
        a[n + 1] = 0;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        if (check()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

/*

*/
