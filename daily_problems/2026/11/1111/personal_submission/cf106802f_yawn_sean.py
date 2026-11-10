# Submission link: https://codeforces.com/gym/106802/submission/398020230
def main():
    def query(x):
        global n
        print('?', x, flush=True)
        ret = LI()
        if ret[0] == 'YES': n -= 1
        return (ret[0] == 'YES'), int(ret[1])
    
    def answer(x):
        print('!', x)
        exit()
    
    def dis(x, y):
        w = abs(x - y)
        return fmin(w, L - w)
    
    n = II()
    L = 10 ** 9
    
    cur = random.randint(1, L)
    flg, d = query(cur)
    
    while n > 1:
        x = (cur - d - 1) % L + 1
        y = (cur + d - 1) % L + 1
        
        V = x if random.randint(0, 1) else y
        flg, d = query(V)
        
        if not flg: answer(x ^ y ^ V)
        cur = V
    
    x = (cur - d - 1) % L + 1
    y = (cur + d - 1) % L + 1
    
    if x == y: answer(x)
    else:
        for i in range(1, L + 1):
            if x != i and y != i and dis(i, x) != dis(i, y):
                if query(i)[1] == dis(i, x): answer(x)
                else: answer(y)