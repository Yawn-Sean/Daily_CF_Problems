fun main() {
    val a = ai(N)
    repeat(ri) {
        a[ri - 1] = 1
    }
    var b = 0
    val c = mutableListOf<Int>()
    val ans = mutableListOf<Int>()
    for (i in 0..<N/2) {
        if (a[i] + a[N - i - 1] == 2) b++
        else if (a[i] + a[N - i - 1] == 0) c.add(i)
        else ans.add(N - i * a[i] - (N - i - 1) * a[N - i - 1])
    }
    while (b > 0) {
        ans.add(c.last() + 1)
        ans.add(N - c.last())
        c.removeLast()
        b--
    }
    put(ans.size)
    put(*ans.toTypedArray())
    done()
}
