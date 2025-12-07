# Submission link: https://codeforces.com/gym/106035/submission/352328405
def main(): 
    n, m, k = MII()
    
    if n == m: print(1)
    else:
        v = abs(n - m)
        
        combs = [[1]]
        
        def add_val(x1, x2):
            cur = []
            n1, n2 = len(x1), len(x2)
            
            carry = 0
            for i in range(fmax(n1, n2)):
                if i < n1: carry += x1[i]
                if i < n2: carry += x2[i]
                cur.append(carry % 2)
                carry //= 2
            
            if carry: cur.append(carry)
            
            return cur
        
        for i in range(1, k + 1):
            ncombs = [[] for _ in range(i + 1)]
            ncombs[0] = [1]
            ncombs[i] = [1]
            
            for j in range(1, i):
                ncombs[j] = add_val(combs[j - 1], combs[j])
            
            combs = ncombs
        
        carry = []
        ans = 0
        
        for x in combs:
            x = add_val(x, carry)
            ans += sum(x[:v])
            carry = x[v:]
        
        ans += sum(carry)
        print(ans)