void solve()
{
    int n, target;
    cin >> n;
    vc<int> a(n);
    fo(i, 0, n)
    {
        cin >> a[i];
        a[i]--;
    }
    cin >> target;
    int swap = n;
    vc<int> vis(n);
    fo(i, 0, n)
    {
        if (!vis[i])
        {
            swap--;
            int j = i;
            while (!vis[j])
            {
                vis[j] = 1;
                j = a[j];
            }
        }
    }
    // cerr<<swap<<endl;
    cout << abs(target - swap) << endl;
    if (swap < target) // 合并环
    {

        while (abs(target - swap))
        {
            fo(i, 0, n) vis[i] = 0;
            int x = -1, y = -1;
            fo(i, 0, n)
            {
                // debug(i);
                if (!vis[i])
                {
                    if (x != -1 && y == -1)
                    {
                        y = i;
                        break;
                    }
                    if (x == -1)
                    {
                        x = i;
                    }

                    int j = i;
                    while (!vis[j])
                    {

                        vis[j] = 1;
                        j = a[j];
                        
                    }
                }
            }
            std::swap(a[x], a[y]);
            //for the purpose of lexicographically
            //every swap should be the base of previous swap
            cout << x + 1 << " " << y + 1 << " ";
            swap++;
        }
    }
    else // 拆分环
    {
        int x = -1, y = -1;
        while (abs(target - swap))
        {
            fo(i, 0, n) vis[i] = 0;
            fo(i, 0, n)
            {
                if (a[i] != i)
                {
                    x = i, y = a[i];
                    int j=i;
                    while(!vis[j])
                    {
                    	if(j!=x) y=min(y,j);
                    	vis[j]=1;
                    	j=a[j];
                    }
                    break;
                }
            }
            std::swap(a[x],a[y]);
            swap--;
            cout << x + 1 << " " << y + 1 << " ";
        }
    }
}
