# Submission link: https://codeforces.com/contest/255/submission/286624682
def main():
    M = 10 ** 6
    sg = [0] * (M + 1)

    l = r = 0

    cnt = Counter()

    for i in range(1, M + 1):
        while l ** 4 < i:
            cnt[sg[l]] -= 1
            l += 1
        
        while r * r <= i and r < i:
            cnt[sg[r]] += 1
            r += 1
        
        while cnt[sg[i]]:
            sg[i] += 1

    n = II()
    nums = LII()
    nums.sort()

    cnt = Counter()
    l = r = 0

    res = 0

    for num in nums:
        
        while l ** 4 < num:
            cnt[sg[l]] -= 1
            l += 1
        
        while r * r <= num and r < num:
            cnt[sg[r]] += 1
            r += 1
        
        v = 0
        while cnt[v]:
            v += 1
        
        res ^= v

    print('Furlo' if res else 'Rublo')