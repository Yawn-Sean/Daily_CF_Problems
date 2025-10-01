#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;

void solve() {
    int n,l,r;
    cin >> n >>l >> r;
    deque<char> dq;
    stack<char> L, R;
    string s;
    cin >> s;
    int m;
    cin >> m;
    s = " " + s;
    for(int i = 1; i < l; i ++)L.push(s[i]);
    for(int i = n; i > r; i--)R.push(s[i]);
    for(int i = l; i <= r; i ++)dq.push_back(s[i]);
    int fl = 0;
    while(m --){
        char op, x, y;
        cin >> op;
        if(op == 'S'){
            cin >> x >> y;
            if(fl == 0){
                if(x == 'L'){
                    if(y == 'L')dq.push_front(L.top()), L.pop(),l--;
                    else L.push(dq.front()), dq.pop_front(),l++;
                }
                else{
                    if(y == 'R')dq.push_back(R.top()), R.pop(),r++;
                    else R.push(dq.back()), dq.pop_back(),r--;
                }
            }
            else{
                if(x == 'L'){
                    if(y == 'L')dq.push_back(L.top()), L.pop(),l--;
                    else L.push(dq.back()), dq.pop_back(),l++;
                }
                else{
                    if(y == 'R')dq.push_front(R.top()), R.pop(),r++;
                    else R.push(dq.front()), dq.pop_front(),r--;
                }
            }
            
        }
        else if(op == 'R')fl ^= 1;
        else{
            cin >> x;
            if(fl == 0){
                if(x == 'L')cout << dq.front() ;
                else cout << dq.back() ;
            }
            else{
                if(x == 'L')cout << dq.back() ;
                else cout << dq.front() ;
            }
        }
    }

}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
