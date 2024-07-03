# Submission link: https://codeforces.com/contest/992/submission/265698239
def main():
    n, k = MII()
    nums = LII()

    next_pos = list(range(n))
    for i in range(n - 2, -1, -1):
        if nums[i] == 1:
            next_pos[i] = next_pos[i+1]

    tot = sum(nums) * k

    ans = 0
    for i in range(n):
        p = 1
        s = 0
        while i < n:
            if next_pos[i] != i:
                if p % k == 0 and 0 < p // k - s <= next_pos[i] - i:
                    ans += 1
                s += next_pos[i] - i
                i = next_pos[i]
            else:
                if tot // nums[i] < p:
                    break
                p *= nums[i]
                s += nums[i]
                if p == s * k: ans += 1
                i += 1
    print(ans)