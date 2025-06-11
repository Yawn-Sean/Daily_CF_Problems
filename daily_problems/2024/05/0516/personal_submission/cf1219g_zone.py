def main(ac=FastIO()):
    """
    url:  
        question:   https://codeforces.com/problemset/problem/1219/G
        submission: https://codeforces.com/contest/1219/submission/261153032
    time: 280 ms
    """
    n, m = ac.read_list_ints()
    a = [ac.read_list_ints() for _ in range(n)]
    sum_row = [sum(x) for x in a]
    sum_col = [sum(a[i][j] for i in range(n))
               for j in range(m)]
    if n < 4 or m < 4: 
        print(sum(sum_row))
        return 
    ans = max(sum(sorted(sum_row)[-4:]), sum(sorted(sum_col)[-4:]))
    # 枚举1行，3列
    for i in range(n):
        mn, mid, mx = 0, 0, 0
        for j, x in enumerate(sum_col):
            x -= a[i][j]
            if x > mx: 
                mx, mid, mn = x, mx, mid 
            elif x > mid: 
                mid, mn = x, mid 
            elif x > mn: 
                mn = x 
        ans = max(ans, sum_row[i] + mn + mid + mx)
    # 枚举1列，3行
    for j in range(m):
        mn, mid, mx = 0, 0, 0
        for i, x in enumerate(sum_row):
            x -= a[i][j]
            if x > mx: 
                mx, mid, mn = x, mx, mid 
            elif x > mid: 
                mid, mn = x, mid 
            elif x > mn: 
                mn = x 
        ans = max(ans, sum_col[j] + mn + mid + mx)
    # 枚举2行2列
    if n <= m: 
        for i in range(n):
            for j in range(i + 1, n):
                mn, mx = 0, 0 
                for k, x in enumerate(sum_col):
                    x -= a[i][k] + a[j][k]
                    if x > mx:
                        mx, mn = x, mx 
                    elif x > mn: 
                        mn = x 
                ans = max(ans, mn + mx + sum_row[i] + sum_row[j])
    else: 
        for i in range(m):
            for j in range(i + 1, m):
                mn, mx = 0, 0 
                for k, x in enumerate(sum_row):
                    x -= a[k][i] + a[k][j]
                    if x > mx:
                        mx, mn = x, mx 
                    elif x > mn: 
                        mn = x 
                ans = max(ans, mn + mx + sum_col[i] + sum_col[j])
    print(ans)
