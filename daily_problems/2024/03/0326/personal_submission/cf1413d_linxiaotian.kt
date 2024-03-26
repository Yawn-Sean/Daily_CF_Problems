private fun shurikens(lines: Array<String>): List<Int> {
    val n = lines.size / 2
    val posStack = ArrayDeque<Int>()
    var pos = 0
    val result = IntArray(n)
    for (line in lines) {
        if (line[0] == '+') {
            posStack.add(pos++)
        } else {
            val price = line.split(" ")[1].toInt()
            if (posStack.isEmpty()) {
                return emptyList()
            }
            result[posStack.removeLast()] = price
        }
    }
    return if (check(lines, result)) result.toList() else emptyList()
}
