# Submission link: https://codeforces.com/contest/2200/submission/364774218
def main(): 
    M = 10 ** 6
    pr = list(range(M + 1))
    cnt = [0] * (M + 1)
    
    for i in range(2, M + 1):
        if pr[i] == i:
            for j in range(i, M + 1, i):
                pr[j] = i
                cnt[j] += 1
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        nums = LII()
        
        def check():
            for i in range(1, n):
                if nums[i] < nums[i - 1]: return False
            return True
    
        if check(): outs.append('Bob')
        else:
            flg = False
            for i in range(n):
                if cnt[nums[i]] > 1: flg = True
                nums[i] = pr[nums[i]]
    
            if flg: outs.append('Alice')
            else: outs.append('Bob' if check() else 'Alice')
    
    print('\n'.join(outs))