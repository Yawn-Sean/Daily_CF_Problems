# Submission link: https://codeforces.com/contest/698/submission/294871475
def main():
    n = II()
    nums = LGMI()

    rt = -1
    for i in range(n):
        if nums[i] == i:
            rt = i

    ans = 0
    vis = [-1] * n
    for i in range(n):
        if vis[i] == -1:
            u = i
            while vis[u] == -1:
                vis[u] = i
                u = nums[u]
            
            if vis[u] == i and u != rt:
                ans += 1
                if rt >= 0:
                    nums[u] = rt
                else:
                    nums[u] = u
                    rt = u

    print(ans)
    print(' '.join(str(x + 1) for x in nums))