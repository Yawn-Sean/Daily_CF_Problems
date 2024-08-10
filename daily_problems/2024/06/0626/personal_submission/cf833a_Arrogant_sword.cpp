
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int> vi, int st, int ed)
{
    for (int i = st; i <= ed; i ++ ) cout << vi[i] << ' ';
    cout << endl;
}

void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int N = 1e5 + 10;

void solve(int _) 
{
    int a, b;
    cin >> a >> b;
    int l = 1, r = 1e6 + 10;
    while (l < r) {
        int mid = l + r >> 1;
        if (mid * mid * mid >= a * b) r = mid;
        else l = mid + 1;
    }

    if (r * r * r == a * b && a % r == 0 && b % r == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}