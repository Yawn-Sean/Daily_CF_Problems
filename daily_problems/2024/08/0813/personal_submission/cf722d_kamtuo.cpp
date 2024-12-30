/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-13 18:51 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> mp;
    vector a(n, 0);
    priority_queue<int, vector<int>, std::less<int>> p;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        p.push(a[i]);
        mp[a[i]] ++;
    }
    while (!p.empty()) {
        int ok = -1;
        int now = p.top();
        int to = now;
        p.pop();
        while (now) {
            if (mp[now] == 0) ok = max(ok, now);
            now >>= 1;
        }
        if (ok == -1) {
            p.push(to);
            break;
        }
        mp[to] --;
        mp[ok] ++;
        p.push(ok);
    }
    debug(p);
    return 0;
}

#endif

/*

*/
