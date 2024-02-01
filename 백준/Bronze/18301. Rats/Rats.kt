import kotlin.math.floor

fun main()
{
    val (n1, n2, n12) = readln().split(" ").map{ it.toDouble()}
    val floor = floor((n1 + 1) * (n2 + 1) / (n12 + 1) - 1)
    print(floor.toInt())
}