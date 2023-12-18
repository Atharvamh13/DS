#include <stdio.h>  
#include <string.h>     
int main()  
{
	char data[50],stuff[50],dstuff[50];
	int i,j,fsize,noofframes,tframes,dsize,s;	
	printf("Enter Data:");
	scanf("%s",data);	
	dsize=strlen(data);	
	printf("Enter fsize:\n");
	scanf("%d",&fsize);
	s=fsize;	
	tframes=fsize-1;	
	noofframes=(dsize/tframes+1);	
	j=0;
	
	for(i=0;i<(dsize+noofframes);i++)
	{
		if(i%fsize==0)
		{
			if((dsize-j)<fsize)
			{
				fsize=dsize-j+1;
			}
			stuff[i]=(char)(48+fsize);
			fsize=s;
			}
			else
			{
stuff[i]=data[j];
				j++;
				}	
	}	stuff[dsize+noofframes]='\0';
	printf("stuffed data is: %s",stuff);
		
//Destuffing:
	j=0;
	for(i=0;i<(dsize+noofframes);i++)
	{
		if(i%fsize!=0)
		{
			dstuff[j]=stuff[i];
			j++;	
		}
	}
	printf("\nDestuffed data is:%s",dstuff);		
	return 0;
}

//OUTPUT:
//Enter Data:hello
//Enter fsize:
//3

