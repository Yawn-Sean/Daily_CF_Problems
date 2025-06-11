/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-06 15:36 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 512;

int n;

int main() {
    int n;
    cin >> n;
    int sx = 1, sy = 1;
    string s;
    string ans;
    string ans2;
    for (int i = 1; i <= n - 1; i ++) {
        cout << "? " << sx + 1 << ' ' << sy << ' ' << n << ' ' << n << endl;
        cin >> s;
        if (s == "YES") {
            mp[sx + 1][sy] = 1;
            sx = sx + 1;
            ans.push_back('D');
        } else {
            mp[sx][sy + 1] = 1;
            sy = sy + 1;
            ans.push_back('R');
        }
    }
    int ex = n, ey = n;
    for (int i = 1; i <= n - 1; i ++) {
        cout << "? " << 1 << ' ' << 1 << ' ' << ex << ' ' << ey - 1 << endl;
        cin >> s;
        if (s == "YES") {
            mp[ex][ey - 1] = 1;
            ey = ey - 1;
            ans2.push_back('R');
        } else {
            mp[ex - 1][ey] = 1;
            ex = ex - 1;
            ans2.push_back('D');
        }
    }
    reverse(ans2.begin(), ans2.end());
    cout << "!" << ' ';
    cout << ans << ans2 << endl;
    return 0;
}

/*

*/
