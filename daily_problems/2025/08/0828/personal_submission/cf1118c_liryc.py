'''
https://codeforces.com/contest/1118/submission/335867858
'''
# matrix, constructive
def solve(n: int, a: list[int]) -> list[list[int]]:
    cn = [0] * 1001
    for x in a:
        cn[x] += 1
    if n & 1:
        hp = [~(cn[x] << 10 | x) for x in range(1, 1001) if cn[x]]
        heapify(hp)
        
        h = n >> 1
        ans = [[0] * n for _ in range(n)]
        for i in range(h):
            for j in range(h):
                x = ~hp[0] & 1023
                if cn[x] < 4:
                    return []
                elif cn[x] == 4:
                    cn[x] = 0
                    heappop(hp)
                else:
                    cn[x] -= 4
                    heapreplace(hp, ~(cn[x] << 10 | x))
                ans[i][j] = ans[n - 1 - i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][n - 1 - j] = x
        for i in range(h):
            x = ~hp[0] & 1023
            if cn[x] < 2:
                return []
            elif cn[x] == 2:
                cn[x] = 0
                heappop(hp)
            else:
                cn[x] -= 2
                heapreplace(hp, ~(cn[x] << 10 | x))
            ans[i][h] = ans[n - 1 - i][h] = x
        for j in range(h):
            x = ~hp[0] & 1023
            if cn[x] < 2:
                return []
            elif cn[x] == 2:
                cn[x] = 0
                heappop(hp)
            else:
                cn[x] -= 2
                heapreplace(hp, ~(cn[x] << 10 | x))
            ans[h][j] = ans[h][n - 1 - j] = x
        ans[h][h] = ~hp[0] & 1023
        return ans
    else:
        sa = [x for x in range(1, 1001) if cn[x]]
        if all(cn[x] & 3 == 0 for x in sa):
            ans = [[0] * n for _ in range(n)]
            for i in range(n >> 1):
                for j in range(n >> 1):
                    if cn[sa[-1]] == 0: sa.pop()
                    x = sa[-1]
                    cn[x] -= 4
                    ans[i][j] = ans[n - 1 - i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][n - 1 - j] = x
            return ans
        else:
            return []
