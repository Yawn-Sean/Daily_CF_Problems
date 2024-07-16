/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-09 17:19 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 51234;

int n;
string s1, s2;
vector<int> cnt[N];
int sum;

int main() {
    cin >> n;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i ++) {
        cnt[s1[i] - '0' + s2[i] - '0'].push_back(i + 1);
        sum += s2[i] - '0';
    }
    bool ok = false;
    for (int i2 = 0; i2 <= cnt[2].size(); i2 ++) {
        int i1 = sum - 2 * i2, i0 = n / 2 - i1 - i2;
        if (i1 >= 0 && i1 <= cnt[1].size() && i0 >= 0 && i0 <= cnt[0].size()) {
            for (int i = 0; i < i1; i ++) cout << cnt[1][i] << ' ';
            for (int i = 0; i < i2; i ++) cout << cnt[2][i] << ' ';
            for (int i = 0; i < i0; i ++) cout << cnt[0][i] << ' ';
            ok = true;
            break;
        }
    } 
    if (!ok) cout << -1 << endl;
    return 0;
}

/*

*/
