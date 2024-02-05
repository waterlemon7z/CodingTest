fun main()
{
    val str = readln()
    print(
        when(str)
        {
            "M" ->"MatKor"
            "W" ->"WiCys"
            "C"->"CyKor"
            "A"->"AlKor"
            "$"->"\$clear"
            else->""
        }
    )
}