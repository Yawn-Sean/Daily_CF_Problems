import sys
input = sys.stdin.readline
def II():
    return int(input())
n=II()
fun={0}
for a in range(10):
    for b in range(a,10):
        for l in range(1,11):
            for m in range(1,1<<10):
                x=0
                for i in range(l):
                    x=x*10+(b if m>>i&1 else a)
                if x<=10**9:
                    fun.add(x)
print(sum (1 for x in fun if x<=n-x and n-x in fun))