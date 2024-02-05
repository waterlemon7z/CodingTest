fun main()
{
    val str = readln()
    for (it in str)
    {
        if(!(it == '0' || it=='1' || it == ' '))
        {
            print("F")
            return
        }
    }
    print("S")
}