// 排列交换两个数，逆序对的变化为奇数，即逆序对的奇偶性发生改变。
// 3n与7n+1的奇偶性是不同的，所以可以根据逆序对的数量求出是哪个交换。
// 另外也可以先求出最少需要操作的次数（n-环的个数）cnt，3n or 7n+1的操作次数必有一个与cnt奇偶性相同。
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
void solve() 
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    int ans = 0;
    vector<bool> vis(n+1);
    for (int i = 1; i <= n; i ++ ) {
        if (!vis[i]) ans ++;
        while (!vis[a[i]]) {
            vis[a[i]] = 1;
            a[i] = a[a[i]];
        }
    }
    ans = n - ans;
    
    if((ans&1) == (n&1)) {
        cout << "Petr" << endl;
    } else cout << "Um_nik" << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}