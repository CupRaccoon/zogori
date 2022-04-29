// h.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"

#include<stdio.h>
#include<string.h>
int an,bn;
int ans[5010];
int f[60][5010];
char a[60],b[5010];
int anst;

void dp(int first)
{
	memset(f,0xff,sizeof(f));
	f[0][0]=0;
	for (int i=0; i<=an; i++)
	{
		for (int j=first; j<=bn; j++)
		{
			if (i==0 && j==first) continue;
			if (i && j!=first) f[i][j-first]=f[i-1][j-first-1]+1;
			if (i && j!=first && a[i-1]==b[j-1] && f[i-1][j-first-1]<f[i][j-first]) f[i][j-first]=f[i-1][j-first-1];
			if (i && (f[i-1][j-first]+1<f[i][j-first] || f[i][j-first]<0)) f[i][j-first]=f[i-1][j-first]+1;
			if (j!=first && (f[i][j-first-1]+1<f[i][j-first] || f[i][j-first]<0)) f[i][j-first]=f[i][j-first-1]+1;
			//if (f[i][j-first]>anst+3) break;
		}
	}
}

int check()
{
	int min=-1;
	for (int i=0; i<bn; i++)
		if (min<0 || f[an][i]<min) min=f[an][i];
	return min;
}

void work()
{
	an=strlen(a);
	bn=strlen(b);
	for (anst=0; anst<=an; anst++)
	{
		if (an>40 && anst>30) 
		{
			printf("%d\n",an);
			return;
		}
		memset(ans,0xff,sizeof(ans));
		for (int i=0; i<bn; i++)
		if (i==0 || ans[i-1]<=anst)
		{
			dp(i);
			for (int j=i; j<bn; j++)
			{
				int tmp=f[an][j-i+1];
				if (i && ans[i-1]>tmp) tmp=ans[i-1];
				if (tmp<ans[j] || ans[j]<0) ans[j]=tmp;
			}
			int k;
			if (i==0) 
			{
				k=check();
				if (k==an) 
				{
					printf("%d\n",an);
					return;
				}
				if (an>35 && k>an/2) 
				{
					printf("%d\n",k);
					return;
				}
			}
		}
		if (ans[bn-1]==anst) {
			printf("%d\n",ans[bn-1]);
			return;
		}
	}
}

int main()
{
	int t;
	//freopen("h.in","r",stdin);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s%s",a,b);
		work();
	}
	return 0;	
}
