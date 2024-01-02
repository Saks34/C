#include<stdio.h>
#include<string.h>
void main()
{	
	char a[900],b[900];
	char p[]="pyar jhootha hi jataya hi kyun,aise jana to aya hi kyun,aee sanam tu zara or sitam karde aa,";
	char s[]="aja be wajah se ye rista khatam karde aa, oo bedardya pyar bedardya";
	int i=0,j=0;
	while(p[i]!='\0')
	{
		a[i]=p[i];
		i++;
		j++;
	}
	i=0;
	while(s[i]!='\0')
	{
		a[j]=s[i];
		i++;
		j++;
	}
	a[j]='\0';
	printf("\n%s",a);
	int z=0;
	int y=strlen(a)-1;
	while(z<y)
	{
	b=a[z];
	a[z]=a[y];
	a[y]=b;
	z++;
	y--;	
	}
	printf("\n%s",a);
}


