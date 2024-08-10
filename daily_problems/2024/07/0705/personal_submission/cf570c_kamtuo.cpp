/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-05 11:17 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

int sz, cnt;
string s;
int n, m;

int main() {
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '.') {
            if (i == 0 || s[i - 1] != '.') {
                sz ++;
            }
            cnt ++;
        }
    }
    for (int  i = 1; i <= m; i ++) {
        int pos;
        char c;
        cin >> pos;
        pos --;
        getchar();
        c = getchar();
        if (c == '.') {
            if (s[pos] != '.') {
                cnt ++;
                if ((pos != 0 && s[pos - 1] == '.') && (pos != n - 1 && s[pos + 1] == '.')) sz --;
                if ((pos == 0 || s[pos - 1] != '.') && (pos == n - 1 || s[pos + 1] != '.')) sz ++;
            }
        } else {
            if (s[pos] == '.') {
                cnt --;
                if ((pos != 0 && s[pos - 1] == '.') && (pos != n - 1 && s[pos + 1] == '.')) sz ++;
                if ((pos == 0 || s[pos - 1] != '.') && (pos == n - 1 || s[pos + 1] != '.')) sz --;
            }
        }
        s[pos] = c;
        cout << cnt - sz << endl;
    }
    return 0;
}

/*

*/
