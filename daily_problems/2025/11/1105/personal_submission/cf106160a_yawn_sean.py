# Submission link: https://codeforces.com/gym/106160/submission/347347758
def main(): 
    n = [int(c) for c in I()]
    k = len(n)
    
    ans = 0
    val = 0
    cur = 1
    
    for i in range(k - 1):
        val += n[i] * cur
        ans += val
        cur = cur / 10
    
    val += n[-1] * cur
    print(ans * 0.9 + val)