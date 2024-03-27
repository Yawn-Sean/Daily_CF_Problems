private fun check(lines: Array<String>, nums: IntArray): Boolean {
    val n = nums.size
    var index = 0
    val queue = PriorityQueue<Int>()
    for (line in lines) {
        if (line[0] == '+') {
            queue.offer(nums[index++])
        } else {
            val price = line.split(" ")[1].toInt()
            if (queue.peek() != price) {
                return false
            }
            queue.poll()
        }
    }
    return true
}

private fun shurikens(lines: Array<String>): List<Int> {
    val n = lines.size / 2
    val posStack = ArrayDeque<Int>()
    var pos = 0
    val result = IntArray(n)
    for (line in lines) {
        if (line[0] == '+') {
            posStack.add(pos++)
        }
        else {
            val price = line.split(" ")[1].toInt()
            if (posStack.isEmpty()) {
                return emptyList()
            }
            result[posStack.removeLast()] = price
        }
    }
    return if (check(lines, result)) result.toList() else emptyList()
}
