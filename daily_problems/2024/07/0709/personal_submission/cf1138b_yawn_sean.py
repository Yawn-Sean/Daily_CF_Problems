# Submission Link: https://codeforces.com/contest/1138/submission/269487812
def main():
    n = II()
    s1 = I()
    s2 = I()

    cnt = s1.count('1')
    tmp = [[] for _ in range(3)]

    for i in range(n):
        tmp[int(s1[i]) + int(s2[i])].append(i)

    for i in range(len(tmp[2]) + 1):
        j = cnt - i * 2
        if 0 <= j <= len(tmp[1]) and 0 <= n // 2 - i - j <= len(tmp[0]): 
            ans = []
            ans.extend(tmp[0][n // 2 - i - j:])
            ans.extend(tmp[1][j:])
            ans.extend(tmp[2][i:])
            print(' '.join(str(x + 1) for x in ans))
            exit()

    print(-1)