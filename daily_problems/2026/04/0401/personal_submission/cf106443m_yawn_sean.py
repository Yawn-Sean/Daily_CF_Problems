# Submission link: https://codeforces.com/gym/106443/submission/368955160
def main(): 
    n, m = MII()
    nums = LII()
    
    diff_k = [0] * (m * 2 + 1)
    diff_b = [0] * (m * 2 + 1)
    
    v = (m + 1) // 2
    
    for x in nums:
        diff_k[x] += 1
        diff_k[x + v] -= 1
        diff_b[x] -= x
        diff_b[x + v] += x
        
        diff_k[x + v] -= 1
        diff_k[x + m] += 1
        diff_b[x + v] += x + m
        diff_b[x + m] -= x + m
    
    for i in range(m * 2):
        diff_k[i + 1] += diff_k[i]
        diff_b[i + 1] += diff_b[i]
    
    ans = [0] * m
    
    for i in range(m * 2):
        ans[i % m] += diff_k[i] * i + diff_b[i]
    
    print(min(ans))