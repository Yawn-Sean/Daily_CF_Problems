# Submission link: https://codeforces.com/gym/103114/submission/337521144
def main():
    n = II()
    pos = [0] * (n + 1)
    
    for i in range(10):
        tmp = []
        for j in range(1, n + 1):
            if j >> i & 1:
                tmp.append(j)
        
        if len(tmp):
            print(len(tmp), *tmp, flush=True)
            
            nums = LII()
            for v in nums:
                pos[v] |= 1 << i
    
    ans = [0] * (n + 1)
    for i in range(n + 1):
        ans[pos[i]] = i
    
    print('!', *ans[1:])