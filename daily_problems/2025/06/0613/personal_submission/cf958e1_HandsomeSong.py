import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
a,b=MII()
print('Yes'if a==b else 'No')