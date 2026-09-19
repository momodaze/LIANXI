void Delay100ms(unsigned char n)	//@11.0592MHz
{
	unsigned char data i, j, k;


	i = 5;
	j = 52;
	k = 195;
	while(n--){
		do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
	}
	
}
