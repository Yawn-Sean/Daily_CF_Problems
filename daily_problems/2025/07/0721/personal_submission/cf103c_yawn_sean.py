# Submission link: https://codeforces.com/contest/103/submission/330009028
def main():
    n, k, p = MII()
    outs = []

    for _ in range(p):
        x = II()
        
        if k == 0: outs.append('.')
        else:
            vn, vk = n, k
            if n % 2:
                if x == n:
                    outs.append('X')
                    continue
                else:
                    vn -= 1
                    vk -= 1
            
            if vk * 2 <= vn:
                if x % 2 == 0 and x // 2 + vk > vn // 2:
                    outs.append('X')
                else:
                    outs.append('.')
            else:
                if x % 2 == 0: outs.append('X')
                elif (x + 1) // 2 + (vk - vn // 2) > vn // 2:
                    outs.append('X')
                else: outs.append('.')

    print(''.join(outs))