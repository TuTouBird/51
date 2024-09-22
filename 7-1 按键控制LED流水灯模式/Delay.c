
void Delay(unsigned int num)		//@12.000MHz
{
	unsigned char i, j;
	while(num--){
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	}
}