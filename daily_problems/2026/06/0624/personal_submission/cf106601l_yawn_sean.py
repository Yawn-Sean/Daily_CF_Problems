# Submission link: https://codeforces.com/gym/106601/submission/379898920
def main():
    x = II()
    ans = 0
    
    for i in range(2, 10 ** 6 + 5):
        cnt = 0
        xor_val = 0
        cur = x
        
        while cur:
            cnt += 1
            xor_val ^= cur % i
            cur //= i
        
        if cnt <= 2: break
        
        if xor_val == 0:
            ans += 1
    
    for i in range(1, 10 ** 6 + 5):
        if i * (i + 2) > x: break
        if x % i == 0:
            ans += 1
    
    print(ans)