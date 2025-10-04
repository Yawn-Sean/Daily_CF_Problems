# Submission link: https://codeforces.com/gym/105822/submission/341614854
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        s = I()
        if s.count('E') % 2: outs.append('NO')
        else:
            outs.append('YES')
            pt1 = 1
            pt2 = 2
            
            for i in range(n):
                if s[i] == 'O':
                    outs.append(f'{pt1} {pt2}')
                    pt1 += 2
                    pt2 += 2
                elif pt1 < pt2:
                    outs.append(f'{pt1} {pt1 + 2}')
                    pt1 += 4
                else:
                    outs.append(f'{pt2} {pt2 + 2}')
                    pt2 += 4
    
    print('\n'.join(outs))