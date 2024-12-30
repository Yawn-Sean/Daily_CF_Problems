# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
TI = lambda: tuple(MI())
LGMI = lambda: list(GMI())

k, a, b = MI()
a -= 1
b -= 1
mtx1 = [LGMI() for _ in range(3)]
mtx2 = [LGMI() for _ in range(3)]

score = [
    [0, 0, 1],
    [1, 0, 0],
    [0, 1, 0],
]

A = []
B = []
D = []
while True:
    A.append(score[a][b])
    B.append(score[b][a])
    na, nb = mtx1[a][b], mtx2[a][b]
    if (a, b, na, nb) in D:
        A.pop()
        B.pop()
        idx = D.index((a, b, na, nb))
        break
    D.append((a, b, na, nb))
    a, b = na, nb
# print(A)
# print(B)
# print(D)
# print(idx)

alice = bob = 0
if k <= idx:
    alice += sum(A[:k])
    bob += sum(B[:k])
else:
    alice += sum(A[:idx])
    bob += sum(B[:idx])
    k -= idx
    A = A[idx:]
    B = B[idx:]
    c1, c2 = divmod(k, len(A))
    alice += c1 * sum(A) + sum(A[:c2])
    bob += c1 * sum(B) + sum(B[:c2])
print(alice, bob)

