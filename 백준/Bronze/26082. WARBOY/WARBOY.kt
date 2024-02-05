fun main()
{
    val (a,b,c) = readln().split(" ").map{it.toInt()}
    val ga :Int=b/a
    print(ga*3*c)
}