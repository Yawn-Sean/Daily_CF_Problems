# Submission link: https://codeforces.com/gym/106369/submission/363404260
def main(): 
    y, x, r = MII()
    x = abs(x)
    
    if x * x * y * y > r * r * (x * x + y * y):
        print(-1)
    elif r >= x:
        print(0)
    else:
        print((math.asin(y / math.hypot(x, y) / r * x) - math.atan2(y, x)) / math.pi * 180)