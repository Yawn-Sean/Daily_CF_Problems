/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-18 11:23 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 212345, M = 1234567;

int pr[N];
int a[N];
int n, m, k;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        if (a[i] == a[i - 1]) {
            pr[i] = pr[i - 1];
        } else {
            pr[i] = i - 1;
        }
    } 
    for (int i = 1; i <= m; i ++) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if (a[r] != x) cout << r << endl;
        else {
            if (l <= pr[r] && pr[r] <= r) {
                cout << pr[r] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    } 
    return 0;
}

/*

*/
