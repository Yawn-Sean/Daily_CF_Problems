import kotlin.math.abs
import kotlin.random.Random

typealias LLP = Pair<Long, Long>
typealias boolean = Boolean
typealias int = Int
typealias long = Long

private fun solve() {
    // https://codeforces.com/problemset/problem/1039/B
    // 将 [l, r] 一分为二，查询 [l, mid]，成功则在 [l - k, mid + k]，否则在[mid + 1 - k, r + k]
    // 到一定区间内就直接猜位置，留4400次用于猜一次二分一次，那么 ((len - 1) / len) ^ 2200 < 1e-9 绝对够用
    // 解出len只要在100以内即可，失败一次最多变成120，二分一次一定小于100
    // 二分到区间不会减小时 len=4k，100肯定是OK的
    val (n, k) = readln().trim().split(" ").map { it.toLong() }

    fun query(cl: long, cr: long): int {
        println("$cl $cr")
        val str = readln()
        return if (str == "Yes" && cl == cr || str == "Bad") -1
        else if (str == "Yes") 1 else 0
    }
    fun ask(cl: long, cr: long, guess: boolean = false): LLP {
        return if (guess) {
            val pos = cl + abs(Random.nextInt()) % (cr - cl + 1)
            val qry = query(pos, pos)
            if (qry == 1) pos to pos
            else if (qry == 0) maxOf(1, cl - k) to minOf(n, cr + k)
            else -1L to -1
        } else {
            val mid = cl + cr shr 1
            val qry = query(cl, mid)
            if (qry == 1) maxOf(1, cl - k) to minOf(n, mid + k)
            else if (qry == 0) maxOf(1, mid + 1 - k) to minOf(n, cr + k)
            else -1L to -1
        }
    }

    var range = 1L to n
    fun end() = range.first == -1L
    out@ while (true) {
        while (true) {
            val (st, ed) = range
            if (ed - st < 100) break
            range = ask(st, ed)
            if (end()) break@out
        }
        val (st, ed) = range
        range = ask(st, ed, true)
        if (end()) break@out
    }
}

fun main(args: Array<String>) {
    solve()
}
