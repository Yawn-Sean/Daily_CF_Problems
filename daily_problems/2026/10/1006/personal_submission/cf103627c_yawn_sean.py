# Submission link: https://codeforces.com/gym/103627/submission/393256462
def main():
    n = II()
    nums = LII()
    
    for i in range(1 << n):
        bit1 = [1 << j for j in range(n) if i >> j & 1]
        bit2 = [1 << j for j in range(n) if not i >> j & 1]
        
        for b1 in bit1:
            for b2 in bit2:
                if nums[i - b1] + nums[i + b2] > nums[i] + nums[i - b1 + b2]:
                    print(i, i - b1 + b2)
                    exit()
    
    print(-1)