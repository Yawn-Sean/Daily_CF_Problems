import sys
import math

input = lambda: sys.stdin.readline().strip()

X = 1e9 + 7
n = int(input())


print(int((pow(3, 3*n, int(X))-pow(7, n, int(X)))%X))
