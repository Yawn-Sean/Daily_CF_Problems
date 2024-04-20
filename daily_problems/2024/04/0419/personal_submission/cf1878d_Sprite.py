from bisect import bisect_right
def f():
    n, k = map(int, input().split())
    s = input()
    l = list(map(lambda x: int(x) - 1, input().split()))
    r = list(map(lambda x: int(x) - 1, input().split()))
    _ = int(input())
    x = list(map(lambda x: int(x) - 1, input().split()))

    dif = [0] * (n+1)
    for now in x:
        group = bisect_right(l, now) - 1
        sym = l[group] + r[group] - now
        if now > sym:
            now, sym = sym, now
        dif[now] ^= 1
        dif[sym+1] ^= 1
    
    ans = list(s)
    change = 0
    now_group = 0
    for i in range(n):
        if now_group != k-1 and i >= l[now_group+1]:
            now_group += 1
        if dif[i]:
            change ^= 1
        if change:
            ans[i] = s[l[now_group] + r[now_group] - i]
    print(''.join(ans))

for _ in range(int(input())):
    f()
