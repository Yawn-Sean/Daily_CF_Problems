# Submission link: https://codeforces.com/gym/102319/submission/393477689
def main():
    def query(s):
        print('?', s, flush=True)
        return II()
    
    def answer(s):
        print('!', s)
    
    n, k = MII()
    
    ans = [0] * n
    bound = -1
    
    for i in range(4, n + 1):
        v = [0] * n
        for j in range(i):
            v[j] = 1
        
        if query(''.join(map(str, v))):
            bound = i
            ans = v
            break
    
    for j in range(bound):
        ans[j] = 0
        if not query(''.join(map(str, ans))):
            ans[j] = 1
    
    tmp = ans[:]
    tmp[bound - 1] = 0
    
    for j in range(bound, n):
        tmp[j] = 1
        if query(''.join(map(str, tmp))):
            ans[j] = 1
        tmp[j] = 0
    
    answer(''.join(map(str, ans)))