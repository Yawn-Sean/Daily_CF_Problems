#include<bits/stdc++.h>
using namespace std;
const int N = 17;
const int inf = 1e8;

int ans = 0;
void init(vector<vector<int>>& f, vector<pair<int, int>>& a)
{
    for(int k = 0; k < N; k++)
        for(int i = 0; i + (1 << k) - 1 < a.size(); i++)
            if(k == 0) f[i][k] = a[i].second;
            else f[i][k] = max(f[i][k - 1], f[i + (1 << k - 1)][k - 1]);
}

int ask(int l, int r, const vector<vector<int>>& f)
{
    if(l > r) return -inf; 
    int len = r - l + 1;
    int k = log2(len);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

void find(const vector<vector<int>>& fc, const vector<pair<int, int>>& C, const int c)
{
    for(int i = 0; i < C.size(); i++)
    {
        if(c >= C[i].first)
        {
            auto it = upper_bound(C.begin() + i, C.end(), make_pair(c - C[i].first, inf)) - C.begin();
            ans = max(ans, ask(i + 1, it - 1, fc) + C[i].second);
        }
        else break;
    }
}
int main()
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<pair<int, int>> C, D;

    for(int i = 1; i <= n; i++)
    {
        int b, p; char ch;
        cin >> b >> p >> ch;
        if(ch == 'C') C.push_back({p, b});
        else D.push_back({p, b});
    }

    sort(C.begin(), C.end()), sort(D.begin(), D.end());

    vector<vector<int>> fc(C.size(), vector<int>(N)), fd(D.size(), vector<int>(N));
    init(fc, C), init(fd, D);
    find(fc, C, c), find(fd, D, d);

    auto it = upper_bound(C.begin(), C.end(), make_pair(c, inf)) - C.begin();
    int a = ask(0, it - 1, fc);
    it = upper_bound(D.begin(), D.end(), make_pair(d, inf)) - D.begin();
    int b = ask(0, it - 1, fd);
    ans = max(ans, a + b);
    cout << ans;
}
