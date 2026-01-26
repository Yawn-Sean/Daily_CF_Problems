# Submission link: https://codeforces.com/gym/105198/submission/359963498
def main(): 
    digits = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
    ans = [1000] * 22
    
    for i in range(10):
        ans[digits[i]] = fmin(ans[digits[i]], i)
    
    for i in range(1, 10):
        for j in range(10):
            d = digits[i] + digits[j]
            ans[d] = fmin(ans[d], i * 10 + j)
    
    for i in range(1, 10):
        for j in range(10):
            for k in range(10):
                d = digits[i] + digits[j] + digits[k]
                ans[d] = fmin(ans[d], i * 100 + j * 10 + k)
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        if n <= 21: outs.append(str(ans[n]))
        else:
            v = (n - 15) % 7 + 15
            outs.append(str(ans[v]) + (n - v) // 7 * '8') 
    
    print('\n'.join(outs))