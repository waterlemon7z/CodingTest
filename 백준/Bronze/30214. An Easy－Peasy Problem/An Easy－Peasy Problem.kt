fun main(args: Array<String>)
{
    val (a, b) = readln().split(" ").map{it.toInt()}
    if(a*2 >= b)
    {
        print("E")
    }
    else
        print("H")

}