fun main()
{
    val (a,b) =  readln().split(" ").map{it.toInt()}
    print((a-9)*60+b)
}