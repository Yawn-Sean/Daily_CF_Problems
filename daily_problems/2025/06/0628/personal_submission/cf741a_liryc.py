'''
https://codeforces.com/problemset/submission/741/326358948
'''
# lcm
def solve(n: int, a: list[int]):
    for i in range(n):
        a[i] -= 1
    vis = [0] * n
    ans = 1
    for i in range(n):
        if not vis[i]:
            j, c = i, 0
            while not vis[j]:
                vis[j] = 1
                c += 1
                j = a[j]
            if i != j: 
                return -1
            ans = lcm(ans, c if c & 1 else c >> 1)
    return ans
