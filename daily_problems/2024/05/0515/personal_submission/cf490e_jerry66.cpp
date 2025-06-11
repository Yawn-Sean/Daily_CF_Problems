#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
string s[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> s[i];
    s[0] = "0";
    for (int i = 1; i <= n; i ++ )
    {
        if (s[i].size() > s[i-1].size())
        {
            // ?全填0
            for (int k = 0; k < s[i].size(); k ++ )
                if (s[i][k] == '?')
                    if (k) s[i][k] = '0';
                    else s[i][k] = '1';
        }
        else if (s[i].size() < s[i-1].size())
        {
            // 无解
            cout << "NO\n";
            return;
        }
        else
        {
            bool hasDiff = false;
            for (int p = 0; p < s[i].size(); p ++ )
                if (s[i][p] != '?' && s[i-1][p] != s[i][p])
                    hasDiff = true;
            if (!hasDiff)
            {
                // 如果所有非问号都是相同的，那么除了最后一个问号要+1，其他与前面一样
                bool choose = false;
                for (int k = s[i].size() - 1; k >= 0; k -- )
                {
                    if (s[i][k] == '?')
                    {
                        if (!choose)
                        {
                            // 这个要比前面的那个数字大一
                            if (s[i-1][k] == '9') s[i][k] = '0';
                            else s[i][k] = s[i-1][k] + 1, choose = true;
                        }
                        else
                        {
                            s[i][k] = s[i-1][k];
                        }
                    }
                }
            }
            else
            {
                bool isBig = false;
                for (int p = 0; p < s[i].size(); p ++ )
                    if (s[i][p] != '?' && s[i-1][p] != s[i][p])
                    {
                        isBig = s[i][p] > s[i-1][p];
                        
                        // 不同位置为p
                        if (isBig)
                        {
                            // 如果第一个非相同的位置是大的，前面相同，后面为0即可
                            for (int k = p - 1; k >= 0; k -- )
                                if (s[i][k] == '?') s[i][k] = s[i-1][k];
                            for (int k = p + 1; k < s[i].size(); k ++ )
                                if (s[i][k] == '?') s[i][k] = '0';
                        }
                        else
                        {
                            // 如过第一个非相同的位置是小的，前面要大，后面为0
                            bool choose = false;
                            for (int k = p - 1; k >= 0; k -- )
                             {
                                if (s[i][k] == '?')
                                {
                                    if (!choose)
                                    {
                                        // 这个要比前面的那个数字大一
                                        if (s[i-1][k] == '9') s[i][k] = '0';
                                        else s[i][k] = s[i-1][k] + 1, choose = true;
                                    }
                                    else
                                    {
                                        s[i][k] = s[i-1][k];
                                    }
                                }
                            }
                            for (int k = p + 1; k < s[i].size(); k ++ )
                                if (s[i][k] == '?') s[i][k] = '0';
                        }
                        break;
                    }
            }
            if (s[i] <= s[i-1])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i ++ )
        cout << s[i] << '\n';
}

int main()
{
    cin.tie(0) -> ios::sync_with_stdio(false);
    int t;
    // cin >> t;
    t = 1;
    while ( t-- ) solve();
    return 0;
}
