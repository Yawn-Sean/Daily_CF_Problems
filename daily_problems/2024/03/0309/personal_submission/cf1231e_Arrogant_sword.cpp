// 变 -> 不变。最后哪些位置不会变动呢？
// 每次操作都是把一个字母放在开头或者结尾，那么最后剩下的字母在t中必然是一个连续的字串。
// 所以问题转化为求s的最长子序列满足其是t的字串。数据范围很小，暴力枚举起点匹配就行了。

#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////

void solve() 
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> cnt(26);
    for (char c: s) cnt[c-'a'] ++;
    for (char c: t) cnt[c-'a'] --;

    if (*min_element(all(cnt)) != 0) {
        cout << -1 << endl;
        return;
    }

    int mx = 0;
    for (int i = 0; i < n; i ++ ) {
        int tmx = 0;
        int j = i;
        for (int k = 0; k < n; k ++ ) {
            if (t[j] == s[k]) {
                tmx ++;
                j ++;
            }
        }
        mx = max(mx, tmx);
    }

    cout << n - mx << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    while (T --) {
        solve();
    }
    
}