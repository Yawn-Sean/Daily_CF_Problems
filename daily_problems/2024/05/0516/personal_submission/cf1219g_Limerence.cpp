#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long min1(long long a, long long b)
{
    return a < b ? a : b;
}

long long max1(long long a, long long b)
{
    return a > b ? a : b;
}

long long large2(vector<long long> &iter)
{
    long long v1 = 0, v2 = 0;
    for (long long x : iter)
    {
        if (x >= v1)
        {
            v2 = v1;
            v1 = x;
        }
        else if (x > v2)
        {
            v2 = x;
        }
    }
    return v1 + v2;
}

long long large3(vector<long long> &iter)
{
    long long v1 = 0, v2 = 0, v3 = 0;
    for (long long x : iter)
    {
        if (x >= v1)
        {
            v3 = v2;
            v2 = v1;
            v1 = x;
        }
        else if (x >= v2)
        {
            v3 = v2;
            v2 = x;
        }
        else if (x > v3)
        {
            v3 = x;
        }
    }
    return v1 + v2 + v3;
}

long long large4(vector<long long> &iter)
{
    long long v1 = 0, v2 = 0, v3 = 0, v4 = 0;
    for (long long x : iter)
    {
        if (x >= v1)
        {
            v4 = v3;
            v3 = v2;
            v2 = v1;
            v1 = x;
        }
        else if (x >= v2)
        {
            v4 = v3;
            v3 = v2;
            v2 = x;
        }
        else if (x >= v3)
        {
            v4 = v3;
            v3 = x;
        }
        else if (x > v4)
        {
            v4 = x;
        }
    }
    return v1 + v2 + v3 + v4;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> grid(n, vector<long long>(m));
    vector<long long> row_sum(n, 0), col_sum(m, 0);

    for (long long i = 0; i < n; ++i)
    {
        for (long long j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
        }
    }

    if (min1(n, m) <= 4)
    {
        long long sum = 0;
        for (long long x : row_sum)
            sum += x;
        cout << sum << endl;
        return 0;
    }

    long long ans_rows = large4(row_sum);
    long long ans_cols = large4(col_sum);
    long long ans_1row_3cols = 0;
    for (long long i = 0; i < n; ++i)
    {
        for (long long j = 0; j < m; ++j)
        {
            col_sum[j] -= grid[i][j];
        }
        ans_1row_3cols = max1(ans_1row_3cols, row_sum[i] + large3(col_sum));
        for (long long j = 0; j < m; ++j)
        {
            col_sum[j] += grid[i][j];
        }
    }

    long long ans_3rows_1col = 0;
    for (long long i = 0; i < m; ++i)
    {
        for (long long j = 0; j < n; ++j)
        {
            row_sum[j] -= grid[j][i];
        }
        ans_3rows_1col = max1(ans_3rows_1col, col_sum[i] + large3(row_sum));
        for (long long j = 0; j < n; ++j)
        {
            row_sum[j] += grid[j][i];
        }
    }

    long long ans_2rows_2cols = 0;
    if (n <= m)
    {
        for (long long i = 0; i < n; ++i)
        {
            for (long long j = i + 1; j < n; ++j)
            {
                vector<long long> temp_col_sum = col_sum;
                for (long long k = 0; k < m; ++k)
                {
                    temp_col_sum[k] -= grid[i][k] + grid[j][k];
                }
                ans_2rows_2cols = max1(ans_2rows_2cols, row_sum[i] + row_sum[j] + large2(temp_col_sum));
            }
        }
    }
    else
    {
        for (long long i = 0; i < m; ++i)
        {
            for (long long j = i + 1; j < m; ++j)
            {
                vector<long long> temp_row_sum = row_sum;
                for (long long k = 0; k < n; ++k)
                {
                    temp_row_sum[k] -= grid[k][i] + grid[k][j];
                }
                ans_2rows_2cols = max1(ans_2rows_2cols, col_sum[i] + col_sum[j] + large2(temp_row_sum));
            }
        }
    }

    cout << max({ans_rows, ans_cols, ans_1row_3cols, ans_3rows_1col, ans_2rows_2cols}) << endl;
    return 0;
}
