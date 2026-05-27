'''
https://codeforces.com/gym/105315/submission/376252225
greedy, priority queue
'''
def solve(n: int, k: int, a: list[int], b: list[int]) -> int:
    hp, s, ans = [], 0, ~(1 << 50)
    for i in sorted(range(n), key=lambda i: b[i]):
        x, y = a[i], b[i]
        if len(hp) < k - 1:
            heappush(hp, x)
            s += x
        else:
            ans = max(ans, s + x - y)
            s = s + x - heappushpop(hp, x)
    return ans
