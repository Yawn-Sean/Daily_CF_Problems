d = [[] for _ in range(9)]
d[1] = [1]
d[2] = [-1]
d[3] = [-1]
d[4] = [2, 4, 1, 3]
d[5] = [1, 3, 5, 2, 4]
d[6] = d[5] + [6]
d[7] = [1, 3, 5, 2, 7, 4, 6]
d[8] = d[7] + [8]

outs = []
def soviet():
    n = int(input())
    ans = []

    def f(i, x):
        res = []
        for j in d[x]:
            res.append(i + j - 1)
        return res

    if n <= 8:
        ans = d[n]
    else:
        i = 1
        while i <= n:
            if i + 8 <= n:
                ans.extend(f(i, 5))
                i += 5
            else:
                ans.extend(f(i, n - i + 1))
                break

    outs.append(' '.join(map(str, ans)))


for _ in range(int(input())):
    soviet()
print('\n'.join(map(str, outs)))
