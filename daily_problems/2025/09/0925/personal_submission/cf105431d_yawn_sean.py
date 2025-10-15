# Submission link: https://codeforces.com/gym/105431/submission/340106175
def main():
    n, k = MII()
    v1 = LII()
    v2 = LII()
    
    pos = [[] for _ in range(n + 1)]
    
    for i in range(n * k - 1, -1, -1):
        pos[v2[i]].append(i)
    
    fen = MaxFenwickTree(n * k + 1)
    
    for i in range(n * k):
        for j in pos[v1[i]]:
            fen.set(j + 1, fen.prefmax(j) + 1)
    
    print(fen.prefmax(n * k))