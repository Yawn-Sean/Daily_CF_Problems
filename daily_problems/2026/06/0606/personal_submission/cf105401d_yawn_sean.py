# Submission link: https://codeforces.com/gym/105401/submission/377396362
def main():
    n = II()
    
    ans = [1]
    
    l = 1
    r = 2 * n + 1
    
    for i in range(n + 1):
        if i % 2 == 0:
            ans.append(ans[-1] + r)
            r -= 2
        else:
            ans.append(ans[-1] - l)
            l += 2
    
    print(' '.join(map(str, ans)))