# Submission link: https://codeforces.com/contest/959/submission/299963994
def main():
    M = 2 * 10 ** 6
    factor = list(range(M + 1))

    for i in range(2, M + 1):
        if factor[i] == i:
            for j in range(i, M + 1, i):
                factor[j] = i

    n = II()
    nums = LII()

    used = [0] * (M + 1)
    ans = [-1] * n

    for i in range(n):
        v = nums[i]
        flg = True
        while v > 1:
            p = factor[v]
            while v % p == 0:
                v //= p
            if used[p]:
                flg = False
        
        if flg:
            ans[i] = nums[i]
            v = nums[i]
            while v > 1:
                p = factor[v]
                while v % p == 0:
                    v //= p
                used[p] = 1
        else:
            while True:
                nums[i] += 1
                
                v = nums[i]
                flg = True
                while v > 1:
                    p = factor[v]
                    while v % p == 0:
                        v //= p
                    if used[p]:
                        flg = False
                
                if flg:
                    break

            ans[i] = nums[i]
            v = nums[i]
            while v > 1:
                p = factor[v]
                while v % p == 0:
                    v //= p
                used[p] = 1
            
            pt = 2
            for j in range(i + 1, n):
                while factor[pt] != pt or used[pt]:
                    pt += 1
                ans[j] = pt
                used[pt] = 1
            break

    print(' '.join(map(str, ans)))