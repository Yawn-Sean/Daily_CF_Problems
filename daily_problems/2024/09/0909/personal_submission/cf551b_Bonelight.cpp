#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    string a,b,c; cin >> a >> b >> c;
    vector<int> cnt1(26);
    vector<int> cnt2(26);
    vector<int> cnt3(26);

    for(auto i:a) cnt1[i - 'a']++;
    for(auto i:b) cnt2[i - 'a']++;
    for(auto i:c) cnt3[i - 'a']++;

    int sum = 0;
    int b_num = 0, c_num = 0;
    for(int cnt_1 = 0; cnt_1 < a.size(); cnt_1 ++){
        vector<int> t_cnt = cnt1;
        int ok = 1;
        for(int i = 0; i < 26; i ++){
            t_cnt[i] -= cnt2[i] * cnt_1;
            if(t_cnt[i] < 0) {ok = 0; break;}
        }
        if(ok == 0) break;

        int cnt_2 = 2e18;
        for(int i = 0; i < 26; i ++){
            if(cnt3[i] == 0) continue;
            int tmp = t_cnt[i] / cnt3[i];
            cnt_2 = min(cnt_2, tmp);
        }
        if(sum < cnt_1 + cnt_2){
            b_num = cnt_1, c_num = cnt_2;
            sum = cnt_1 + cnt_2;
        }
    }

    for(int i = 0; i < 26; i ++){
        cnt1[i] -= cnt2[i] * b_num + cnt3[i] * c_num;
    }

    string ans = "";
    
    for(int i = 0; i < b_num; i ++) ans += b;
    for(int i = 0; i < c_num; i ++) ans += c;
    for(int i = 0; i < 26; i ++){
        ans += string(cnt1[i],'a' + i);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
