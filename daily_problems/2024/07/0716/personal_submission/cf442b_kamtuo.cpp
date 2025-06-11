/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-16 17:20 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123;

priority_queue<double> q;
double ans;
double a[N];

bool cmp(double x, double y) {
    return x > y;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i ++) {
        double res = 0;
        for (int j = 1; j <= i; j ++) {
            double now = a[j];
            for (int k = 1; k <= i; k ++) {
                if (j == k) continue;
                now *= (1.0 - a[k]);
            }
            res += now;
        }
        ans = max(ans, res);
    }
    printf("%.12lf\n", ans);
    return 0;
}

/*

*/
