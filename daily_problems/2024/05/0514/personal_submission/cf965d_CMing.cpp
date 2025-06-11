#include<bits/stdc++.h>
using namespace std;

int main()
{
    int w, k; cin >> w >> k;
    vector<int> h(w);
    for(int i = 1; i < w; i++) cin >> h[i];
    int now = 0;
    for(int i = 1; i <= k; i++) now += h[i];
    int ans = 1e9;
    ans = min(ans, now);
    for(int i = k + 1; i < w; i++)
    {
        now -= h[i - k];
        now += h[i];
        ans = min(ans, now);
    }

    cout << ans;
}
