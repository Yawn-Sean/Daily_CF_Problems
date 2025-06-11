# Submission link: https://codeforces.com/contest/818/submission/287442447
def main():
    n, a = MII()
    nums = LII()

    M = 10 ** 6
    tmp = [[] for _ in range(M + 1)]

    for i in range(n):
        tmp[nums[i]].append(i)

    for i in range(1, M + 1):
        if i != a and len(tmp[i]) >= len(tmp[a]):
            flg = True
            for j in range(len(tmp[a])):
                if tmp[i][j] > tmp[a][j]:
                    flg = False
                    break
            if flg:
                exit(print(i))

    print(-1)