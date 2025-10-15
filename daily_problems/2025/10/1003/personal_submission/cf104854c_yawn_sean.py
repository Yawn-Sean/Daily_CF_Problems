# Submission link: https://codeforces.com/gym/104854/submission/341572109
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        p = II()
        possible_bs = set()
        
        for b in range(1, 10 ** 6 + 1):
            if (p - 1) % (b + 1) == 0 and 2 * (p - 1) % (b + 2) == 0:
                possible_bs.add(b)
        
        for k in range(1, 2 * 10 ** 6 +  1):
            if 2 * (p - 1) % k == 0:
                v = 2 * (p - 1) // k
                b = (math.isqrt(4 * v + 1) - 1) // 2 - 1
                if b > 0 and (p - 1) % (b + 1) == 0 and 2 * (p - 1) % (b + 2) == 0:
                    possible_bs.add(b)
        
        possible_bs = sorted(possible_bs)
        outs.append(str(len(possible_bs)))
        outs.append(' '.join(map(str, possible_bs)))
    
    print('\n'.join(outs))