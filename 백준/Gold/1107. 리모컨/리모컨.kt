import kotlin.math.abs
import kotlin.math.min

fun main() {
    val N = readln().toInt()
    val M = readln().toInt()
    val broken: MutableList<Boolean> = MutableList(10, { false })
    var flag = false;
    if (M >= 1) {
        val btn = readln().split(' ').map { it.toInt() }
        for (i in 0..M-1) {
            broken[btn[i]] = true
        }
    }
    var rst = abs(N - 100)
    for (i in 0..1000000) {
        val str = i.toString()
        flag = false
        for(it in str)
        {
            if(broken[it-'0'])
            {
                flag = true
                break
            }
        }
        if(flag == true)
            continue
        rst = min(rst, abs(N - i) + str.length)
    }
    println(rst)
}
