# Submission link: https://codeforces.com/gym/106414/submission/373499944
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        nums = LII()
        
        order = sorted(range(n), key=lambda x: nums[x])
        
        ans = []
        bound = n
        
        for i in range(2, n):
            if nums[order[i]] >= m:
                if nums[order[0]] + nums[order[1]] + nums[order[i]] <= 2 * m:
                    ans = [order[0], order[1], order[i]]
                bound = i
                break
        
        if not ans and bound >= 3:
            for i in range(4):
                tmp = []
                for j in range(i):
                    tmp.append(order[j])
                for j in range(3 - i):
                    tmp.append(order[bound - 1 - j])
                
                total = 0
                for x in tmp:
                    total += nums[x]
                
                if m <= total <= 2 * m:
                    ans = tmp
                    break
        
        if ans: outs.append(' '.join(str(x + 1) for x in ans))
        else: outs.append('-1')
    
    print('\n'.join(map(str, outs)))