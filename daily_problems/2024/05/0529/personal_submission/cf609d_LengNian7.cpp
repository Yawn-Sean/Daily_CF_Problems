#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> nums1(n), nums2(n), ts(m), cs(m), idxs1(n), idxs2(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums1[i];
        idxs1[i] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> nums2[i];
        idxs2[i] = i;
    }

    for (int i = 1; i < n; ++i)
    {
        if (nums1[i] > nums1[i - 1])
        {
            nums1[i] = nums1[i - 1];
            idxs1[i] = idxs1[i - 1];
        }
        if (nums2[i] > nums2[i - 1])
        {
            nums2[i] = nums2[i - 1];
            idxs2[i] = idxs2[i - 1];
        }
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> ts[i] >> cs[i];
    }

    vector<int> c1, c2;
    for (int i = 0; i < m; ++i)
    {
        if (ts[i] == 1)
        {
            c1.push_back(cs[i]);
        }
        else
        {
            c2.push_back(cs[i]);
        }
    }
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());

    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int pt1 = 0, pt2 = 0;
        long long tot = 0;

        for (int i = 0; i < k; ++i)
        {
            if (pt1 == c1.size())
            {
                tot += (long long)c2[pt2++] * nums2[mid - 1];
            }
            else if (pt2 == c2.size())
            {
                tot += (long long)c1[pt1++] * nums1[mid - 1];
            }
            else if ((long long)c1[pt1] * nums1[mid - 1] < (long long)c2[pt2] * nums2[mid - 1])
            {
                tot += (long long)c1[pt1++] * nums1[mid - 1];
            }
            else
            {
                tot += (long long)c2[pt2++] * nums2[mid - 1];
            }
        }

        if (tot <= s)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (l == n + 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << l << endl;
        int buy1 = idxs1[l - 1];
        int buy2 = idxs2[l - 1];
        vector<long long> cur;
        for (int i = 0; i < m; ++i)
        {
            if (ts[i] == 1)
            {
                cur.push_back((long long)nums1[l - 1] * cs[i] * m + i);
            }
            else
            {
                cur.push_back((long long)nums2[l - 1] * cs[i] * m + i);
            }
        }
        sort(cur.begin(), cur.end());
        vector<string> ans;
        for (int i = 0; i < k; ++i)
        {
            int idx = cur[i] % m;
            if (ts[idx] == 1)
            {
                ans.push_back(to_string(idx + 1) + " " + to_string(buy1 + 1));
            }
            else
            {
                ans.push_back(to_string(idx + 1) + " " + to_string(buy2 + 1));
            }
        }
        for (const string &a : ans)
        {
            cout << a << endl;
        }
    }

    return 0;
}
