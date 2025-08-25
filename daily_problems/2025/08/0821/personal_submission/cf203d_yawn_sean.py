# Submission link: https://codeforces.com/contest/203/submission/334662303
def main():
    a, b, m = MII()
    vx, vy, vz = MII()
    
    time = -m / vy
    
    x = a / 2 + vx * time
    z = vz * time
    
    x %= 2 * a
    z %= 2 * b
    
    if x >= a: x = 2 * a - x
    if z >= b: z = 2 * b - z
    print(x, z)