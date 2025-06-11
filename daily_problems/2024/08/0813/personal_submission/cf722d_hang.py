from queue import PriorityQueue
def main():
    n = int(input())
    y = list(map(int, input().split()))
    pq = PriorityQueue()
    used = set(y)
    for i in y:
        pq.put(-i)
    while True:
        x = -pq.get()
        t = x
        while t in used:
            t //= 2
        if t == 0:
            pq.put(-x)
            break
        pq.put(-t)
        used.add(t)
        used.remove(x)
    ans = []
    while not pq.empty():
        ans.append(-pq.get())
    print(*ans)
main()