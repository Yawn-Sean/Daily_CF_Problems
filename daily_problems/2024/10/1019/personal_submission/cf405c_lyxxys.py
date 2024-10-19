def main():
    n = int(input())
    g = [[int(x) for x in input().split()] for _ in range(n)]
    ans = 0
    for i in range(n):
        ans += g[i][i]
    ans %= 2
    q = int(input())
    outs = []
    while q:
        q -= 1
        if input()[0] == '3': outs.append(ans)
        else: ans ^= 1

    print(''.join(map(str, outs)))
