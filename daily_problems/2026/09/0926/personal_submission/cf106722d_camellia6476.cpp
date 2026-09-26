#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string res;

bool check(int cur, int mid)
{
    cout << "? " << cur << ' ' << mid << endl;
    cin >> res;
    if (res[0] == 'Y')
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int mx = n;
    for (int i = 1; i <= n; i++)
    {
        while (check(i, mx))
        {
            if (1 == mx)
            {
                cout << "! 1 " << i << endl;
                return 0;
            }
            mx--;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (check(i, mx + 1))
            ans.push_back(i);
    cout << "! " << ans.size() << ' ';
    for (auto& x : ans)
        cout << x << ' ';
    cout << endl;
    return 0;
}