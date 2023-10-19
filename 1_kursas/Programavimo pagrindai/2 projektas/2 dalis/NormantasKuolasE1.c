unsigned char hexToChar (int digit, char type)
{
    char number[9]={'1','2','3','4','5','6','7','8','9'};
    char upper[6]={'A','B','C','D','E','F'};
    char lower[6]={'a','b','c','d','e','f'};

    if(digit>15)
        return 0;

    if(digit>=0 && digit<10)
        return number[digit-1];

    if(type>-1)
        return upper[digit-10];

    else
        return lower[digit-10];
}
