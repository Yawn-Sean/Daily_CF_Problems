def main():
    n, k, x = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    a.sort()
    
    history = {}
    history[tuple(a)] = 0
    min_history = [a[0]]
    max_history = [a[-1]]
    
    for step in range(1, k + 1):
        for i in range(0, n, 2):
            a[i] ^= x
        a.sort()
        current = tuple(a)
        
        if current in history:
            cycle_start = history[current]
            cycle_length = step - cycle_start
            remaining = (k - cycle_start) % cycle_length
            final_step = cycle_start + remaining
            print(max_history[final_step], min_history[final_step])
            return
        
        history[current] = step
        min_history.append(a[0])
        max_history.append(a[-1])
    
    print(a[-1], a[0])
