# Submission link: https://codeforces.com/gym/105446/submission/371754900
def main():
    n = II()
    
    acc_x = [0] * (n + 1)
    acc_y = [0] * (n + 1)
    acc_x2 = [0] * (n + 1)
    acc_xy = [0] * (n + 1)
    
    for i in range(n):
        x, y = LFI()
        acc_x[i + 1] = acc_x[i] + x
        acc_y[i + 1] = acc_y[i] + y
        acc_x2[i + 1] = acc_x2[i] + x * x
        acc_xy[i + 1] = acc_xy[i] + x * y
    
    q = II()
    outs = []
    
    for _ in range(q):
        l, r, lamb, x = LI()
        l = int(l) - 1
        r = int(r)
        lamb = float(lamb)
        x = float(x)
        
        vx = acc_x[r] - acc_x[l]
        vy = acc_y[r] - acc_y[l]
        vx2 = acc_x2[r] - acc_x2[l]
        vxy = acc_xy[r] - acc_xy[l]
        
        delta = (vx2 + lamb) * (r - l + lamb) - vx * vx
        k = ((r - l + lamb) * vxy - vx * vy) / delta
        b = ((vx2 + lamb) * vy - vx * vxy) / delta
        
        outs.append(k * x + b)
    
    print('\n'.join(map(str, outs)))