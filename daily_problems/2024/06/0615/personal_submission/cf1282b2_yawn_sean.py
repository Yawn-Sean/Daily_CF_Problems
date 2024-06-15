# Submission link: https://codeforces.com/contest/1282/submission/265820826
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, p, k = MII()
        nums = [0] + LII()
        nums.sort()
        for i in range(1, n + 1):
            if i < k: nums[i] += nums[i-1]
            else: nums[i] += nums[i-k]
        
        ans = n
        for i in range(n, -1, -1):
            if nums[i] <= p:
                ans = i
                break
        outs.append(ans)

    print('\n'.join(map(str, outs)))