fun main()
{
    val N = readln().toInt()
    val dict: Array<String> = arrayOf(
        "Never gonna give you up",
        "Never gonna let you down",
        "Never gonna run around and desert you",
        "Never gonna make you cry",
        "Never gonna say goodbye",
        "Never gonna tell a lie and hurt you",
        "Never gonna stop"
    )
    for (i in 1..N)
    {
        val str: String = readln()
        if(str !in dict)
        {
            print("Yes")
            return
        }
    }
    print("No")
}