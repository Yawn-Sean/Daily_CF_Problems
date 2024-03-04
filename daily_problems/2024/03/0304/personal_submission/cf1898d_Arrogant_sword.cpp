// 注意绝对值与距离之间的联系！
// 画图分析可得如果两个线段相交，那么交换右端点长度的总和不变
// 所以只有交换两个不相交线段的右端点才能使结果变大，变大的值为2 * 距离,所以只需要找到最大的左端点和最小的右端点即可。
#include<bits/stdc++.h>

#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

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

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i ++ ) cin >> l[i];
    for (int i = 0; i < n; i ++ ) {
        cin >> r[i];
        if (r[i] < l[i]) swap(l[i], r[i]);
    }

    cout << (accumulate(all(r), 0ll) - accumulate(all(l), 0ll) + 2 * max(0ll, *max_element(all(l))-*min_element(all(r)))) << endl;
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