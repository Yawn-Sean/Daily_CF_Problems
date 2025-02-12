# Submission link: https://codeforces.com/contest/427/submission/303590874
def main():
    n, m = MII()
    nums = LII()

    pref = [0] * n
    suff = [0] * n

    for i in range(n):
        if i: pref[i] = pref[i - 1]
        if i % m == m - 1:
            pref[i] += nums[i - m + 1]

    for i in range(n - 1, -1, -1):
        if i + 1 < n: suff[i] = suff[i + 1]
        if (n - 1 - i) % m == m - 1:
            suff[i] += nums[i + m - 1]

    ans = inf
    for i in range(n):
        res = 0
        res += (i + 1) // m * nums[i] - pref[i]
        res += suff[i] - (n - i) // m * nums[i]
        
        left = (i + 1) // m * m
        right = n - 1 - (n - i) // m * m
        
        if right - left < m:
            if right >= left:
                res += nums[fmax(right, i)] - nums[fmin(left, i)]
            ans = fmin(ans, res)

    print(ans * 2)