/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-27 15:32 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    struct Node {
        int x, y, z;
        int i;
        bool operator < (const Node& now) const {
            if (x != now.x) return x < now.x;
            if (y != now.y) return y < now.y;
            return z < now.z;
        }
    };
    int n;
    cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].i = i + 1;
    }
    sort(a.begin(), a.end());
    vector st(n, 0);
    for (int i = 1; i < n; i ++) {
        if (a[i].x == a[i - 1].x && a[i].y == a[i - 1].y) {
            st[i] = st[i - 1] = 1;
            cout << a[i - 1].i << ' ' << a[i].i << endl;
            i ++;
        }
    }
    vector<Node> v;
    for (int i = 0; i < n; i ++) {
        if (st[i] == 0) {
            v.push_back(a[i]);
        }
        st[i] = 0;
    }
    for (int i = 1; i < v.size(); i ++) {
        if (v[i].x == v[i - 1].x) {
            st[i] = st[i - 1] = 1;
            cout << v[i - 1].i << ' ' << v[i].i << endl;
            i ++;
        }
    }
    vector<Node> v2;
    for (int i = 0; i < v.size(); i ++) {
        if (st[i] == 0) {
            v2.push_back(v[i]);
        }
    }
    for (int i = 1; i < v2.size(); i += 2) {
        cout << v2[i - 1].i << ' ' << v2[i].i << endl;
    }
    return 0;
}

#endif

/*

*/
