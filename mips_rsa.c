#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define ll long long int

ll check=0xffffffff;

ll modulo(ll base, ll exponent, ll mod) 
{
	ll x = 1;
	ll y = base;
	while(exponent > 0) 
	{
		if(exponent%2==1)
		{
			if((x*y)>check)printf("x*y is overflow\n");
			x=(x*y)%mod;
		}
		if((y*y)>check)printf("y*y is overflow\n");
		y=(y*y)%mod;
		exponent=exponent/2;
	}
	return x%mod;
}

int Fermat(ll p,int iterations) 
{
	int i;
	if(p==1) 
	{
		return 0;
	}
	for(i=0;i<iterations;i++) 
	{
		ll a=rand()%(p-1)+1;
		if(modulo(a,p-1,p)!= 1) 
		{
			return 0;
		}
	}
	return 1;
}

void main()
{
	for(int yeo=0;yeo<10000;yeo++)
	{
		ll p;
		ll i,j,e,d,n,kn;
		srand((unsigned int)time(0));
		do{
			p=rand()%1000;
		}while(p/100==0);

		for(i=p;i<1000;i++)
		{
			if(Fermat(i,50)==1)
			{
				break;
			}
		}

		do{
			p=rand()%1000;
		}while(p/100==0);

		for(j=p;j<1000;j++)
		{
			if(Fermat(j,50)==1)
			{
				break;
			}
		}
		n=i*j;
		kn=(i-1)*(j-1);
		do{
			p=rand()%100000;
		}while((p/10000)==0);

		for(e=p;e<100000;e++)
		{
			if(Fermat(e,50)==1)
			{
				break;
			}
		}

		ll a1,a2,b1,b2,c1,c2;
		a1=kn;
		a2=a1;
		b1=e;
		b2=1;

		while(b1!=1)
		{
			c1=a1%b1;
			c2=a2-(b2*(a1/b1));
			a1=b1;
			a2=b2;
			b1=c1;
			b2=c2;
		}

		while(b2<0)
			b2=kn+b2;
		if(b2>kn)
			b2=b2%kn;

		d=b2;
		long long int check;
		check=0xffffffff;
		if(i>check)printf("i overflow\n");
		if(j>check)printf("j overflow\n");
		if((i*j)>check)printf("p*q is overflow\n");
		if(((i-1)*(j-1))>check)printf("(p-1)*(q-1) is oveflow\n");
		if(e>check)printf("selected e is oveflow \n");
		if(d>check)printf("calculated d is overflow\n");
		//if(e*d>check)printf("e*d is overflow\n");
	}
	/*
	   ll c;
	   scanf("%lld",&c);
	   c=modulo(c,e,n);
	   printf("encrypted message : %lld\n", c);
	   p=modulo(c,d,n);
	   printf("decrypted message : %lld\n",p);*/
}

