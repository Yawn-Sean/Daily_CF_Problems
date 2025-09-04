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
int sum[N];
void solve()
{
    int n, c;
    cin >> n >> c;
    vector<vector<int>> w(n);
    for(int i = 0 ; i < n; i++){
        int len;
        cin >> len;
        w[i].resize(len);
        for(int j = 0; j < len ;j ++)cin >> w[i][j];
    }
    int cnt = 0;
    for(int i = 0; i < n-1; i ++){
        vector<int> v1 = w[i], v2 = w[i+1];
        int len = min((int)v1.size(), (int)v2.size());
        int ok = 0;
        for(int j = 0; j < len ; j ++){    
            if(v1[j] == v2[j])continue;
            else if(v1[j] > v2[j]){
                sum[c-v1[j]+1]++;
                sum[c-v2[j]+1]--;
                ok = 1;
                break;
            }
            else{
                sum[0]++;
                sum[c-v2[j]+1]--;
                sum[c-v1[j]+1]++;
                sum[c]--;
                ok = 1;
                break;
            }
        }
        if(ok == 0 && v1.size() > v2.size()){
            cout << -1 << '\n';
            return ;
        }
        if(ok == 0)cnt++;
    }
    for(int i = 1; i < c; i ++)sum[i] += sum[i-1];
    for(int i= 0; i < c; i ++){
        if(sum[i] == n-1-cnt){
            cout << i << '\n';
            return ;
        }
    }
    cout << -1 << '\n';
}
signed cute_prov0nce()
{
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
