import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    tree_height = n.bit_length()
    # 畫圖觀察二進制關係:
    # lowbit: (tree_height-位數+1)決定在哪一層
    # lowbit與上一位: 01為左子樹，11為右子樹
    # U->L: u += (lb >> 1) - lb
    # U->R: u += lb >> 1
    # L->U: u += lb
    # R->U: u -= lb
    for _ in range(q):
        u = int(input())
        s = input()
        for c in s:
            lb = u & -u
            layer = tree_height - lb.bit_length() + 1
            tp = 'L' if u >> 1 & lb == 0 else 'R'
            if c == 'U':
                if layer == 1:
                    continue
                if tp == 'L':
                    u += lb
                else:
                    u -= lb
            else:
                if layer == tree_height:
                    continue
                if c == 'L':
                    u += (lb >> 1) - lb
                else:
                    u += lb >> 1
        print(u)
               
for _ in range(1):
    n, q = MII()
    solve()