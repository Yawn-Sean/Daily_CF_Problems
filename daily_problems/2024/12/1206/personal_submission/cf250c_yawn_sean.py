# Submission link: https://codeforces.com/contest/250/submission/295138864
def main():
    n, k = MII()
    nums = LII()
    
    tmp = [nums[0]]
    for i in range(1, n):
        if nums[i] != tmp[-1]:
            tmp.append(nums[i])
    
    ans = [0] * (k + 1)
    for i in range(len(tmp)):
        if i == 0 or i == len(tmp) - 1 or tmp[i - 1] != tmp[i + 1]:
            ans[tmp[i]] += 1
        else:
            ans[tmp[i]] += 2
    
    print(ans.index(max(ans)))