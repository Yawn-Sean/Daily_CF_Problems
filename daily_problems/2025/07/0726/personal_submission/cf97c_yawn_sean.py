# Submission link: https://codeforces.com/contest/97/submission/330839884
def main():
    n = II()
    nums = LFI()
    
    ans = nums[n // 2]
    
    for i in range(n + 1):
        wi = 2 * i - n
        for j in range(n + 1):
            wj = 2 * j - n
            
            if wi < 0 and wj > 0:
                ans = fmax(ans, (wj * nums[i] - wi * nums[j]) / (wj - wi))
    
    print(ans)