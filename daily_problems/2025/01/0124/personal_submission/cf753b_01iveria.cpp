#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdi = pair<double, int>;
using pdd = pair<double, double>;

const ll inf = 1e18;
const int N = 2e5 + 10;
// 假如我现在知道这四个数了
pii ask(string s)
{
    cout << s << '\n';
    fflush(stdout);
    int x , y;cin >> x >> y;
    return {x , y};
}
void out(string s)
{
    cout << s << '\n';
    fflush(stdout);
}
int main()
{
    vector<int>v;// 哪四个数
    for(int i = 0;i <= 9;i++)
    {
        string temp;
        for(int j = 1;j <= 4;j++) temp += (char) ('0' + i);
        auto it = ask(temp);
        if(it.second != 0 || it.first != 0) v.push_back(i);
    }
    sort(begin(v) , end(v));
    int cnt = 0;
    for(auto t : v) cnt += (t == cnt); // 不存在的数
    string temp;
    string ans = "0000";
    for(int i = 1;i <= 4;i++) temp += (char) ('0' + cnt);
    for(auto now : v)
    {
        for(int i = 0;i < 4;i++)
        {
            string tmp = temp;
            tmp[i] = (char) ('0' + now);
            auto it = ask(tmp);
            if(it.first == 1)
            {
                ans[i] = ('0' + now);
                break;
            }
        }
    }
    out(ans);
    return 0;
}
