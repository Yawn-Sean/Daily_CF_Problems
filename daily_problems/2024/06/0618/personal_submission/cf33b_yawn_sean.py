# Submission link: https://codeforces.com/contest/33/submission/266193484
def main():
    s1 = [ord(c) - ord('a') for c in I()]
    s2 = [ord(c) - ord('a') for c in I()]

    n = II()

    inf = 10 ** 9
    dist = [[inf] * 26 for _ in range(26)]

    for i in range(26):
        dist[i][i] = 0

    for _ in range(n):
        c1, c2, d = LI()
        c1 = ord(c1) - ord('a')
        c2 = ord(c2) - ord('a')
        d = int(d)
        if d < dist[c1][c2]:
            dist[c1][c2] = d

    for i in range(26):
        for j in range(26):
            for k in range(26):
                if dist[j][i] + dist[i][k] < dist[j][k]:
                    dist[j][k] = dist[j][i] + dist[i][k]

    ans = [[inf] * 26 for _ in range(26)]
    chosen = [[-1] * 26 for _ in range(26)]
    for i in range(26):
        for j in range(26):
            for k in range(26):
                if dist[i][k] + dist[j][k] < ans[i][j]:
                    ans[i][j] = dist[i][k] + dist[j][k] 
                    chosen[i][j] = k

    if len(s1) != len(s2):
        print(-1)
        exit()

    k = len(s1)
    tot = 0
    res = []

    for i in range(k):
        if chosen[s1[i]][s2[i]] != -1:
            tot += ans[s1[i]][s2[i]]
            res.append(chosen[s1[i]][s2[i]])
        else:
            print(-1)
            exit()

    print(tot)
    print(''.join(chr(ord('a') + c) for c in res))