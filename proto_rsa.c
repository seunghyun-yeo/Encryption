#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define ll unsigned int

ll modulo(ll base, ll exponent, ll mod) 
{
	ll x = 1;
	ll y = base;
	while(exponent > 0) 
	{
		if(exponent%2==1)
			x=(x*y)%mod;
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
	ll p;
	ll i,j,e,d,n,kn;
	srand((unsigned int)time(0));
	do{
		p=rand()%10000;
	}while(p/1000==0);
	for(i=p;i<10000;i++)
	{
		if(Fermat(i,50)==1)
		{
			break;
		}
	}

	do{
		p=rand()%10000;
	}while(p/1000==0);

	for(j=p;j<10000;j++)
	{
		if(Fermat(j,50)==1)
		{
			break;
		}
	}
	n=i*j;
	kn=(i-1)*(j-1);
	do{
		p=rand()%10000;
	}while((p/1000)==0);

	for(e=p;e<10000;e++)
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
	printf("%d and %d is prime\n",i,j);
	printf("p*q is % d\n",n);
	printf("(p-1)*(q-1) is %d\n",kn);
	printf("selected e is %d\n",e);
	printf("calculated d is %d\n",d);
	printf("%d\n",(e*d)%kn);

	ll c;
	scanf("%d",&c);
	c=modulo(c,e,n);
	printf("encrypted message : %d\n", c);
	p=modulo(c,d,n);
	printf("decrypted message : %d\n",p);
}

