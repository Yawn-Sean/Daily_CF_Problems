# Submission link: https://codeforces.com/contest/1027/submission/290472440
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        nums = LII()
        
        cnt = Counter(nums)
        tmp = []
        
        flg = False
        for k, v in cnt.items():
            if v >= 4:
                outs.append(f'{k} {k} {k} {k}')
                flg = True
                break
            if v >= 2:
                tmp.append(k)
        
        if not flg:
            tmp.sort()
            
            x, y = 1, 0
            for i in range(1, len(tmp)):
                nx, ny = tmp[i], tmp[i - 1]
                if nx * y < x * ny:
                    x, y = nx, ny

            outs.append(f'{x} {x} {y} {y}')

    print('\n'.join(outs))