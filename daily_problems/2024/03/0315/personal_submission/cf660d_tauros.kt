import java.io.InputStream
import java.io.Writer
import java.io.OutputStreamWriter
import java.io.BufferedWriter
import java.io.OutputStream
import java.io.PrintWriter
import java.io.Closeable
import java.util.function.BiConsumer
import java.util.function.Function
import java.util.function.BiFunction

open class FastReader(private val input: InputStream, bufCap: Int = 8192) {
    companion object { private const val NC = 0.toChar() }
    private val buf = ByteArray(bufCap)
    private var bId = 0
    private var size = 0
    private var c = NC
    private val char: Char
        get() {
            while (bId == size) { size = input.read(buf); if (size == -1) return NC; bId = 0 }
            return buf[bId++].toInt().toChar()
        }
    private fun isWhitespace(c: Char) = c.code !in 33..126
    private fun skip(): Char { var b: Char; while (char.also { b = it } != NC && isWhitespace(b)); return b }
    fun ns() = buildString {
        while (true) { c = char; if (!isWhitespace(c)) break }; append(c);
        while (true) { c = char; if (isWhitespace(c)) break; append(c) }
    }
    fun ns(n: Int): CharArray {
        val buf = CharArray(n); var (b, p) = skip() to 0
        while (p < n && !isWhitespace(b)) { buf[p++] = b;b = char }
        return if (n == p) buf else buf.copyOf(p)
    }
    fun ni(): Int {
        var neg = false; if (c == NC) c = char
        while (c < '0' || c > '9') { if (c == '-') neg = true;c = char }
        var res = 0; while (c in '0'..'9') { res = (res shl 3) + (res shl 1) + (c - '0'); c = char }
        return if (neg) -res else res
    }
    fun nl(): Long {
        var neg = false; if (c == NC) c = char
        while (c < '0' || c > '9') { if (c == '-') neg = true; c = char }
        var res = 0L; while (c in '0'..'9') { res = (res shl 3) + (res shl 1) + (c - '0'); c = char }
        return if (neg) -res else res
    }
    fun na(n: Int) = IntArray(n) { ni() }; fun nal(n: Int) = LongArray(n) { nl() }; fun nad(n: Int) = DoubleArray(n) { nd() }
    fun nm(n: Int, m: Int) = Array(n) { ns(m) }; fun nmi(n: Int, m: Int) = Array(n) { na(m) }
    fun nd() = ns().toDouble(); fun nc() = skip()
}
open class FastWriter : Closeable {
    private val writer: PrintWriter
    constructor(output: OutputStream, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(OutputStreamWriter(output), bufCap))
    }
    constructor(writer: Writer, bufCap: Int = 8192) {
        this.writer = PrintWriter(BufferedWriter(writer, bufCap))
    }
    override fun close() { writer.flush(); try { writer.close() } catch (e: Exception) { e.printStackTrace() } }
    fun print(b: Boolean) = writer.print(b); fun print(c: Char) = writer.print(c); fun print(i: Int) = writer.print(i)
    fun print(l: Long) = writer.print(l); fun print(f: Float) = writer.print(f); fun print(d: Double) = writer.print(d)
    fun print(s: CharArray) = writer.print(s); fun print(s: String?) = writer.print(s);
    fun print(obj: Any?) = writer.print(obj)
    fun println() = writer.println(); fun println(x: Boolean) = writer.println(x); fun println(x: Char) = writer.println(x)
    fun println(x: Int) = writer.println(x); fun println(x: Long) = writer.println(x); fun println(x: Float) = writer.println(x)
    fun println(x: Double) = writer.println(x); fun println(x: CharArray) = writer.println(x); fun println(x: String) = writer.println(x)
    fun println(x: Any) = writer.println(x)
    fun printf(format: String, vararg args: Any?) = writer.format(format, *args)
    fun flush() = writer.flush()
}
inline fun <reified T> ar(size: Int, init: (Int) -> T) = Array(size) { init(it) }
typealias int = Int
typealias long = Long
fun sqrt(n: Long): Long {
    if (n == 0L) return 0
    var x: Long = 1
    var decreased = false
    while (true) {
        val nx = x + n / x shr 1
        if (x == nx || nx > x && decreased) break
        decreased = nx < x
        x = nx
    }
    return x
}
data class IPoint2(val x: Int, val y: Int) {
    fun toVector() = IVector2(x, y)
    operator fun plus(other: IVector2) = IPoint2(x + other.x, y + other.y)
    operator fun minus(other: IVector2) = IPoint2(x - other.x, y - other.y)
    operator fun minus(other: IPoint2) = IVector2(x - other.x, y - other.y)
    override fun equals(other: Any?): Boolean {
        return if (other === this) true
        else if (other !is IPoint2) false
        else x == other.x && y == other.y
    }
    override fun hashCode() = x.hashCode() xor y.hashCode()
    override fun toString() = "($x,$y)"
}
data class IVector2(val x: Int, val y: Int) {
    fun len2() = x.toLong() * x + y.toLong() * y
    fun len() = sqrt(len2())
    operator fun plus(other: IVector2) = IVector2(x + other.x, y + other.y)
    operator fun minus(other: IVector2) = IVector2(x - other.x, y - other.y)
    // cos
    infix fun dot(other: IVector2) = x.toLong() * other.x + y.toLong() * other.y
    // sin
    infix fun cross(other: IVector2) = x.toLong() * other.y - other.x * y.toLong()
    infix fun isParallel(other: IVector2) = (this cross other) == 0L
    infix fun isPerpendicular(other: IVector2) = (this dot other) == 0L
    infix fun side(other: IVector2) = (this cross other).let { if (it < 0) -1 else if (it > 0) 1 else 0 }
    override fun equals(other: Any?): Boolean {
        return if (other === this) true
        else if (other !is IVector2) false
        else x == other.x && y == other.y
    }
    override fun hashCode() = x.hashCode() xor y.hashCode()
    override fun toString() = "($x,$y)"
}
inline fun <reified K, reified V> mmo(vararg pairs: Pair<K, V>) = mutableMapOf(*pairs)
open class DefaultMutableMap<K, V, D : MutableMap<K, V>>(protected val delegate: D, protected val default: (K) -> V) : MutableMap<K, V> {
    override val entries: MutableSet<MutableMap.MutableEntry<K, V>>
        get() = delegate.entries
    override val keys: MutableSet<K>
        get() = delegate.keys
    override val size: Int
        get() = delegate.size
    override val values: MutableCollection<V>
        get() = delegate.values

    override fun clear() = delegate.clear()
    override fun compute(key: K, remappingFunction: BiFunction<in K, in V?, out V?>) = delegate.compute(key, remappingFunction)
    override fun computeIfAbsent(key: K, mappingFunction: Function<in K, out V>) = delegate.computeIfAbsent(key, mappingFunction)
    override fun computeIfPresent(key: K, remappingFunction: BiFunction<in K, in V & Any, out V?>) = delegate.computeIfPresent(key, remappingFunction)
    override fun merge(key: K, value: V & Any, remappingFunction: BiFunction<in V & Any, in V & Any, out V?>) = delegate.merge(key, value, remappingFunction)
    override fun put(key: K, value: V) = delegate.put(key, value)
    override fun putAll(from: Map<out K, V>) = delegate.putAll(from)
    override fun putIfAbsent(key: K, value: V) = delegate.putIfAbsent(key, value)
    override fun remove(key: K) = delegate.remove(key)
    override fun remove(key: K, value: V) = delegate.remove(key, value)
    override fun replace(key: K, oldValue: V, newValue: V) = delegate.replace(key, oldValue, newValue)
    override fun replace(key: K, value: V) = delegate.replace(key, value)
    override fun replaceAll(function: BiFunction<in K, in V, out V>) = delegate.replaceAll(function)
    override fun containsKey(key: K) = delegate.containsKey(key)
    override fun containsValue(value: V) = delegate.containsValue(value)
    override fun forEach(action: BiConsumer<in K, in V>) = delegate.forEach(action)
    override fun getOrDefault(key: K, defaultValue: V) = delegate.getOrDefault(key, defaultValue)
    override fun isEmpty() = delegate.isEmpty()
    override operator fun get(key: K) = delegate[key] ?: default(key)
}
fun <K, V> MutableMap<K, V>.default(default: (K) -> V) = DefaultMutableMap(this, default)

/**
 * generated by kotlincputil@tauros
 */
private val bufCap = 65536
private val rd = FastReader(System.`in`, bufCap)
private val wt = FastWriter(System.out, bufCap)
private fun solve() {
    // https://codeforces.com/problemset/problem/660/D
    // 把带模长的向量哈希一下，统计数量
    // 注意保证向量的正反关系，需要排序保证下
    val n = rd.ni()
    val points = ar(n) { IPoint2(rd.ni(), rd.ni()) }

    points.sortWith { a, b -> if (a.x == b.x) a.y.compareTo(b.y) else a.x.compareTo(b.x) }

    val cap = 1e9.toInt()
    val base = cap * 2L + 2
    val cnt = mmo<long, int>().default { 0 }
    var ans = 0L
    for (i in 0 until n) {
        for (j in 0 until i) {
            val vector = points[j] - points[i]
            val (x, y) = vector
            val (mx, my) = x + cap to y + cap
            val id = mx * base + my
            ans += cnt[id]
            cnt[id] += 1
        }
    }
    wt.println(ans / 2)
}
fun main(args: Array<String>) {
    solve()
    wt.flush()
}