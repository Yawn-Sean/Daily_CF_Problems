# url: https://codeforces.com/contest/644/submission/280674773
n, m = map(int, input().split())
a = [0] 
i = 0
outs = []
for _ in range(n):
    t, d = map(int, input().split()) 
    while i < len(a) and a[i] <= t: 
        i += 1 
    outs.append("-1" if len(a) - i > m else f"{max(a[-1], t) + d}")
    if outs[-1] != "-1": 
        a.append(int(outs[-1]))
print(*outs)
