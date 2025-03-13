# Submission link: https://codeforces.com/contest/980/submission/310331867
def main():
    n, k = MII()
    nums = LII()

    col = list(range(256))
    sz = [1] * 256

    ans = [0] * n

    for i in range(n):
        while True:
            cur = col[nums[i]]
            if cur == 0: break
            
            ncur = col[cur - 1]
            if sz[ncur] + sz[cur] > k:
                break

            for j in range(cur, nums[i] + 1):
                col[j] = ncur
            sz[ncur] += sz[cur]
        
        ans[i] = col[nums[i]]

    print(' '.join(map(str, ans)))