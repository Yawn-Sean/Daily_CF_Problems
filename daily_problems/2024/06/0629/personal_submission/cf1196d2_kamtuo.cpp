/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-06-29 13:12 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 223456;

int n, k;
string s;
int a[N][4];

int main() {
    string s1 = "RGB";
    string s2 = "GBR";
    string s3 = "BRG";
    while (s1.size() < N) s1 += s1, s2 += s2, s3 += s3; 
    int t;
    cin >> t;
    while (t --) {
        cin >> n >> k;
        cin >> s;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= 3; j ++) {
                a[i][j] = 0;
            }
        }
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] != s1[i]) a[i + 1][1] = 1;
            if (s[i] != s2[i]) a[i + 1][2] = 1;
            if (s[i] != s3[i]) a[i + 1][3] = 1;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= 3; j ++) {
                a[i][j] += a[i - 1][j];
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = k; i <= n; i ++) {
            for (int j = 1; j <= 3; j ++) ans = min(a[i][j] - a[i - k][j], ans);
        }
        cout << ans << endl;
    }
    return 0;
}

/*

*/
