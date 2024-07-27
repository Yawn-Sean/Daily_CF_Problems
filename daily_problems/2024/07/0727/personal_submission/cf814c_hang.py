def main():
    n = int(input())
    s = input()
    s = [ord(x) - ord('a') for x in s]
    f = [[0] * (n + 1) for _ in range(26)]
    for i in range(26):
        for j in range(1, n + 1):
            l,r = 0,0
            ans = 0
            cur = 0
            while l < n:
                while r < n and cur + int(s[r] != i) <= j:
                    cur += int(s[r] != i)
                    r += 1
                ans = max(ans, r - l)
                cur -= int(s[l] != i)
                l += 1
            f[i][j] = ans



    q = int(input())
    res = []
    for _ in range(q):
        m,c = input().split()
        m = int(m)
        res.append(f[ord(c) - ord('a')][m])
    print('\n'.join(map(str,res)))

main()