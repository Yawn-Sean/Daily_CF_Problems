@file:Suppress("NOTHING_TO_INLINE", "EXPERIMENTAL_FEATURE_WARNING", "OVERRIDE_BY_INLINE", "DEPRECATION")
@file:OptIn(ExperimentalStdlibApi::class)

import java.io.PrintWriter
import java.util.StringTokenizer
import kotlin.collections.ArrayDeque
import kotlin.math.*
import kotlin.random.Random
import java.util.TreeMap
import java.util.TreeSet
import java.util.PriorityQueue
// import java.math.BigInteger
// import java.util.BitSet
// import java.util.*

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val reader = INPUT.bufferedReader()
fun readLine(): String? = reader.readLine()
fun readLn() = reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int = 2) = List(n) { read() }
fun readString() = readStrings(1)[0]
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int = 2) = List(n) { read().toInt() }
fun readInts1(n: Int = 2) = List(n) { read().toInt() - 1 }
fun readIntArray(n: Int = 2) = IntArray(n) { read().toInt() }
fun readIntArray1(n: Int = 2) = IntArray(n) { read().toInt() - 1 }
fun readDoubles(n: Int = 2) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int = 2) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int = 2) = List(n) { read().toLong() }
fun readLongs1(n: Int = 2) = List(n) { read().toLong() - 1L }
fun readLongArray(n: Int = 2) = LongArray(n) { read().toLong() }
fun readLongArray1(n: Int = 2) = LongArray(n) { read().toLong() - 1L }

// val isLocal = System.getenv("IS_LOCAL_CP") == "true"

@JvmField
val writer = PrintWriter(OUTPUT)

// ----------------------------------------------------------------------------

class UnionFind {

    private val parents = mutableMapOf<Int, Int>()
    private val sizes = mutableMapOf<Int, Int>()

    fun union(a: Int, b: Int) {
        val fa = find(a)
        val fb = find(b)
        if (fa != fb) {
            parents[fa] = fb
            sizes[fb] = (sizes[fb] ?: 1) + (sizes[fa] ?: 1)
        }
    }

    fun find(a: Int): Int {
        fun getOrDefault(value: Int) = parents.getOrDefault(value, value)

        var parent = getOrDefault(a)
        while (parent != getOrDefault(parent)) {
            parents[parent] = getOrDefault(getOrDefault(parent))
            parent = parents[parent]!!
        }
        return parent
    }

    fun connected(a: Int, b: Int): Boolean {
        return find(a) == find(b)
    }

    fun getSize(a: Int): Int {
        return sizes[find(a)] ?: 1
    }
}

class UnionFindArray(private val n: Int) {

    private val parents = IntArray(n + 1) { it }
    private val sizes = IntArray(n + 1) { 1 }

    fun union(a: Int, b: Int) {
        val fa = find(a)
        val fb = find(b)
        if (fa != fb) {
            parents[fa] = fb
            sizes[fb] += sizes[fa]
        }
    }

    fun find(a: Int): Int {
        var parent = parents[a]
        while (parent != parents[parent]) {
            parents[parent] = parents[parents[parent]]
            parent = parents[parent]
        }
        return parent
    }

    fun connected(a: Int, b: Int): Boolean {
        return find(a) == find(b)
    }

    fun getSize(a: Int): Int {
        return sizes[find(a)]
    }
}

class Trie() {

    /** Initialize your data structure here. */
    private val root = Node()

    /** Inserts a word into the trie. */
    fun insert(word: String) {
        var node = root
        for (char in word) {
            if (!node.children.contains(char)) {
                node.children[char] = Node()
            }
            node = node.children[char]!!
        }
        node.hasWord = true
    }

    /** Returns if the word is in the trie. */
    fun search(word: String): Boolean {
        return findNode(word)?.hasWord ?: false
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    fun startsWith(prefix: String): Boolean {
        return findNode(prefix) != null
    }

    private fun findNode(prefix: String): Node? {
        var node = root
        for (char in prefix) {
            node = node.children[char] ?: return null
        }
        return node
    }

    private class Node(
        var hasWord: Boolean = false,
        val children: MutableMap<Char, Node> = mutableMapOf<Char, Node>()
    )
}

// 所有函数的下标从 0 开始
// query(index): sum[0, index]
// query(left, right): sum[left, right]
class BinaryIndexedTree {

    private val bit: IntArray

    constructor(n: Int) {
        this.bit = IntArray(n + 1)
    }

    constructor(nums: IntArray) {
        this.bit = IntArray(nums.size + 1)
        val prefix = IntArray(bit.size)
        for (i in 1 until nums.size + 1) {
            prefix[i] = prefix[i - 1] + nums[i - 1]
            bit[i] = prefix[i] - prefix[i - lowbit(i)]
        }
    }

    fun query(index: Int): Int {
        var result = 0
        var i = index + 1
        while (i > 0) {
            result += bit[i]
            i -= lowbit(i)
        }
        return result
    }

    fun query(left: Int, right: Int): Int {
        return query(right) - (if (left == 0) 0 else query(left - 1))
    }

    fun update(index: Int, x: Int) {
        val value = query(index) - query(index - 1)
        add(index, x - value)
    }

    fun add(index: Int, x: Int) {
        var i = index + 1
        while (i < bit.size) {
            bit[i] += x
            i += lowbit(i)
        }
    }

    override fun toString(): String {
        return IntArray(bit.size - 1) { query(it) - query(it - 1) }.toList().toString()
    }

    private fun lowbit(x: Int): Int {
        return x.and(-x)
    }
}

class BinaryIndexedTreeMod {

    private val bit: LongArray

    constructor(n: Int) {
        this.bit = LongArray(n + 1)
    }

    constructor(nums: List<Int>) {
        this.bit = LongArray(nums.size + 1)
        val prefix = LongArray(bit.size)
        for (i in 1 until nums.size + 1) {
            prefix[i] = prefix[i - 1] + nums[i - 1]
            bit[i] = prefix[i] - prefix[i - lowbit(i)]
        }
    }

    fun query(index: Int): Long {
        var result = 0L
        var i = index + 1
        while (i > 0) {
            result += bit[i]
            result %= MODL
            i -= lowbit(i)
        }
        return result
    }

    fun query(left: Int, right: Int): Long {
        return query(right) - (if (left == 0) 0L else query(left - 1))
    }

    fun update(index: Int, x: Long) {
        val value = query(index) - query(index - 1)
        add(index, x - value)
    }

    fun add(index: Int, x: Long) {
        var i = index + 1
        while (i < bit.size) {
            bit[i] += x
            i += lowbit(i)
        }
    }

    override fun toString(): String {
        return LongArray(bit.size - 1) { query(it) - query(it - 1) }.toList().toString()
    }

    private fun lowbit(x: Int): Int {
        return x.and(-x)
    }
}

// 所有函数的下标从 0 开始
// query(index): max[0, index]
// udpate(index, x): 更新 [0, index] 之间的最大值，只能越来越大
class BinaryIndexedTreeMax {

    private val bit: IntArray

    constructor(n: Int) {
        this.bit = IntArray(n + 1)
    }

    fun query(index: Int): Int {
        var result = 0
        var i = index + 1
        while (i > 0) {
            result = Math.max(result, bit[i])
            i -= lowbit(i)
        }
        return result
    }

    fun update(index: Int, x: Int) {
        var i = index + 1
        while (i < bit.size) {
            bit[i] = Math.max(bit[i], x)
            i += lowbit(i)
        }
    }

    private fun lowbit(x: Int): Int {
        return x.and(-x)
    }
}

class SparseTableMax(private val nums: IntArray) {

    private val st: Array<IntArray>

    init {
        val n = nums.size
        val logN = Integer.numberOfTrailingZeros(Integer.highestOneBit(n))
        this.st = Array(logN + 1) { IntArray(n) }
        for (i in 0 until n) {
            st[0][i] = nums[i]
        }
        for (i in 1 until logN + 1) {
            for (j in 0 until n - 1.shl(i - 1)) {
                st[i][j] = Math.max(st[i - 1][j], st[i - 1][j + 1.shl(i - 1)])
            }
        }
    }

    fun query(left: Int, right: Int): Int {
        if (left > right) {
            return -1
        }
        val len = right - left + 1
        val k = Integer.numberOfTrailingZeros(Integer.highestOneBit(len))
        return Math.max(st[k][left], st[k][right - 1.shl(k) + 1])
    }
}

class SparseTableMin(private val nums: IntArray) {

    private val st: Array<IntArray>

    init {
        val n = nums.size
        val logN = Integer.numberOfTrailingZeros(Integer.highestOneBit(n))
        this.st = Array(logN + 1) { IntArray(n)  { Int.MAX_VALUE / 2 } }
        for (i in 0 until n) {
            st[0][i] = nums[i]
        }
        for (i in 1 until logN + 1) {
            for (j in 0 until n - 1.shl(i - 1)) {
                st[i][j] = Math.min(st[i - 1][j], st[i - 1][j + 1.shl(i - 1)])
            }
        }
    }

    fun query(left: Int, right: Int): Int {
        if (left > right) {
            return -1
        }
        val len = right - left + 1
        val k = Integer.numberOfTrailingZeros(Integer.highestOneBit(len))
        return Math.min(st[k][left], st[k][right - 1.shl(k) + 1])
    }
}

class PrefixSum2D(private val grid: Array<IntArray>) {

    private val prefix: Array<IntArray>

    init {
        val (m, n) = Pair(grid.size, grid[0].size)
        prefix = Array(m + 1) { IntArray(n + 1) }
        for (i in 0 until m) {
            var row = 0
            for (j in 0 until n) {
                row += grid[i][j]
                prefix[i + 1][j + 1] = prefix[i][j + 1] + row
            }
        }
    }

    fun query(up: Int, left: Int, bottom: Int, right: Int): Int {
        return prefix[up][left] + prefix[bottom + 1][right + 1] -
            prefix[bottom + 1][left] - prefix[up][right + 1]
    }
}

private class Counter<T>(nums: List<T> = emptyList()) {

    val numToCount = mutableMapOf<T, Int>()

    val size: Int
        get() = numToCount.size

    var sum: Int = 0
        private set

    init {
        nums.forEach { add(it) }
    }

    fun add(num: T, count: Int = 1): Int {
        val added = numToCount.getOrDefault(num, 0) + count
        numToCount[num] = added
        sum += count
        return added
    }

    fun remove(num: T, count: Int = 1) {
        val lastCount = numToCount.getOrDefault(num, 0)
        if (lastCount == count) {
            numToCount.remove(num)
        } else {
            numToCount[num] = lastCount - count
        }
        sum -= count
    }

    fun get(num: T): Int {
        return numToCount.getOrDefault(num, 0)
    }
}

// ----------------------------------------------------------------------------

typealias Graph = Array<MutableList<Int>>

private fun edgesToGraph(n: Int, edges: Array<List<Int>>, directed: Boolean = false): Graph {
    val graph = Array(n) { mutableListOf<Int>() }
    for ((a, b) in edges) {
        graph[a].add(b)
        if (!directed) {
            graph[b].add(a)
        }
    }
    return graph
}

typealias GraphW = Array<MutableList<Long>>

private fun edgesToGraphW(n: Int, edges: Array<List<Int>>, directed: Boolean = false): GraphW {
    val graph = Array(n) { mutableListOf<Long>() }
    for ((u, v, w) in edges) {
        graph[u].add(makePoint(v, w))
        if (!directed) {
            graph[v].add(makePoint(u, w))
        }
    }
    return graph
}

private fun readGraph(n: Int, m: Int, directed: Boolean = false): Graph {
    val graph = Array(n) { mutableListOf<Int>() }
    repeat(m) {
        val a = readInt() - 1
        val b = readInt() - 1
        graph[a].add(b)
        if (!directed) {
            graph[b].add(a)
        }
    }
    return graph
}

fun makePoint(x: Int, y: Int) = (x.toLong() shl 32) or y.toLong()
fun makePointS(x: Int, y: Int) = (x.min(y).toLong() shl 32) or y.max(x).toLong()
fun Long.x() = (this shr 32).toInt()
fun Long.y() = this.toInt()
operator fun Long.component1() = (this shr 32).toInt()
operator fun Long.component2() = this.toInt()

private fun PrintWriter.printNums(nums: List<Int>) {
    if (nums.isEmpty()) {
        println()
        return
    }
    for (i in 0 until nums.size - 1) {
        print(nums[i])
        print(' ')
    }
    println(nums.last())
}

private fun genPrefix(nums: LongArray): LongArray {
    val n = nums.size
    val prefix = LongArray(n + 1)
    for (i in 0 until n) {
        prefix[i + 1] = prefix[i] + nums[i]
    }
    return prefix
}

private fun uniqList(nums: List<Int>): List<Int> {
    val n = nums.size
    val uniq = mutableListOf(nums[0])
    for (i in 1 until n) {
        if (nums[i] != nums[i - 1]) {
            uniq.add(nums[i])
        }
    }
    return uniq
}

private fun lengthOfLIS(numsInput: List<Int>): Int {
    val nums = unify(numsInput)
    val bit = BinaryIndexedTreeMax(nums.size + 1)
    var result = 0
    for (num in nums) {
        val len = bit.query(num - 1) + 1
        bit.update(num, len)
        result = Math.max(result, len)
    }
    return result
}

private fun unify(nums: List<Int>): List<Int> {
    val numToIndex = nums.sorted().mapIndexed { index, num -> num to index }.toMap()
    return nums.map { numToIndex[it]!! }
}

private fun fastPow(a: Long, exp: Long, mod: Long = MODL): Long {
    var result = 1L % mod
    var base = a % mod
    var remain = exp
    while (remain != 0L) {
        if (remain % 2L == 1L) {
            result = (result * base) % mod
        }
        base = (base * base) % mod
        remain /= 2L
    }
    return result
}

private fun inv(a: Long, mod: Long = MODL): Long {
    return fastPow(a, mod - 2L, mod)
}

private tailrec fun gcd(a: Int, b: Int): Int {
    return if (b == 0) a else gcd(b, a % b)
}

private tailrec fun gcdL(a: Long, b: Long): Long {
    return if (b == 0L) a else gcdL(b, a % b)
}

private fun lcm(a: Int, b: Int): Int {
    return a / gcd(a, b) * b
}

private fun lcmL(a: Long, b: Long): Long {
    return a / gcdL(a, b) * b
}

private fun wordToCharCount(word: String): IntArray {
    val charCount = IntArray(26)
    for (char in word) {
        charCount[char.toIndex()]++
    }
    return charCount
}

private fun Int.max(target: Int) = this.coerceAtLeast(target)
private fun Long.max(target: Long) = this.coerceAtLeast(target)
private fun Float.max(target: Float) = this.coerceAtLeast(target)
private fun Double.max(target: Double) = this.coerceAtLeast(target)

private fun Int.min(target: Int) = this.coerceAtMost(target)
private fun Long.min(target: Long) = this.coerceAtMost(target)
private fun Float.min(target: Float) = this.coerceAtMost(target)
private fun Double.min(target: Double) = this.coerceAtMost(target)

private fun Char.toIndex(): Int {
    return this.toInt() - 'a'.toInt()
}

private fun Char.toDigit(): Int {
    return this.toInt() - '0'.toInt()
}

private fun Int.isBit(i: Int): Boolean {
    return this.and(1.shl(i)) != 0
}

private fun Int.setBit(i: Int): Int {
    return this.or(1.shl(i))
}

private fun Int.getBit(i: Int): Int {
    return this.and(1.shl(i))
}

private fun Int.clearBit(i: Int): Int {
    return this.and(1.shl(i).inv())
}

private fun Int.revertBit(i: Int): Int {
    return this.xor(1.shl(i))
}

private fun Int.countOneBits(): Int {
    return Integer.bitCount(this)
}

private fun Int.highestOneBit(): Int {
    return Integer.highestOneBit(this)
}

private fun Long.modSum(other: Long, mod: Long = MODL): Long {
    val a = ((this % mod) + mod) % mod
    val b = ((other % mod) + mod) % mod
    return (a + b) % mod
}

private fun Long.modMul(other: Long, mod: Long = MODL): Long {
    val a = ((this % mod) + mod) % mod
    val b = ((other % mod) + mod) % mod
    return (a * b) % mod
}

private fun Int.modSum(other: Int, mod: Int = MOD): Int {
    val a = ((this % mod) + mod) % mod
    val b = ((other % mod) + mod) % mod
    return (a + b) % mod
}

private fun Int.modMul(other: Int, mod: Int = MOD): Int {
    val a = ((this % mod) + mod) % mod
    val b = ((other % mod) + mod) % mod
    return (a * b) % mod
}

private fun Boolean.toYesNo(upper: Boolean = false): String {
    val yesNo = if (this) "Yes" else "No"
    return if (upper) yesNo.toUpperCase() else yesNo
}

private fun Double.isZero(): Boolean {
    return abs(this) <= EPS
}

private fun Float.isZero(): Boolean {
    return abs(this) <= EPS
}

private fun LongArray.modSum(mod: Long = MODL): Long {
    var sum = 0L
    for (num in this) {
        sum = sum.modSum(num, mod)
    }
    return sum
}

private fun LongArray.modMul(mod: Long = MODL): Long {
    var mul = 1L
    for (num in this) {
        mul = mul.modMul(num, mod)
    }
    return mul
}

private fun IntArray.swap(i: Int, j: Int) {
    val temp = this[i]
    this[i] = this[j]
    this[j] = temp
}

private fun LongArray.swap(i: Int, j: Int) {
    val temp = this[i]
    this[i] = this[j]
    this[j] = temp
}

private fun CharArray.swap(i: Int, j: Int) {
    val temp = this[i]
    this[i] = this[j]
    this[j] = temp
}

private fun <T> List<T>.toArrayDeque(): ArrayDeque<T> {
    return ArrayDeque(this)
}

private fun <T> List<T>.toPair(): Pair<T, T> {
    return Pair(this[0], this[1])
}

private fun <T> List<T>.listEquals(other: List<T>): Boolean {
    return this.size == other.size && (0 until this.size).all { this[it] == other[it] }
}

private fun <T: Comparable<T>> List<T>.compareTo(other: List<T>): Int {
    val n = Math.min(this.size, other.size)
    for (i in 0 until n) {
        val c = this[i].compareTo(other[i])
        if (c != 0) {
            return c
        }
    }
    return when {
        this.size < other.size -> -1
        this.size > other.size -> 1
        else -> 0
    }
}

private fun <T : Comparable<T>> List<T>.isSorted(): Boolean {
    val n = this.size
    return (0 until n - 1).all { this[it] <= this[it + 1] }
}

private fun <T : Comparable<T>> Collection<T>.findMin(): T {
    var result = this.first()
    for (num in this) {
        result = if (result.compareTo(num) < 0) result else num
    }
    return result
}

private fun <T : Comparable<T>> Collection<T>.findMax(): T {
    var result = this.first()
    for (num in this) {
        result = if (result.compareTo(num) > 0) result else num
    }
    return result
}

private fun <T, E : Comparable<E>> Collection<T>.minBy(converter: (T) -> E): T {
    var minEle = this.first()
    var minValue = converter(this.first())
    for (ele in this) {
        val value = converter(ele)
        if (value.compareTo(minValue) < 0) {
            minValue = value
            minEle = ele
        }
    }
    return minEle
}

private fun <T, E : Comparable<E>> Collection<T>.maxBy(converter: (T) -> E): T {
    var maxEle = this.first()
    var maxValue = converter(this.first())
    for (ele in this) {
        val value = converter(ele)
        if (value.compareTo(maxValue) > 0) {
            maxValue = value
            maxEle = ele
        }
    }
    return maxEle
}

private val DIR = listOf(
    listOf(0, 1), listOf(1, 0), listOf(0, -1), listOf(-1, 0)
)

private const val MOD3 = 998244353
private const val MOD7 = 1000000007
private const val MOD9 = 1000000009
private const val MOD = MOD7
private const val MODL = MOD.toLong()
private const val EPS = 0.000001
private const val maxValue = Int.MAX_VALUE / 2
private const val maxValueL = Long.MAX_VALUE / 2L

// ----------------------------------------------------------------------------

fun main() {
    val go: Runnable = Runnable {
        writer.solve()
        writer.flush()
    }
    Thread(null, go, "thread", 1L.shl(28)).start()
    // writer.solve()
    // writer.flush()
}

private fun PrintWriter.solve() {
    val (n, l) = readInts()
    val nums = readLongArray(n)
    println(partyLemonade(l, nums))
}

private fun partyLemonade(l: Int, nums1: LongArray): Long {
    val n = 31
    val nums = LongArray(n) { nums1.getOrNull(it) ?: maxValueL }
    for (i in 1 until n) {
        nums[i] = nums[i].min(nums[i - 1] * 2)
    }
    var result = maxValueL
    var sum = 0L
    for (i in n - 1 downTo 0) {
        if (l.isBit(i)) {
            sum += nums[i]
            continue
        }
        result = result.min(sum + nums[i])
    }
    return min(result, sum)
}
