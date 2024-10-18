/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-27 10:19 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 1512, M = 26;

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    vector s(M, vector (N, 0)), ans(M, vector(N, 0));
    cin >> n;
    string str;
    cin >> str;
    str = "0" + str;
    for (int i = 0; i < 26; i ++) {
        for (int j = 1; j <= n; j ++) {
            int now = str[j] - 'a';
            if (now == i) s[i][j] = 1;
            s[i][j] += s[i][j - 1];
        }
        for (int cnt = 1; cnt <= n; cnt ++) {
            int l = 1;
            for (int j = 1; j <= n; j ++) {
                int now = s[i][j - 1] - j + 1 - cnt;
                // l = max(j, l);
                while (l <= n && s[i][l] - l >= now) l ++;
                l --;
                ans[i][cnt] = max(min(n, l - j + 1), ans[i][cnt]);
            }
        }
    }
    int q;
    cin >> q;
    while (q --) {
        int ni;
        string k;
        cin >> ni >> k;
        cout << ans[k[0] - 'a'][ni] << endl;
    }
    return 0;
}

/*

*/
