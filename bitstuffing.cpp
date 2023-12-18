#include<stdio.h>
#include<string.h>
int main()
{
	char data[50],stuff[50],dstuff[50];
	int i,j,cnt,len;
	
	printf("Enter the Data(in '0' and '1' form):");
	scanf("%s",data);
	
	len=strlen(data);
	cnt=0;
	j=0;
	
	for(i=0;i<len;i++)
	{
		if(data[i]=='1')
		{
			cnt++;
		}
		else
		{
			cnt=0;
		}
		stuff[j]=data[i];
		j++;
		
		if(cnt==5 && data[i+1]=='1')
		{
			stuff[j]='0';
			j++;
			cnt=0;
		}
	}
	stuff[j]='\0';
	printf("Stuffed data with flag byte(01111110):\n 01111110 %s 01111110 \n",stuff);
	
	
//Destuffing:

	len=strlen(stuff);
	cnt=0;
	j=0;
	
	for(i=0;i<len;i++)
	{
		if(stuff[i]=='1')
		{
			cnt++;
		}
		else
		{
			cnt=0;
		}
		dstuff[j]=stuff[i];
		j++;
		
		if(cnt==5 && stuff[i+1]=='0')
		{
			cnt=0;
			i++;	
		}
	}
	dstuff[j]='\0';
	printf("\nDestuffed data is: %s",dstuff);	
	
	
	return 0;
}



//*output:
//Enter the Data(in '0' and '1' form):111111


