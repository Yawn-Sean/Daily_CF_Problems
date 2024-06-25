# submission: https://codeforces.com/problemset/submission/1129/259851172

def main():
    n, m = MII()
    move = defaultdict(lambda: n - 1)
    cnt = Counter()
    for i in range(m):
        a, b = GMI()
        cnt[a] += 1
        move[a] = min(move[a], (b - a) % n)
    
    ans = [0] * n
    for i in range(n):
        for j in range(n):
            nex = (i + j) % n
            if cnt[nex]:
                ans[i] = max(ans[i], j + (cnt[nex] - 1) * n + move[nex])

    print(*ans, sep=' ')


main()