# Submission link: https://codeforces.com/gym/106671/submission/388638581
def main():
    n = II()
    nums = LII()
    mod = 998244353
    
    cur = sum(nums) % mod
    
    M = 10 ** 6 * 2
    que_array = [0] * M
    
    l = 5 * 10 ** 5
    r = l + n
    
    for i in range(n):
        que_array[l + i] = nums[i]
    
    flg = True
    
    q = II()
    outs = []
    
    for _ in range(q):
        query = LII()
        
        if query[0] == 1:
            if flg:
                que_array[r] = query[1]
                r += 1
            else:
                l -= 1
                que_array[l] = query[1]
            
            cur = (cur + query[1]) % mod
        
        elif query[0] == 2:
            if flg:
                r -= 1
                cur -= que_array[r]
            else:
                cur -= que_array[l]
                l += 1
            
            cur %= mod
        
        elif query[0] == 3:
            flg = not flg
        
        elif query[0] == 4:
            cur = cur * 2 % mod
            
            if r - l < q:
                for i in range(r - l):
                    que_array[r + i] = que_array[l + i]
                
                r += r - l
        
        else:
            outs.append(cur)
    
    print('\n'.join(map(str, outs)))