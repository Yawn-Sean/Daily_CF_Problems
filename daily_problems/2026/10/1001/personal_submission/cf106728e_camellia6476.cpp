#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n, a[110][110];
int red[110][110], blue[110][110];
bool mov[110][110];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<map<int, int>> row(n + 1), col(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            int ii = (a[i][j] + n - 1) / n;
            int jj = (a[i][j] - 1) % n + 1;
            if (ii == i && jj != j)
            {
                mov[ii][jj] = true;
                row[i][jj] = j;
                if (j < jj)
                {
                    blue[i][j]++;
                    blue[i][jj]--;
                }
                else
                {
                    blue[i][jj + 1]++;
                    blue[i][j + 1]--;
                }
            }
            else if (ii != i && jj == j)
            {
                mov[ii][jj] = true;
                col[j][ii] = i;
                if (ii > i)
                {
                    red[ii][j]--;
                    red[i][j]++;
                }
                else
                {
                    red[ii + 1][j]++;
                    red[i + 1][j]--;
                }
            }
            else if (ii != i && jj != j)
            {
                cout << "No";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int last = 0;
        for (auto& [ori, cur] : row[i])
        {
            if (cur < last)
            {
                cout << "No";
                return 0;
            }
            last = cur;
        }
        last = 0;
        for (auto& [ori, cur] : col[i])
        {
            if (cur < last)
            {
                cout << "No";
                return 0;
            }
            last = cur;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            blue[i][j] += blue[i][j - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            red[j][i] += red[j - 1][i];
            if (!mov[j][i] && red[j][i] && blue[j][i])
            {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}