#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e3+10; 
const int mod = 1e9 + 7;
void solve()
{
    int n, a ,b;
    cin >> n >> a >> b;
    vector<int> t(n), f(n), ve;
    for(int i = 0; i <n; i ++)cin >> t[i],ve.emplace_back(t[i]);
    sort(ve.begin(), ve.end());
    if(a == b){
        for(int i = 1; i <= a; i ++)cout << 1 <<' ';
        for(int i = 1; i <= a; i ++)cout << 2 <<' ';
    }
    else if(a < b){
        int p = ve[b];
        for(int i = 0; i < n; i++){
            if(t[i] > p){
                f[i] = 1;
                a--;
            }
            if(a == 0)break;
        }
        for(int i = 0; i < n; i++){
            if(t[i] == p){
                f[i] = 1;
                a--;
            }
            if(a == 0)break;
        }
        for(int i = 0; i < n; i++){
            if(!f[i])cout << 2 << ' ';
            else cout << 1 << ' ';
        }
        
    }
    else{
        int p = ve[a-1];
        for(int i = 0; i < n; i++){
            if(t[i] < p){
                f[i] = 1;
                a--;
            }
            if(a == 0)break;
        }
        for(int i = 0; i < n; i++){
            if(t[i] == p){
                f[i] = 1;
                a--;
            }
            if(a == 0)break;
        }
        for(int i = 0; i < n; i++){
            if(!f[i])cout << 2 << ' ';
            else cout << 1 << ' ';
        }
    }

    

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
