# Submission link: https://codeforces.com/gym/104673/submission/343872842
def main(): 
    d = {}
    bound = 10 ** 9
    
    for i in range(10 ** 5, -1, -1):
        cur = 1
        for j in range(i + 1):
            if cur > bound: break
            d[cur] = i + 1
            cur = cur * (i - j) // (j + 1)
    
    t = II()
    outs = []
    
    for _ in range(t):
        x = II()
        if x in d: outs.append(d[x])
        else: outs.append(x + 1)
    
    print('\n'.join(map(str, outs)))