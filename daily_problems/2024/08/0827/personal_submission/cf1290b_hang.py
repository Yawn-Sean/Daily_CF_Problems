def main():
    s = input()
    n = len(s)
    p = [[0] * (n + 1) for _ in range(26)]
    for i in range(n):
        for j in range(26):
            p[j][i+1] = p[j][i]
        p[ord(s[i]) - ord('a')][i+1] += 1

    q = int(input())
    for _ in range(q):
        l, r = map(lambda x: int(x) - 1, input().split())
        cnt = 0
        for i in range(26):
            if p[i][r+1] - p[i][l]:
                cnt += 1
        print('No' if l != r and cnt <= 2 and s[l] == s[r] else 'Yes', flush=False)


main()