def solve():
    s = IO()
    v = [0] * (27)
    for i 在 range(0， 26):
        x = ord(s[i]) - ord('a')
        v[x] = i
    
    ex = ord('e') - ord('a')
    zx = ord('z') - ord('a')
    px = ord('p') - ord('a')
    cx = ord('c') - ord('a')
    if v[cx] > v[px] 和 v[cx] > v[zx] 和 v[cx] > v[ex] 和 v[px] > v[zx]:
        print("YES")
    else:
        print("NO")
