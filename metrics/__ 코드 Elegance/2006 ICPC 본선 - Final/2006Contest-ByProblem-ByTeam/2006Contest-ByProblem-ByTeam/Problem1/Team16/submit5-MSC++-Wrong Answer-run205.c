#include <stdio.h>

int result[1000000];

main()
{
	int i, j, tcase, h1, m1, s1, h2, m2, s2, flag, nul;

	scanf("%d", &tcase);
	for(i=0;i<tcase;i++)
	{
		flag=0;
		scanf("%d%c%d%c%d %d%c%d%c%d", &h1, &nul, &m1, &nul, &s1, &h2, &nul, &m2, &nul, &s2);
		if(s2<s1)
		{
			m2=m2-1;
			s2=s2+60;
		}
		if(m2<m1)
		{
			h2=h2-1;
			m2=m2+60;
		}
		if(h2<h1)
			h2=h2+24;

		s2=s2-s1;
		m2=m2-m1;
		h2=h2-h1;

		result[i]=s2+m2*60+h2*3600+1;
		if(result[i]%3>=2)
			flag=1;
		result[i]=result[i]/3+flag;
	}

	for(i=0;i<tcase;i++)
	{
		printf("%d\n", result[i]);
	}
}