# Submission link: https://codeforces.com/problemset/submission/534/323558270
def main():
    n = II()
    nums = LII()

    tmp = [[] for _ in range(n + 4)]
    for i in range(n):
        tmp[nums[i]].append(i)

    cur = 0
    ans = []

    for _ in range(n):
        while True:
            if tmp[cur]:
                ans.append(tmp[cur].pop())
                break
            else:
                if cur < 3: exit(print('Impossible'))
                cur -= 3
        cur += 1

    print('Possible')
    print(' '.join(str(x + 1) for x in ans))