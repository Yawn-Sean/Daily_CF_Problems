# Submission link: https://codeforces.com/contest/1575/submission/259435124
def main():
    n = II()
    nums = LGMI()

    tmp = [[] for _ in range(n)]

    for i in range(n):
        if i - nums[i] >= 0:
            tmp[nums[i]].append(i - nums[i])

    lis = []
    for i in range(n):
        for j in reversed(tmp[i]):
            x = bisect.bisect_right(lis, j)
            if x < len(lis): lis[x] = j
            else: lis.append(j)

    print(len(lis))