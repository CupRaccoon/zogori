#include <bits/stdc++.h>
#define L long long

using namespace std;

bool chk[1111][55];
L a[1111][55];
L top[55];
L n;
L seq[55];//1->x?
L invseq[55];//x->1?

map<pair<L,L>,pair<L,L> >mp;

int main()
{
	scanf("%lld",&n);
	L i,j;
	for(i=1;i<=n;i++)
	{
		seq[i]=i;
		invseq[i]=i;
	}
	for(i=1;i<n;i++)
	{
		while(1)
		{
			L x;
			scanf("%lld",&x);
			if(x==0) break;
			a[x][i]=1;
		}
	}
	for(i=1;i<=1000;i++)
	{
		for(j=1;j<n;j++)
		{
			if(!a[i][j]) continue;
			//printf("%lld %lld ",i,j);
			L ba=invseq[j],bb=invseq[j+1];
			if(ba>bb) swap(ba,bb);
			//printf("babb %lld %lld\n",ba,bb);
			if(mp[make_pair(ba,bb)]!=make_pair(0ll,0ll))
			{
				//puts("1");
				//printf("%lld %lld\n",mp[make_pair(ba,bb)].first,mp[make_pair(ba,bb)].second);
				chk[mp[make_pair(ba,bb)].first][mp[make_pair(ba,bb)].second]=1;
				chk[i][j]=1;
				mp[make_pair(ba,bb)]=make_pair(0ll,0ll);
			}
			else
			{	
				//puts("0");
				mp[make_pair(ba,bb)]=make_pair(i,j);
			}
			swap(seq[ba],seq[bb]);
			swap(invseq[j],invseq[j+1]);
		}
	}
	vector<L>ans1,ans2;
	for(i=1;i<n;i++)
	{
		L cnt=0;
		for(j=1;j<=1000;j++)
		{
			if(a[j][i])
				cnt++;
			if(a[j][i]&&!chk[j][i])
			{
				ans1.push_back(i);
				ans2.push_back(cnt);
			}
		}
	}
	printf("%d\n",(int)ans1.size());
	for(i=0;i<ans1.size();i++)
	{
		printf("%lld %lld\n",ans1[i],ans2[i]);
	}
}
