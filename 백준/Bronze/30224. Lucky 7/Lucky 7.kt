fun main(args: Array<String>)
{
    val str: String = readln()
    val cur: Int = str.toInt()
    if (!str.contains("7"))
    {
        if(cur %7 != 0)
        {
            println(0)
        }
        else
        {
            println(1)
        }
    }
    else
    {
        if(cur %7 != 0)
        {
            println(2)
        }
        else
        {
            println(3)
        }
    }
}