# Submission link: https://codeforces.com/gym/105297/submission/387530485
def main():
    x, y, z = MII()
    tx, ty, tz = LFI()
    R = LFI()[0]
    
    tx = fmax(tx, x - tx)
    ty = fmax(ty, y - ty)
    tz = fmax(tz, z - tz)
    
    l, r = 0, min(x, y, z) / 2
    
    for _ in range(100):
        mid = (l + r) / 2
        if math.hypot(tx - mid, ty - mid, tz - mid) >= R + mid:
            l = mid
        else:
            r = mid
    
    print((l + r) / 2)