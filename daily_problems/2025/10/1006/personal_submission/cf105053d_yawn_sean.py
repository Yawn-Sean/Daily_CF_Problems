# Submission link: https://codeforces.com/gym/105053/submission/342017782
def main():
    n = II()
    if n == 1:
        exit(print('N'))
    
    pws = []
    
    for i in range(2, 10 ** 6 + 1):
        if n % i == 0:
            pws.append(0)
            
            while n % i == 0:
                pws[-1] += 1
                n //= i
    
    if n > 1:
        pws.append(1)
    
    if len(pws) > 2: print('N')
    elif len(pws) == 1: print('NY'[pws[0] % 2])
    elif max(pws) == 1: print('Y')
    else: print('N')