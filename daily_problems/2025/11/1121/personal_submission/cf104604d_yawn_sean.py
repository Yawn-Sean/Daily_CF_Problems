# Submission link: https://codeforces.com/gym/104604/submission/349820630
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        a, b = MII()
        
        if a > b: a, b = b, a
        
        if b > 2 * a: outs.append('NO')
        elif a == b:
            if a % 2 == 0: outs.append('SI')
            else: outs.append('NO')
        else:
            if a % (b - a): outs.append('NO')
            else:
                flg = False
                for i in range(2, 5):
                    if b % i == 0:
                        x = a - b // i
                        if x > 0 and b % x == 0:
                            flg = True
                outs.append('SI' if flg else 'NO')
    
    print('\n'.join(map(str, outs)))