unsigned char BCD_To_Dec(unsigned char bcd)
{
    return (bcd >> 4) * 10 + (bcd & 0x0F);
}

unsigned char Dec_To_BCD(unsigned char dec)
{
    return ((dec / 10) << 4) | (dec % 10);
}