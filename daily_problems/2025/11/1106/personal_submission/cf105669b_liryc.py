'''
https://codeforces.com/gym/105669/submission/347621181
'''
def solve(sl: str, op: str, sr: str) -> int:
    MOD1, MOD2 = 1000000007, 1000000006
    x = reduce(lambda s, c: (s * 10 + int(c)) % MOD1, (int(c) for c in sl))    
    y = 0
    if op == '^':
        y = reduce(lambda s, c: (s * 10 + int(c)) % MOD2, (int(c) for c in sr))    
        return pow(x, y, MOD1)
    else:
        y = reduce(lambda s, c: (s * 10 + int(c)) % MOD1, (int(c) for c in sr))    
        if op == '+': 
            return (x + y) % MOD1
        elif op == '-': 
            return (x - y) % MOD1
        else: # '*'
            return x * y % MOD1
