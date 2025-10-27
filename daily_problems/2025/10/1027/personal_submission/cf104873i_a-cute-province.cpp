#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a[n];
    int j = 0;
    auto work = [&](int st)->void{
    	int ed = min(n, st + n/2-1);
        cout << "? " << (ed-st+1)*2 << ' ';
        for(int i = st; i <= ed ; i ++){
            cout << i <<' ' << i <<' ';
        }
        cout << endl;
        int k;
        cin >> k;
        int cnt = 0;
        vector<int> ve(k+1);
        for(int i = 1; i <= k; i ++)cin >> ve[i];
        
        for(int i = 1; i <= k ;i ++){ 
            mp[ve[i]]++;
            if(mp[ve[i]] == 2){
                j++;
                i += cnt-1;
                cnt = 0;
                mp.clear();
                continue;
            }   
            a[j].emplace_back(ve[i]);
            cnt ++;
        }

    };
    if(n == 1){
       	cout << "? 1 1" <<endl;
       	
       	int k;
       	cin >> k;
       	vector<int> ans(k);
       	for(auto &x : ans)cin >> x;
       	cout << "! " << ans.size() <<' ';
       	for(auto &x : ans)cout <<x <<' ';
       	cout << endl;
       	return ;
    }
    else{
        for(int i = 1; i <= n; i+=n/2){
            work(i);
        }
    }
    cout << "! ";
    for(auto v : a){
        cout << v.size() <<' ';
        for(auto u : v)cout << u <<' ';
    }
    cout << endl;

}
int cute_prov0nce()
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
