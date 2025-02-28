# Submission link: https://codeforces.com/contest/1090/submission/296085337
def main():
    v = (1 << 32) - 1

    t = II()
    outs = []

    inf = 5 * 10 ** 18

    for _ in range(t):
        n, l, r, x, y, z, b1, b2 = MII()
        nums = [0] * n
        bs = [0] * n
        bs[0] = b1
        bs[1] = b2
        
        for i in range(2, n):
            bs[i] = (bs[i - 2] * x + bs[i - 1] * y + z) & v
        for i in range(n):
            nums[i] = bs[i] % (r - l + 1) + l
        
        ans = inf
        
        cur_mi = nums[0]
        for i in range(n):
            if nums[i] <= cur_mi: cur_mi = nums[i]
            elif nums[i] > 0: ans = fmin(ans, cur_mi * nums[i])

        cur_ma = nums[-1]
        for i in range(n - 1, -1, -1):
            if nums[i] >= cur_ma: cur_ma = nums[i]
            elif nums[i] < 0: ans = fmin(ans, cur_ma * nums[i])
        
        outs.append(str(ans) if ans < inf else 'IMPOSSIBLE')

    print('\n'.join(outs))