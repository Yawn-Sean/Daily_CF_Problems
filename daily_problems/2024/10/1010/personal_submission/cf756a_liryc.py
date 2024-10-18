'''
https://codeforces.com/contest/756/submission/285130640
756A
2024/10/10 Y1
1700
'''
# ref
if __name__ == '__main__':
    n = int(input())
    perm = list(map(int, input().split()))
    for i in range(len(perm)):
        perm[i] -= 1
    nums = list(map(int, input().split()))

    vis = [0] * n
    cnt = 0

    for i in range(n):
        if not vis[i]:
            while not vis[i]:
                vis[i] = 1
                i = perm[i]
            cnt += 1

    print((cnt if cnt > 1 else 0) + (sum(nums) - 1) % 2)