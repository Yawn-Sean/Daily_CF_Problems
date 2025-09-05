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
    int h;
    cin >> h;
    vector<int> a(h+1);
    int cnt = 0;
    for(int i = 0; i <=h; i ++)cin >> a[i], cnt += a[i];
    int ok = 0;
    for(int i = 0 ;i < h; i ++){
        if(a[i] >= 2 && a[i+1] >= 2){
            ok = 1;
            break;
        }
    }
    vector<int> p(cnt+1);
    if(ok == 0){
        cout << "perfect" << '\n';
        return;
    }
    else cout << "ambiguous" << '\n';
    int id = 1;
    for(int i = id; i < id + a[0]; i ++)p[i] = 0;
    id += a[0];
    for(int i = 1; i <=h; i ++){
        if(a[i] >= 2 && a[i-1] >= 2){
            p[id] = id-2;
            for(int j = id+1; j < id + a[i]; j ++)p[j] = id-1;
        }
        else if(a[i] >= 2){
            for(int j = id; j < id + a[i]; j ++)p[j] = id-1;
        }
        else if(a[i-1] >= 2){
            p[id] = id-1;
        }   
        else{
            p[id] = id-1;
        }
        id += a[i];
    }
    for(int i = 1; i <= cnt ;i ++)cout << p[i] <<' ';
    cout << '\n';
    id = 1;
    for(int i = id; i < id + a[0]; i ++)p[i] = 0;
    id += a[0];
    for(int i = 1; i <=h; i ++){
        if(a[i] >= 2 && a[i-1] >= 2){
            for(int j = id; j < id + a[i]; j ++)p[j] = id-1;
        }
        else if(a[i] >= 2){
            for(int j = id; j < id + a[i]; j ++)p[j] = id-1;
        }
        else if(a[i-1] >= 2){
            p[id] = id-1;
        }   
        else{
            p[id] = id-1;
        }
        id += a[i];
    }
    for(int i = 1; i <= cnt ;i ++)cout << p[i] <<' ';
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
