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
typealias int = Int
fun <T> Array<T>.swap(i: Int, j: Int) {
    val tmp = this[i]
    this[i] = this[j]
    this[j] = tmp
}
abstract class Heap<T>(var cap: Int = MIN_CAP) {
    companion object {
        val MIN_CAP = 10
        val MAX_CAP = 1e8.toInt()
    }

    protected var idx: Int = 0

    protected fun newCapacity(old: Int) = minOf(MAX_CAP, maxOf(MIN_CAP, old + (old shr 1)))

    fun offer(value: T) {
        if (idx >= cap) {
            val newCap = newCapacity(cap)
            expand(newCap - cap)
            cap = newCap
        }
        doOffer(value)
        afterOffer()
    }

    fun poll() = peek().also { afterPoll() }

    protected fun afterPoll() {
        swap(0, --idx)
        if (isEmpty()) return
        var iter = 0
        while (iter < idx) {
            val l = (iter shl 1) + 1
            val r = (iter shl 1) + 2
            if (l >= idx) break
            val next = if (r >= idx || compare(l, r) <= 0) l else r
            if (compare(iter, next) <= 0) break
            this.swap(iter, next)
            iter = next
        }
    }

    protected fun afterOffer() {
        var iter = idx++
        while (iter > 0) {
            val parent = (iter - 1) / 2
            if (compare(iter, parent) > 0) {
                break
            }
            swap(iter, parent)
            iter = parent
        }
    }

    abstract fun peek(): T
    protected abstract fun expand(increment: Int)
    protected abstract fun swap(p: Int, q: Int)
    protected abstract fun compare(indexA: Int, indexB: Int): Int
    protected abstract fun doOffer(new: T)
    val size: Int get() = idx
    fun isEmpty() = size <= 0
    fun isNotEmpty() = !isEmpty()
    fun clear() {
        idx = 0
    }
}
class KHeap<K>(initCap: Int = MIN_CAP, val keyComparator: (K, K) -> Int)
    : Heap<K>(initCap) {
    private var key = Array<Any?>(cap) { null }

    @Suppress("UNCHECKED_CAST")
    override fun peek() = key[0] as K

    override fun expand(increment: Int) {
        val newKeyArray = arrayOfNulls<Any?>(key.size + increment)
        key.copyInto(newKeyArray, 0, 0, key.size)
        key = newKeyArray
    }

    override fun swap(p: Int, q: Int) {
        key.swap(p, q)
    }

    @Suppress("UNCHECKED_CAST")
    override fun compare(indexA: Int, indexB: Int) = keyComparator(key[indexA] as K, key[indexB] as K)

    override fun doOffer(new: K) {
        key[idx] = new
    }
}

/**
 * generated by kotlincputil@tauros
 */
private val bufCap = 65536
private val rd = FastReader(System.`in`, bufCap)
private val wt = FastWriter(System.out, bufCap)
fun main(args: Array<String>) {
    // https://codeforces.com/problemset/problem/1498/E
    // https://www.luogu.com.cn/article/e6h0nij1
    // https://codeforces.com/blog/entry/89137
    // 竞赛图、哈密顿路径、强连通分量的拓扑序和入度的关系
    // 在这个拓扑序中，相邻的两个强连通分量，在前面的强连通分量的入度一定严格小于之后的
    // 因为在前面的强连通分量与之后的强连通的边的方向一定是从前向后的，否则他们就能成为同一个强连通分量
    // 因为还得争取度数差最大，所以得n^2logn
    // 很奇怪，直接用println和readln是会WA1的
    val n = rd.ni()
    val deg = rd.na(n)

    data class Query(val diff: int, val qFrom: int, val qTo: int)
    val heap = KHeap<Query> { a, b -> -a.diff.compareTo(b.diff) }
    for (i in 0 until n) for (j in i + 1 until n) {
        if (deg[i] < deg[j]) {
            // 那么i一定可达j
            heap.offer(Query(deg[j] - deg[i], j + 1, i + 1))
        } else {
            // 那么j一定可达i
            heap.offer(Query(deg[i] - deg[j], i + 1 , j + 1))
        }
    }

    while (heap.isNotEmpty()) {
        val (_, from, to) = heap.poll()
        wt.println("? $from $to")
        wt.flush()
        val ask = readln()
        if (ask == "Yes") {
            wt.println("! $from $to")
            wt.flush()
            return
        }
    }
    wt.println("! 0 0")
    wt.flush()
}