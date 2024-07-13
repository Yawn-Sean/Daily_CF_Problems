int n, m, k;

char a[N][N];

void solve()
{
    for (int i = 0; i <= 110; i ++ )
        for (int j = 0; j <= 110; j ++ )
            a[i][j] = '-';
            
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            if (a[i][j] != '-') continue;
            for (char c = 'A'; c <= 'Z'; c ++ )
            {
                // 试填
                int l = j, r = j;
                int tp = i, btm = i;
                
                // 大括号里面这部分，是如果把当前点变成字符c，那么上下左右只要跟这个字符相同
                // 就会被搞成同一个联通块
                // 通过不同方向的把 周围正方形的 边角找到
                // 把周围连通块的角落都找到，那么这部分就必然应该全是c
                {
                    int x = i, y = j;
                    // 先上再左
                    while (x - 1 >= 1 && a[x - 1][y] == c) x -- ;
                    while (y - 1 >= 1 && a[x][y - 1] == c) y -- ;
                    l = min(l, y); tp = min(tp, x);
                    
                    x = i, y = j;
                    // 先左在上
                    while (y - 1 >= 1 && a[x][y - 1] == c) y -- ;
                    while (x - 1 >= 1 && a[x - 1][y] == c) x -- ;
                    l = min(l, y); tp = min(tp, x);
                    
                    x = i, y = j;
                    // 先右在上
                    while (y + 1 <= m && a[x][y + 1] == c) y ++ ;
                    while (x - 1 >= 1 && a[x - 1][y] == c) x -- ;
                    tp = min(tp, x); r = max(r, y);
                    
                    x = i, y = j;
                    // 先上在右
                    while (x - 1 >= 1 && a[x - 1][y] == c) x -- ;
                    while (y + 1 <= m && a[x][y + 1] == c) y ++ ;
                    tp = min(tp, x); r = max(r, y);
                    
                    
                    // 先左在下
                    x = i, y = j;
                    while (y - 1 >= 1 && a[x][y - 1] == c) y -- ;
                    while (x + 1 <= n && a[x + 1][y] == c) x ++ ;
                    btm = max(btm, x); l = min(l, y);
                    
                    // 先右在下
                    x = i, y = j;
                    while (y + 1 <= m && a[x][y + 1] == c) y ++ ;
                    while (x + 1 <= n && a[x + 1][y] == c) x ++ ;
                    btm = max(btm, x); r = max(r, y);
                    
                    // 看起来根本就不会出现当前没填过，下面填过的情况，只可能存在右侧填过
                }
                
                // 补充正方形点
                // 左侧以及上侧都已经无法修改了
                // 如果现在还不是个正方形，要去看看下面和右面是否可以通过没填过的给他补充成正方形
                
                // 补充的过程中遇到可能会遇到没填过的也可能遇到相同的，都可以算进去
                if (btm - tp > r - l)
                {
                    // 需要尝试向右扩大
                    while (btm - tp > r - l && r + 1 <= m && ((a[i][r + 1] == c) || (a[i][r + 1] == '-') )) r ++ ;
                    if (btm - tp > r - l) continue;
                }
                
                
                if (btm - tp < r - l)
                {
                    // 需要尝试向下扩大
                    while (btm - tp < r - l && btm + 1 <= n && ((a[btm+1][j] == c) || ((a[btm+1][j] == '-')))) btm ++ ;
                    if (btm - tp < r - l) continue;
                }
                
                // a question: 这里在向下or向右扩充的情况下
                // 停止的时候不会产生正好类似于a[i][r+1]==c的情况
                // 导致又存在相同字符连接了吗
                
                // 脑子已经不转了，GG
                
                // 到这里是个正方形区域了，检查下是不是没别的字符冲突
                
                bool ok = true;
                for (int x = tp; x <= btm; x ++ )
                    for (int y = l; y <= r; y ++ )
                        if (a[x][y] != '-' && a[x][y] != c) ok = false; 
                
                if (ok)
                {
                    // 保证不冲突的前提下了已经，让当前最小即最优
                    for (int x = tp; x <= btm; x ++ )
                        for (int y = l; y <= r; y ++ )
                            a[x][y] = c;
                    break;
                }
            }
        }
    
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ ) cout << a[i][j];
        cout << endl;
    }
}
