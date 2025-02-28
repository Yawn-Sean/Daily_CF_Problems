def solve():
    s, c = LI()
    s, c = [*s], [*c]
    n = len(s)
    for i in range(n):
        k = i
        for j in range(n - 1, i, -1):
            if s[k] > s[j]:
                k = j
        if k != i:
            s[i], s[k] = s[k], s[i]
            break
    if s < c:
        print(''.join(s))
    else:
        print('---')


            


T=II()
# T=1
for _ in range(T):
    solve()
