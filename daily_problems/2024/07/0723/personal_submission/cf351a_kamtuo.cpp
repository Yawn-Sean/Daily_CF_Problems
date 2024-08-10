/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-23 17:21 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 21234;

double a[N];

int main() {
    int n;
    cin >> n;
    double sum = 0;
    int now = 0;
    for (int i = 1; i <= 2 * n; i ++) {
        cin >> a[i];
        a[i] -= floor(a[i]);
        sum += a[i];
        if (a[i] <= 1e-6) now ++; 
    }
    double ans = 2.0 * n;
    for (int i = max(n - now, 0); i <= min(2 * n - now, n); i ++) {
        ans = min(ans, fabs(1.0 * i - sum));
    }
    printf("%.3lf", ans);
    return 0;
}

/*

*/
