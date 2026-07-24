# Submission link: https://codeforces.com/gym/104670/submission/384016784
def main():
    n = II()
    xs = []
    ys = []
    rs = []
    
    for _ in range(n):
        x, y, r = MII()
        xs.append(x)
        ys.append(y)
        rs.append(r)
    
    import time
    t = time.time()
    
    freq = 0
    total = 0
    
    while time.time() - t < 2.5:
        x = random.random() * 30 - 10
        y = random.random() * 30 - 10
        
        total += 1
        for i in range(n):
            vx = xs[i]
            vy = ys[i]
            r = rs[i]
            
            if (x - vx) * (x - vx) + (y - vy) * (y - vy) <= r * r:
                freq += 1
                break
    
    print(freq / total * 900)