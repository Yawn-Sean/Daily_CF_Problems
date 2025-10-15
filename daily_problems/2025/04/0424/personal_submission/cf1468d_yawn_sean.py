# Submission link: https://codeforces.com/contest/1468/submission/316895470
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, m, a, b = MII()
        nums = LII()
        nums.sort()
        
        to_consider = fmin(m, abs(a - b) - 1)
        caught = b - 1 if a < b else n - b
        
        ans = 0
        for i in range(to_consider - 1, -1, -1):
            if nums[i] < caught:
                caught -= 1
                ans += 1
        
        outs.append(ans)

    print('\n'.join(map(str, outs)))