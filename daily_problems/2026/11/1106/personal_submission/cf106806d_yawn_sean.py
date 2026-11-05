# Submission link: https://codeforces.com/gym/106806/submission/397291614
def main(): 
    n = II()
    nums = LII()
    
    nums.sort()
    
    cur = 0
    flg = False
    
    for x in nums:
        if cur >= x: flg = True
        cur += x
    
    print('possible' if flg else 'impossible')