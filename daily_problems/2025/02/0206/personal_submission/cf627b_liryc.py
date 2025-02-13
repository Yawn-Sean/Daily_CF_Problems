'''
https://codeforces.com/problemset/submission/627/304645205
'''
def solve(n: int, k: int, a: int, b: int, q: int, qa: list[list[int]]) -> list[int]:
    a1 = [0] * n
    a2 = [0] * n

    f1 = FenwickTree(n)
    f2 = FenwickTree(n)

    ans = []
    for query in qa:
        if query[0] == 1:
            x = query[1] - 1
            y = query[2]
            
            v = min(a1[x] + y, b) - a1[x]
            a1[x] += v
            f1.add(x, v)
            
            v = min(a2[x] + y, a) - a2[x]
            a2[x] += v
            f2.add(x, v)
        
        else:
            x = query[1] - 1
            ans.append(f1.sum(x - 1) + f2.rangesum(x + k, n - 1))
    return ans

