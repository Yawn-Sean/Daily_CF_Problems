private fun solve() {
    // https://codeforces.com/problemset/submission/769/299457889
    // 别dfs，会炸，学羊解的只要贪心能走就行，走出去距离保证能回来就一直贪心走就可以，所以直接循环模拟走就好了
    val (n, m, k) = rd.na(3)
    var (stX, stY) = iar(2)
    val grid = ar(n) { i ->
        car(m) { j ->
            rd.nc().also {
                if (it == 'X') {
                    stX = i; stY = j
                }
            }
        }
    }
    if (k % 2 != 0) {
        wt.println("IMPOSSIBLE")
        return
    }

    data class Op(val di: int, val dj: int, val sym: char)
    val ops = ao(
        Op(1, 0, 'D'),
        Op(0, -1, 'L'),
        Op(0, 1, 'R'),
        Op(-1, 0, 'U')
    )

    val dist = iar(n * m) { -1 }
    val q = iar(n * m)
    var (head, tail) = 0 to 0
    q[tail++] = stX * m + stY
    dist[stX * m + stY] = 0
    while (head < tail) {
        val (x, y) = q[head] / m to q[head] % m
        head += 1
        for ((di, dj) in ops) {
            val (nx, ny) = x + di to y + dj
            val next = nx * m + ny
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '*' || dist[next] != -1) continue
            dist[next] = dist[x * m + y] + 1
            q[tail++] = next
        }
    }

    val road = car(k)
    var (x, y) = stX to stY
    var success = false
    for (i in 0 until k) {
        for ((di, dj, sym) in ops) {
            val (nx, ny) = x + di to y + dj
            val next = nx * m + ny
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '*' || dist[next] == -1 || dist[next] > k - i - 1) continue
            road[i] = sym
            x = nx; y = ny
            success = true
            break
        }
    }
    if (success) {
        val ans = road.joinToString("")
        wt.println(ans)
    } else {
        wt.println("IMPOSSIBLE")
    }
}

fun main(args: Array<String>) {
    solve()
    wt.flush()
}