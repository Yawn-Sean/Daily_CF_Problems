/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-24 19:14 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123456;

LL ans = 1;
LL w[N];
int m, n;
LL tot[N];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int x;
        cin >> x >> w[i];
    }
    tot[1] = 1;
    for (int i = 2; i <= m; i ++) {
        tot[i] = 1ll * (i - 1) * i / 2ll + 1ll * (i % 2 == 0) * (i - 2ll) / 2; 
        tot[i] ++;
    }
    sort(w + 1, w + 1 + m, cmp);
    int k = m;
    for (int i = 1; i <= m; i ++) {
        if (tot[i] > n) {
            k = i - 1;
            break;
        }
    }
    LL ans = 0;
    for (int i = 1; i <= k; i ++) {
        ans += w[i];
    }
    cout << ans << endl;
    return 0;
}

/*

*/
