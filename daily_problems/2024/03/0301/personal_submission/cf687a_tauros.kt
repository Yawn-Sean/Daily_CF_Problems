import java.io.InputStream
import java.io.Writer
import java.io.OutputStreamWriter
import java.io.BufferedWriter
import java.io.OutputStream
import java.io.PrintWriter
import java.io.Closeable

open class FastReader(private val input: InputStream, bufCap: Int = 8192) {
    companion object {
        private const val NC = 0.toChar()
    }

    private val buf = ByteArray(bufCap)
    private var bId = 0
    private var size = 0
    private var c = NC
    private val char: Char
        get() {
            while (bId == size) {
                size = input.read(buf) // no need for checked exceptions
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toInt().toChar()
        }

    private fun isWhitespace(c: Char) = c.code !in 33..126

    private fun skip(): Char {
        var b: Char
        while (char.also { b = it } != NC && isWhitespace(b));
        return b
    }

    fun ns() = buildString {
        while (true) {
            c = char
            if (!isWhitespace(c)) {
                break
            }
        }
        append(c)
        while (true) {
            c = char
            if (isWhitespace(c)) {
                break
            }
            append(c)
        }
    }

    fun ns(n: Int): CharArray {
        val buf = CharArray(n)
        var b = skip()
        var p = 0
        while (p < n && !isWhitespace(b)) {
            buf[p++] = b
            b = char
        }
        return if (n == p) buf else buf.copyOf(p)
    }

    fun ni(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }

    fun nl(): Long {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0L
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }

    fun na(n: Int) = IntArray(n) { ni() }
    fun nal(n: Int) = LongArray(n) { nl() }
    fun nad(n: Int) = DoubleArray(n) { nd() }
    fun nm(n: Int, m: Int) = Array(n) { ns(m) }
    fun nmi(n: Int, m: Int) = Array(n) { na(m) }
    fun nd() = ns().toDouble()
    fun nc() = skip()
}
open class FastWriter : Closeable {
    private val writer: PrintWriter

    constructor(output: OutputStream, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(OutputStreamWriter(output), bufCap))
    }

    constructor(writer: Writer, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(writer, bufCap))
    }

    override fun close() {
        writer.flush()
        try {
            writer.close()
        } catch (e: Exception) {
            e.printStackTrace()
        }
    }

    fun print(b: Boolean) = writer.print(b)
    fun print(c: Char) = writer.print(c)
    fun print(i: Int) = writer.print(i)
    fun print(l: Long) = writer.print(l)
    fun print(f: Float) = writer.print(f)
    fun print(d: Double) = writer.print(d)
    fun print(s: CharArray) = writer.print(s)
    fun print(s: String?) = writer.print(s)
    fun print(obj: Any?) = writer.print(obj)
    fun println() = writer.println()
    fun println(x: Boolean) = writer.println(x)
    fun println(x: Char) = writer.println(x)
    fun println(x: Int) = writer.println(x)
    fun println(x: Long) = writer.println(x)
    fun println(x: Float) = writer.println(x)
    fun println(x: Double) = writer.println(x)
    fun println(x: CharArray) = writer.println(x)
    fun println(x: String) = writer.println(x)
    fun println(x: Any) = writer.println(x)
    fun printf(format: String, vararg args: Any?) = writer.format(format, *args)
    fun flush() = writer.flush()
}
inline fun <reified T> ar(size: Int, init: (Int) -> T) = Array(size) { init(it) }
inline fun bar(size: Int, init: (Int) -> Boolean = { false }) = BooleanArray(size) { init(it) }
typealias boolean = Boolean
typealias int = Int
open class Graph(val nodeCap: Int, var edgeCap: Int = maxOf(nodeCap, MIN_EDGE_COUNT),
                 private val needFrom: Boolean = false, private val removeAble: Boolean = false) {
    companion object {
        val MAX_EDGE_COUNT = 1e8.toInt()
        val MIN_EDGE_COUNT = 10
    }

    var idx = -1
    var removed = 0
    val totalEdgeCnt: Int get() = idx + 1 - removed
    val first = IntArray(nodeCap) { -1 }
    val vtxEdgeCnt = IntArray(if (removeAble) nodeCap else 0)
    var to = IntArray(edgeCap)
    var next = IntArray(edgeCap)
    var from = IntArray(if (needFrom) edgeCap else 0)

    private fun newCapacity(old: Int) = minOf(MAX_EDGE_COUNT, maxOf(MIN_EDGE_COUNT, old + (old shr 1)))

    private fun ensureCapacityIncrement() {
        if (idx + 1 >= edgeCap) {
            val newCap = newCapacity(edgeCap)
            expand(newCap - edgeCap)
            edgeCap = newCap
        }
    }

    protected open fun expand(increment: Int) {
        edgeCap += increment
        to += IntArray(increment)
        next += IntArray(increment)
        if (needFrom) {
            from += IntArray(increment)
        }
    }

    fun addEdge(from: Int, to: Int): Int {
        ensureCapacityIncrement()
        val edgeId = ++this.idx
        if (this.needFrom) {
            this.from[edgeId] = from
        }
        this.to[edgeId] = to
        this.next[edgeId] = this.first[from]
        this.first[from] = edgeId
        if (removeAble) {
            this.vtxEdgeCnt[from] += 1
        }
        return edgeId
    }

    inline fun each(u: Int, start: Int = first[u], withEdgeId: (Int) -> Unit = {}) {
        var edgeId = start
        while (edgeId != -1) {
            withEdgeId(edgeId)
            edgeId = next[edgeId]
        }
    }

    inline fun each(withEdgeId: (Int) -> Unit = {}) {
        var edgeId = 0
        while (edgeId <= idx) {
            withEdgeId(edgeId)
            edgeId++
        }
    }

    inline fun eachBreakable(u: Int, start: Int = first[u], withEdgeId: (Int) -> Boolean = { false }) {
        var edgeId = start
        var isBreak = false
        while (edgeId != -1 && !isBreak) {
            isBreak = withEdgeId(edgeId)
            edgeId = next[edgeId]
        }
    }

    inline fun eachBreakable(withEdgeId: (Int) -> Boolean = { false }) {
        var edgeId = 0
        var isBreak = false
        while (edgeId <= idx && !isBreak) {
            isBreak = withEdgeId(edgeId)
            edgeId++
        }
    }

    fun clear(u: Int) {
        if (removeAble) {
            removed += vtxEdgeCnt[u]
            first[u] = -1
        }
    }
}
inline fun iar(size: Int, init: (Int) -> Int = { 0 }) = IntArray(size) { init(it) }
inline fun <reified T> mlo(vararg elements: T) = mutableListOf(*elements)

/**
 * generated by kotlincputil@tauros
 */
private val bufCap = 65536
private val rd = FastReader(System.`in`, bufCap)
private val wt = FastWriter(System.out, bufCap)
private fun solve() {
    // https://codeforces.com/problemset/problem/687/A
    // 相当于二分图染色
    val (n, m) = rd.ni() to rd.ni()
    val graph = Graph(n, m * 2)
    repeat(m) {
        val (u, v) = rd.ni() - 1 to rd.ni() - 1
        graph.addEdge(u, v); graph.addEdge(v, u)
    }

    val vis = bar(graph.totalEdgeCnt)
    val color = iar(n) { -1 }
    fun Graph.dfs(u: int, c: int): boolean {
        if (color[u] == c xor 1) return false
        if (color[u] == c) return true
        color[u] = c
        each(u) {
            if (vis[it]) return@each
            val v = to[it]
            vis[it] = true; vis[it xor 1] = true
            if (!dfs(v, c xor 1)) return false
        }
        return true
    }
    var success = true
    for (i in 0 until n) if (color[i] == -1) {
        if (!graph.dfs(i, 0)) success = false
        if (!success) break
    }

    if (!success) {
        wt.println(-1)
        return
    }
    val vtx = ar(2) { mlo<int>() }
    for (i in 0 until n) vtx[color[i]].add(i + 1)
    for (i in 0 until 2) {
        wt.println(vtx[i].size)
        for (res in vtx[i]) wt.print("$res ")
        wt.println()
    }
}
fun main(args: Array<String>) {
    solve()
    wt.flush()
}