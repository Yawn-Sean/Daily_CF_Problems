'''
https://codeforces.com/gym/105582/my#
'''
# ref
def solve(n: int) -> list[list[int]]:
    pa = []
    if n & 1:
        pa.append([0, 0])
        
        x, y = 0, 0
        for i in range(n // 2 - 1):
            y += 25
            pa.append([x, y])
            x += 25
            pa.append([x, y])
        
        x = max(x, 25)
        pa.append([x, 0])
        pa.append([x // 25 * 9, -x // 25 * 12])
    
    else:
        pa.append([0, 0])
        
        x, y = 0, 0
        for i in range(n // 2 - 1):
            y += 25
            pa.append([x, y])
            x += 25
            pa.append([x, y])
        
        pa.append([x, 0])
    
    dx, dy = 5, 12
    
    return [[x * dx + y * dy, x * (-dy) + y * dx] for x, y in pa]
