MOD = 10**9 + 7
MAX_SUM = 2600
MAX_N = 100

def init():
    f = [[0] * (MAX_N + 1) for _ in range(MAX_SUM + 1)]
    f[0][0] = 1
    for i in range(1, MAX_SUM + 1):
        for j in range(1, min(i, MAX_N) + 1):
            for k in range(1, min(26, i) + 1):
                f[i][j] = (f[i][j] + f[i - k][j - 1]) % MOD
    return f

def main():
    f = init()
    import sys
    input = sys.stdin.read
    data = input().split()
    
    T = int(data[0])
    results = []
    
    index = 1
    for _ in range(T):
        s = data[index]
        index += 1
        sum_val = sum(ord(c) - 96 for c in s)
        n = len(s)
        result = f[sum_val][n] - 1
        results.append(result)
    
    for result in results:
        print(result)
