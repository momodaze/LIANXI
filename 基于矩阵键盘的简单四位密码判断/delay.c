void Delay10ms(unsigned char n)	//@11.0592MHz
{
	unsigned char data i, j, k;
  while(n--){
	i = 144;
	j = 157;
	do
	{
		while (--j);
	} while (--i);
	}
}
