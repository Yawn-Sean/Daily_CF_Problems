/*
cf_1579_E2
https://codeforces.com/problemset/problem/1579/E2
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> t = a;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    
    vector<long long> tr(t.size() + 1);
    auto insert = [&](int i, int c)
    {
        for(; i < tr.size(); i += i & -i)
            tr[i] += c;
    };
    auto query = [&](int i)
    {
        long long res = 0;
        for(; i; i -= i & -i)
            res += tr[i];
            
        return res;
    };
    
    insert(lower_bound(t.begin(), t.end(), a[0]) - t.begin() + 1, 1);
    long long res = 0;
    for(int i = 1; i < n; i++)
    {
        int idx = lower_bound(t.begin(), t.end(), a[i]) - t.begin() + 1;
        long long l = query(idx - 1), r = query(t.size()) - query(idx);
        
        res += min(l, r);
        insert(idx, 1);
    }
    
    cout << res << endl;
}

int main()
{
    int r;
    cin >> r;
    while(r --) solve();

    return 0;
}
