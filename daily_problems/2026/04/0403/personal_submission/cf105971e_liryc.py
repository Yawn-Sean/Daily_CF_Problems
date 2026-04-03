'''
https://codeforces.com/gym/105971/submission/369446908
'''
def solve(n: int, m: int, k: int, pa: list[list[int]]) -> int:
    MOD = 1000000007
    if any(abs(x1 - x0) + abs(y1 - y0) == 2 for (x0, y0), (x1, y1) in pairwise(pa)):
        return 0
    uni = UnionFind(n * m)
    ec = [0] * (n * m)
    sl = [0] * (n * m)
    enc = lambda x, y: x * m + y
    for i in range(k):
        x1, y1 = pa[i]
        x2, y2 = pa[i + 1]

        if x1 == x2 or y1 == y2:
            e = enc((x1 + x2) // 2, (y1 + y2) // 2)
            ec[e] += 1
            sl[e] = 1
        else:
            e1 = enc(x1, y2)
            e2 = enc(x2, y1)
            uni.union(e1, e2)
            ec[e1] += 1
    
    for i in range(n * m):
        if uni.find(i) != i:
            ec[uni.find(i)] += ec[i]
            sl[uni.find(i)] |= sl[i]
    
    ans = 1
    for i in range(n * m):
        if uni.find(i) == i:
            if ec[i] > uni.size(i):
                ans = 0
            elif ec[i] == uni.size(i):
                if not sl[i]:
                    ans = ans * 2 % MOD
            else:
                ans = ans * uni.size(i) % MOD
        
    return ans    
