# Submission link: https://codeforces.com/gym/103150/submission/376975517
def main():
    t = II()
    outs = []
    
    xe = ord('e') - ord('a')
    xz = ord('z') - ord('a')
    xp = ord('p') - ord('a')
    xc = ord('c') - ord('a')
    
    for _ in range(t):
        s = [ord(c) - ord('a') for c in I()]
    
        pos = [0] * 26
        for i in range(26):
            pos[s[i]] = i
        
        pe = pos[xe]
        pz = pos[xz]
        pp = pos[xp]
        pc = pos[xc]
        
        if pe < pc and pz < pp and pp < pc: outs.append('YES')
        else: outs.append('NO')
    
    print('\n'.join(outs))