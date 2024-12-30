# 对每个 k 检查 是否有 偶数个 1
def main():
    n = int(input())
    s = [int(x) for x in input()]
    cnts = [0 for _ in range(n)]
    vis = [0 for _ in range(n+1)]

    res = 0
    for i in range(1, n+1):
        if not n%i:
            for j in range(n):
                cnts[j%i] ^= s[j]
            vis[i] = 1
            for j in range(i):
                if cnts[j]:
                    cnts[j] = 0
                    vis[i] = 0
        res += vis[math.gcd(i, n)]

    print(res)
