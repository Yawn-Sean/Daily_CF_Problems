# Submission link: https://codeforces.com/contest/67/submission/319447993
def main():
    n, k = MII()
    nums = LII()

    ans = []

    for i in range(n - 1, -1, -1):
        nans = []
        
        c = 0
        for x in ans:
            if c == nums[i]:
                nans.append(i)
                c += 1
            nans.append(x)
            if x >= i + k:
                c += 1
        
        if c == nums[i]:
            nans.append(i)
        
        ans = nans

    print(*(x + 1 for x in ans))