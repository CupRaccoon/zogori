#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

void main(){

	int i,j,k,t,hh1,mm1,ss1,hh2,mm2,ss2,n1,n2,res;
	char col,snum1,snum2;
	int c1,c2;

	cin>>t;
	while(t--)
	{
		cin >> hh1 >> col >> mm1 >> col >> ss1 >> hh2 >> col >> mm2 >> col >> ss2;
		
		n1=(hh1*60+mm1)*20+ss1/3;
		if((hh1*10000+mm1*100)%3==0 && (hh1*10000+mm1*100)!=0) n1++;
		//if((hh1*10000+mm1*100+ss1)%3==0) n1--;
		
		n2=(hh2*60+mm2)*20+ss2/3;
		if((hh2*10000+mm2*100)%3==0) n2++;
		if(hh1>hh2) n2+=28801;
		
		cout<<n1<<" "<<n2<<endl;
		cout<<n2-n1<<endl;
	}
}