#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

const int N = 3010;
int cnt[N], ct[N];
int n, m;
vector<pair<int, int>> v;
bool st[N];
int main()
{
    cin >> n >> m;
    int t = n;
    while (t -- ){
        int a, b;
        cin >> a >> b;
        cnt[a] ++;
        if(a != 1)
        v.push_back({b, a});
    }
    for(int i = 1; i <= m; i ++) ct[i] = cnt[i];
    sort(v.begin(), v.end());
    LL res = N * 1e9;
    for(int x = 0; x < n; x ++)
    {
        int tp = cnt[1];
        LL tans = 0;
        memset(st, 0, sizeof st);
        for(int i = 0; i < v.size(); i ++)
        {
            int a = v[i].first, b = v[i].second;
            if(cnt[b] > x) {
                cnt[b] --;
                tans += a;
                st[i] = true;
                tp ++;
            }
        }
        if(tp > x) res = min(res, tans);
        else{
            for(int i = 0; i < v.size(); i ++)
            {
                int a = v[i].first, b = v[i].second;
                if(!st[i]) {
                    cnt[b] --;
                    tans += a;
                    st[i] = true;
                    tp ++;
                }
                if(tp > x)
                {
                    res = min(res, tans);
                    break;
                }
            }
        }
        for(int i = 1; i <= m; i ++) cnt[i] = ct[i];
    }
    cout << res;
    return 0;
}
