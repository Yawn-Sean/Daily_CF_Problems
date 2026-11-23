# Submission link: https://codeforces.com/gym/104146/submission/399593591
def main(): 
    n = 15
    nums = [2 * 3 ** i for i in range(15)]
    
    print(15)
    print(*nums)
    print(sum(nums))
    sys.stdout.flush()
    
    def check(mid):
        pos = []
        neg = [0]
        
        for i in range(15):
            if mid % 3 == 1:
                mid -= 1
                pos.append(i + 1)
            elif mid % 3 == 2:
                mid += 1
                neg.append(i + 1)
            mid //= 3
        
        print('WEIGH')
        print(len(neg))
        print(*neg)
        print(len(pos))
        print(*pos)
        sys.stdout.flush()
        
        s = I()
        if s == '<': return -1
        if s == '>': return 1
        return 0
    
    t = II()
    bound = sum(nums) // 2
    
    for _ in range(t):
        l, r = 1, bound
        
        ans = -1
        
        while l <= r:
            mid = (l + r) // 2
            res = check(mid)
            
            if res == -1: r = mid - 1
            elif res == 1: l = mid + 1
            else:
                ans = mid * 2
                break
        
        print('VERDICT')
        if ans != -1:
            print('EXACT')
            print(ans, flush=True)
        else:
            if l > bound:
                print('HEAVY', flush=True)
            else:
                print('EXACT')
                print(l + r, flush=True)
        I()