# Submission link: https://codeforces.com/problemset/submission/404/312129433
def main():
    n, k = MII()
    nums = LII()

    tmp = [[] for _ in range(n)]
    for i in range(n):
        tmp[nums[i]].append(i)

    if len(tmp[0]) != 1:
        print(-1)
    else:
        for i in range(1, n):
            if len(tmp[i]) > len(tmp[i - 1]) * (k if i == 1 else k - 1):
                exit(print(-1))
        
        outs = []

        for i in range(1, n):
            for j in range(len(tmp[i])):
                outs.append(f'{tmp[i - 1][j // (k if i == 1 else k - 1)] + 1} {tmp[i][j] + 1}')
        
        print(n - 1)
        print('\n'.join(outs))