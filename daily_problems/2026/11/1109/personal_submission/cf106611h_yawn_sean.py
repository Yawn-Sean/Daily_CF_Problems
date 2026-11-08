# Submission link: https://codeforces.com/gym/106611/submission/397860407
def main():
    hx, hy = MII()
    cx, cy = MII()
    d, u = MII()
    
    if abs(hx - cx) + abs(hy - cy) <= 1:
        print(1)
    else:
        mid = math.atan2(hy - cy, hx - cx)
        delta = math.asin(1 / math.hypot(hy - cy, hx - cx))
    
        l1, r1 = mid - delta, mid + delta
        l2, r2 = (d - u) / 180 * math.pi, (d + u) / 180 * math.pi
    
        overlap = 0
    
        for i in range(-1, 2):
            overlap += fmax(0, fmin(r1, r2 + i * math.pi * 2) - fmax(l1, l2 + i * math.pi * 2))
    
        print(overlap / (2 * u / 180 * math.pi))