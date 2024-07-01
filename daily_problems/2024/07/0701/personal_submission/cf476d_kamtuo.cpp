/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-01 18:24 */
/* Software : Visual Studio Code    */
/*----------------------------------*/


int main() {
    int n, k;
    cin >> n >> k;
    cout << (5 + (6 * (n - 1))) * k << endl;
    for (int i = 1; i <= n; i ++) {
        cout << (1 + (6 * (i - 1))) * k << ' ' << ((3 + (6 * (i - 1)))) * k << ' ' << ((5 + (6 * (i - 1)) - 1)) * k << ' ' << (5 + (6 * (i - 1))) * k << endl;
    }
    return 0;
}

/*

*/
