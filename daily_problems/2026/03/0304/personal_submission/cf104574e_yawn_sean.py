# Submission link: https://codeforces.com/gym/104574/submission/365222059
def main(): 
    nums = LII()
    
    for _ in range(8):
        nnums = []
        for i in range(26):
            nnums.append(nums[i])
            nnums.append(nums[i + 26])
        nums = nnums
        
        flg = True
        for i in range(26, 52):
            if nums[i] == 1:
                flg = False
        
        if flg: exit(print('YES'))
    
    print('NO')