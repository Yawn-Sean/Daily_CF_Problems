# Submission link: https://codeforces.com/contest/960/submission/263395689
def main():
    shifts = [0] * 61

    q = II()
    outs = []

    for _ in range(q):
        query = LII()
        if query[0] == 1:
            idx = query[1].bit_length()
            k = query[2]
            
            shifts[idx] += k
            shifts[idx] %= 1 << idx - 1
        
        elif query[0] == 2:
            idx = query[1].bit_length()
            k = query[2]
            
            for i in range(idx, 61):
                shifts[i] += k
                k %= 1 << i - 1
                shifts[i] %= 1 << i - 1
                k *= 2
        
        else:
            x = query[1]
            idx = x.bit_length()
            
            pos = (x - (1 << idx - 1) + shifts[idx]) % (1 << idx - 1)
            ans = []
            
            for i in range(idx, 0, -1):
                ans.append((1 << i - 1) + (pos - shifts[i]) % (1 << i - 1))
                pos //= 2
            
            outs.append(' '.join(map(str, ans)))

    print('\n'.join(outs))