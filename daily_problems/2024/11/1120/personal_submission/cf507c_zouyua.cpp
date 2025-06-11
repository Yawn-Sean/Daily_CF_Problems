int main()
{
    ll h, n; cin >> h >> n;
    auto dfs = [&](auto &&dfs, ll l, ll r, int u, int d) ->ll {
        if(u == 0) return 0;
        ll mid = l + r >> 1ll;
        if(n <= mid) {//都向左半区间，下一步是反方向
            if(d == 0)
                return 1 + dfs(dfs, l, mid, u - 1, 1);//当前方向只走一步
            else return  (1ll << u) + dfs(dfs, l, mid, u - 1, 1);//另一边方向需要走完回来
        } else {//右半区间
            if(d == 0) 
                return (1ll << u) + dfs(dfs, mid + 1, r, u - 1, 0);
            else return 1 + dfs(dfs, mid + 1, r, u - 1, 0);
        }

    };
    cout << dfs(dfs, 1, 1ll << h,  h, 0) << endl;
    return 0;
}
