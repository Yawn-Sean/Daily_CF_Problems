# Submission link: https://codeforces.com/contest/306/submission/298740967
def main():
    n = II()
    if n <= 4: print('No solution')
    else:
        angle = math.acos(-1) * 2 / n
        step = 500
        cur = 0
        
        x, y = 0, 0
        outs = []
        for i in range(1, n):
            outs.append(f'{x} {y}')
            cur += angle
            step += 0.01
            if i < n - 1:
                x += step * math.cos(cur)
                y += step * math.sin(cur)
        outs.append(f'{x - y / math.tan(cur)} 0')
        print('\n'.join(outs))