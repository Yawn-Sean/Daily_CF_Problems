#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> ind(n, vector<int>(26, -1));
    vector<set<int>> ind2(26);
    vector<bool> used(n, 1);
    vector<string> vec(n);
    for (int i = 0; i < n; i++)
    {
        string w;
        cin >> w;
        if (i == 0)
        {
            for (int j = 0; j < w.size(); j++)
            {
                if (ind[i][w[j] - 'a'] != -1)
                {
                    cout << "NO";
                    return 0;
                }
                ind2[w[j] - 'a'].insert(i);
                ind[i][w[j] - 'a'] = j;
            }
        }
        else
        {
            string s1 = "";
            bool flag = 0;
            for (int j = 0; j < w.size(); j++)
            {
                if (ind[i][w[j] - 'a'] != -1)
                {
                    cout << "NO";
                    return 0;
                }
                ind[i][w[j] - 'a'] = j;
            }
            for (int j = 0; j < 26; j++)
            {
                if (ind[i][j] != -1)
                {
                    while (ind2[j].size() > 0)
                    {
                        s1 = "";
                        int a1 = *ind2[j].begin();
                        string w1 = vec[a1];
                        used[a1] = 0;
                        int ind1 = ind[a1][j];
                        for (int k = 0; k < 26; k++)
                        {
                            if (ind[a1][k] != -1)
                            {
                                ind2[k].erase(a1);
                            }
                        }
                        int t1 = min(ind1 + 1, ind[i][j] + 1);
                        int t2 = min(w1.size() - ind1, w.size() - ind[i][j]);
                        for (int k1 = 0; k1 < t1; k1++)
                        {
                            if (w[ind[i][j] - k1] != w1[ind1 - k1])
                            {
                                cout << "NO";
                                return 0;
                            }
                        }
                        for (int k1 = 0; k1 < t2; k1++)
                        {
                            if (w[ind[i][j] + k1] != w1[ind1 + k1])
                            {
                                cout << "NO";
                                return 0;
                            }
                        }
                        for (int k1 = ind[i][j]; k1 >= t1; k1--)
                        {
                            s1 += w[ind[i][j] - k1];
                        }
                        s1 += w1;
                        for (int k1 = ind[i][j] + t2; k1 < w.size(); k1++)
                        {
                            s1 += w[k1];
                        }
                        for (int a = 0; a < 26; a++)
                        {
                            ind[i][a] = -1;
                        }
                        w = s1;
                        for (int a = 0; a < w.size(); a++)
                        {
                            if (ind[i][w[a] - 'a'] != -1)
                            {
                                cout << "NO";
                                return 0;
                            }
                            ind[i][w[a] - 'a'] = a;
                        }
                    }
                }
            }
            for (int j = 0; j < 26; j++)
            {
                if (ind[i][j] != -1)
                {
                    ind2[j].insert(i);
                }
            }
        }
        vec[i] = w;
    }
    vector<string> mass;
    vector<int> cnt(26, 0);
    for (int j = 0; j < n; j++)
    {
        if (used[j])
        {
            for (int k = 0; k < vec[j].size(); k++)
            {
                cnt[vec[j][k] - 'a']++;
                if (cnt[vec[j][k] - 'a'] > 1)
                {
                    cout << "NO";
                    return 0;
                }
            }
            mass.push_back(vec[j]);
        }
    }
    for (int i = 0; i < 26; i++)
    {
        char t = i + 'a';
        for (int j = 0; j < mass.size(); j++)
        {
            if (mass[j][0] == t)
            {
                cout << mass[j];
            }
        }
    }
    return 0;
}
