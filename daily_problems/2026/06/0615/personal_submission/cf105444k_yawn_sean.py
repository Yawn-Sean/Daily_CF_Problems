# Submission link: https://codeforces.com/gym/105444/submission/378614806
def main():
    x = [int(c) for c in I()]
    y = [int(c) for c in I()]
    
    x.reverse()
    y.reverse()
    
    while len(x) < len(y): x.append(0)
    while len(y) < len(x): y.append(0)
    
    x.append(0)
    y.append(0)
    
    x.reverse()
    y.reverse()
    
    k = len(x)
    
    total = [0] * k
    chosen = k
    
    for i in range(k - 1, 0, -1):
        if x[i] + y[i] + total[i] >= 10:
            chosen = i
        
        total[i] += x[i] + y[i]
        total[i - 1] += total[i] // 10
        total[i] %= 10
    
    x = x[chosen:]
    y = y[chosen:]
    
    tmp = max(x, y)
    
    k = len(tmp)
    
    ans = []
    
    for i in range(k):
        if i < k - 1: ans.append(9 - tmp[i])
        else: ans.append(10 - tmp[i])
    
    if ans and ans[-1] == 10:
        ans[-1] = 0
        ans[-2] += 1
    
    ans.reverse()
    while ans and ans[-1] == 0:
        ans.pop()
    ans.reverse()
    
    if ans: print(''.join(map(str, ans)))
    else: print(0)