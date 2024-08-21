/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-20 15:45 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(n + 1, 0);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int cnt1 = 1, cntn = 1;
    for (int i = 2; i <= n; i ++) {
        if (a[i] > a[i - 1]) cnt1 ++; 
        else break;
    }
    for (int i = n - 1; i; i --) {
        if (a[i] > a[i + 1]) cntn ++;
        else break;
    }
    if (cnt1 % 2 || cntn % 2) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    return 0;
}

#endif

/*

*/
