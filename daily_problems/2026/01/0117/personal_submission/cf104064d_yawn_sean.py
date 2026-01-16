# Submission link: https://codeforces.com/gym/104064/submission/358030798
def main(): 
    n = II()
    inf = 10 ** 9
    
    add_ma = -inf
    add_mi = inf
    minus_ma = -inf
    minus_mi = inf
    
    for _ in range(n):
        x, y = MII()
        add_ma = fmax(add_ma, x + y)
        add_mi = fmin(add_mi, x + y)
        minus_ma = fmax(minus_ma, x - y)
        minus_mi = fmin(minus_mi, x - y)
    
    if add_ma == add_mi and minus_ma == minus_mi:
        print(4)
    elif add_ma == add_mi or minus_ma == minus_mi:
        print(add_ma - add_mi + minus_ma - minus_mi + 5)
    else:
        print(add_ma - add_mi + minus_ma - minus_mi + 4)