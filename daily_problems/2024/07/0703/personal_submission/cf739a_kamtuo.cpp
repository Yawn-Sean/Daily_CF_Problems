/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-03 11:39 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123456;

int n, m;
int k;

int main() {
    cin >> n >> m;
    k = n;
    for (int i = 1; i <= m; i ++) {
        int l, r;
        cin >> l >> r;
        k = min(r - l + 1, k);
    }
    cout << k << endl;
    for (int i = 0; i < n; i ++) {
        cout << (i % k) << " \n"[i == n - 1];
    }
    return 0;
}

/*

*/
