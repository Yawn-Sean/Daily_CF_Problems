import sys
from math import gcd
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
def LI():
    return list(input().strip())
def I():
    return input().strip()
t=II()
valid={(2,3),(3,2),(3,4),(4,3),(5,6),(6,5)}
for _ in range(t):
    a,b=MII()
    g=gcd(a,b)
    a_prime=a//g
    b_prime=b//g
    if (a_prime,b_prime) in valid:
        print("SI")
    elif (a_prime,b_prime) in {(1,2),(2,1)} and (min(a,b)%2==0 or min(a,b)%3==0):
        print("SI")
    elif a_prime==b_prime==1 and a%2==0:
        print('SI')
    else:
        print('NO')
    