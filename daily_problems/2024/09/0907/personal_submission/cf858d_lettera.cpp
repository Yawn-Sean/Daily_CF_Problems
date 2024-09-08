#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < 9; j++)
        {
        	 int cur = 0;
            for (int k = j; k < 9; k++)
            {
                cur = cur * 10 + (a[i][k] - '0');
                if (!mp.count({cur, k - j + 1}) || mp[{cur, k - j + 1}] == i)
                {
                    mp[{cur, k - j + 1}] = i;
                }
                else
                {
                    mp[{cur, k - j + 1}] = -1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        
        int len = 10;
        int id;
        for (int j = 0; j < 9; j++)
        {
        	 int cur = 0;
            for (int k = j; k < 9; k++)
            {
                cur = cur * 10 + (a[i][k] - '0');
                if ( mp[{cur, k - j + 1}] == i)
                {
                    if(k-j+1<len)
                    {
                    	len=k-j+1;
                    	id=j;
                    }
                }
            }
        }
        cout<<a[i].substr(id,len)<<"\n";
    }
}
