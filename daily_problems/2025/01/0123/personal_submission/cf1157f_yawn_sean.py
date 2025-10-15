# Submission link: https://codeforces.com/contest/1157/submission/302528225
def main():
    cnt = [0] * (2 * 10 ** 5 + 2)

    n = II()
    nums = LII()

    for x in nums:
        cnt[x] += 1

    ans = 0
    start = -1

    pt = 0
    while pt < len(cnt):
        if cnt[pt] > 1:
            lpt = pt
            cur = 0
            while cnt[pt] > 1:
                cur += cnt[pt]
                pt += 1
            if cnt[lpt - 1]: cur += 1
            if cnt[pt]: cur += 1
            if cur > ans:
                ans = cur
                start = lpt
        else:
            pt += 1

    if ans >= 2:
        l = start
        while cnt[start] > 1:
            start += 1
        r = start
        
        ans = []
        if cnt[l - 1]:
            ans.append(l - 1)
        
        for i in range(l, r):
            ans.append(i)
        
        if cnt[r]:
            ans.append(r)
        
        for i in range(r - 1, l - 1, -1):
            for j in range(cnt[i] - 1):
                ans.append(i)
        
        print(len(ans))
        print(' '.join(map(str, ans)))
    else:
        for i in range(2 * 10 ** 5 + 1):
            if cnt[i] and cnt[i + 1]:
                print(2)
                print(i, i + 1)
                exit()
        
        print(1)
        print(nums[0])