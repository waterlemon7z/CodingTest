import kotlin.math.floor

fun main()
{
    var rst = 0
    val N = readln()
    val str:String = readln()
    for(i in str)
    {
        if(i in arrayOf('a','e','i','o','u'))
        {
            rst++
        }
    }
    println(rst)
}