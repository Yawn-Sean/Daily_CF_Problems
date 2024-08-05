def main():
    data = input().split()
    idx = 0
    def read():
        nonlocal idx
        val = int(data[idx])
        idx += 1
        return val
    
    n = read()
    m = read()
    c = read()
    
    maxn = 105
    sum = [[[0] * maxn for _ in range(maxn)] for _ in range(11)]
    
    for i in range(n):
        x = read()
        y = read()
        s = read()
        for j in range(c + 1):
            sum[j][x][y] += (s + j) % (c + 1)
    
    for k in range(c + 1):
        for i in range(1, 100 + 1):
            for j in range(1, 100 + 1):
                sum[k][i][j] += sum[k][i - 1][j] + sum[k][i][j - 1] - sum[k][i - 1][j - 1]
    
    results = []
    for i in range(m):
        t = read()
        x1 = read()
        y1 = read()
        x2 = read()
        y2 = read()
        t %= (c + 1)
        result = sum[t][x2][y2] - sum[t][x1 - 1][y2] - sum[t][x2][y1 - 1] + sum[t][x1 - 1][y1 - 1]
        results.append(result)
    
    for res in results:
        print(res)
