'''
1.如果序列最终到达右下角位置 那么无法进行修改
2.考虑移动的过程 在某一时刻移动到了点(x0, y0)
        通过增加D和R 所能到达的位置为(x0 + a, y0 + b) 0 <= a <= n - 1 -cnt_R, 0<=b<=n-1-cnt_D
        考虑下一个位置为(x0, y0 + 1)增加了多少新的网格
'''
def solve():
    ...
    n = II()
    path = I()
    ans = 0
    cnt_R, cnt_D = path.count('R'), path.count('D')
    limit_R, limit_D = n - 1 - cnt_R, n - 1 - cnt_D
    D, R = 0, 0
    far_D, far_R = 0, 0
    start = len(path)

    for i in range(len(path)):

        if path[i] == 'D':
            D += 1
            if R == 0:
                ans = D + limit_D + 1
        else:
            R += 1
            if D == 0:
                ans = R + limit_R + 1
        if D > 0 and R > 0:
            start = i
            ans += (1 + limit_R) * (1 + limit_D)
            break

    far_D, far_R = D + limit_D, R + limit_R
    for i in range(start + 1, len(path)):
        if path[i] == 'D':
            D += 1
            if far_D < n - 1:
                ans += limit_R + 1
            far_D = D + limit_D
        else:
            R += 1
            if far_R < n - 1:
                ans += limit_D + 1
            far_R = R + limit_R

    print(ans)

t = II()
for _ in range(t):
    solve()
