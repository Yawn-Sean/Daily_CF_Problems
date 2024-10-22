# Submission link: https://codeforces.com/contest/550/submission/287288693
def main():
    k = II()

    if k % 2 == 0: print('NO')
    else:
        outs = []
        for i in range(k - 1):
            
            for j in range(k - 1):
                outs.append(f'{i + 1} {j + k}')
                outs.append(f'{i + 2 * k - 1} {j + 3 * k - 2}')
            
            if i % 2 == 0:
                outs.append(f'{i + 1} {i + 2}')
                outs.append(f'{i + 2 * k - 1} {i + 2 * k}')
            
            outs.append(f'{i + k} {4 * k - 3}')
            outs.append(f'{i + 3 * k - 2} {4 * k - 2}')
        
        outs.append(f'{4 * k - 3} {4 * k - 2}')
        
        print('YES')
        print(4 * k - 2, len(outs))
        print('\n'.join(outs))