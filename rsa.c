#include<stdio.h>
#include<math.h>
#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <arpa/inet.h>



int findp();
int findq();
unsigned int findd();
double mod(double,double);
double mpow(double m,int e,int n)
{
	double temp;
	for(int i=0; i<e;i++)
	{
		temp=mod(m,n);
		m=temp*m;
	}
	return temp;
}

void main()
{
	int p=3;
	int q=5;
	double n=p*q;
//	p=findp();
//	q=findq();
	double m=12;
// e for encryption, d for decryption	
	int e=3;
	unsigned int d=4;//findd(e,p,q);
	printf("%d\n",d);
// encrypt message
	double c1 = mpow(m,e,n);
	printf("%d\n",c1);
// decrypt message
	double dm= mpow(c1,d,n);
	printf("%d\n",dm);
}

unsigned int findd(int e, int p, int q)
{
	int nk=(p-1)*(q-1)+1;
	int temp[2][2];
	int tmul;
	int temp1,temp2;
	memset(&temp,0,sizeof(temp));
	temp[0][0]=nk;
	temp[0][1]=nk;
	temp[1][0]=e;
	temp[1][1]=1;
	while(temp[1][0]!=1)
	{
		tmul=temp[0][0]/temp[1][0];
		
		temp1=temp[1][0];
		temp2=temp[1][1];
		
		temp[1][0]=temp[1][0]*tmul;
		temp[1][1]=temp[1][1]*tmul;
		
		temp[1][0]=temp[0][0]-temp[1][0];
		temp[1][1]=temp[0][1]-temp[1][1];
		
		temp[0][0]=temp1;
		temp[0][1]=temp2;
	}
	while(temp[1][1]<0)
	{
		temp[1][1]=temp[1][1]+nk;
	}
	if(temp[1][1]>nk)
		return temp[1][1]%nk;
	else
		return temp[1][1];
}

double mod(double m,double d)
{
	while(m>d)
	{
		m=m-d;
	}
	return m+d;
}
