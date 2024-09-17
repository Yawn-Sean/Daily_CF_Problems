# Submission link: https://codeforces.com/contest/641/submission/281421599
def main():
    n, q = MII()
    
    even_move = 0
    odd_move = 0
    swap = 0
    
    for i in range(q):
        query = LII()
        if query[0] == 1:
            odd_move += query[1]
            even_move += query[1]
            swap ^= query[1] % 2
        else:
            if swap:
                even_move += 1
                odd_move -= 1
            else:
                even_move -= 1
                odd_move += 1
            swap ^= 1
    
    ans = [-1] * n
    for i in range(n):
        if i % 2 == 0:
            ans[(i + odd_move) % n] = i + 1
        else:
            ans[(i + even_move) % n] = i + 1
    
    print(' '.join(map(str, ans)))