# Submission link: https://codeforces.com/gym/103785/submission/343053672
def main():
    n = II()
    nums = LII()
    
    ans = []
    
    for i in range(n - 1, -1, -1):
        for j in range(i, -1, -1):
            if nums[j] == j + 1:
                ans.append(nums.pop(j))
                break
        else:
            exit(print('NO'))
    
    ans.reverse()
    print('YES')
    print(' '.join(map(str, ans)))