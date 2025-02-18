def main():
    n,m = map(int,input().split())
    a = [list(map(int,input().split())) for i in range(m)]
    ans_cnt,ans_idx = 0,-1
    for i in range(n - 1):
        dif = [a[j][i] - a[j][-1] for j in range(m)]
        dif = sorted(dif,reverse=True)
        cur = 0
        for j in range(m):
            cur += dif[j]
            if cur < 0: break
            if j + 1 > ans_cnt: ans_cnt,ans_idx = j + 1,i
    print(m - ans_cnt)
    if ans_cnt == 0:
        print(*list(range(1,m + 1)))
    else:
        t = sorted(range(m), key=lambda j: a[j][ans_idx] - a[j][-1], reverse=True)[ans_cnt:]
        t = [x + 1 for x in t]
        print(*t)
main()