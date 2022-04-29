#include <iostream>
using namespace std;

int tube[20][2];
int n;

int main()
{
	int time;

	cin >> time;
	for(int t = 0; t < time; t++)
	{
		cin >> n;

		for(int i = 0; i < n; i++)
		{
			cin >> tube[i][0] >> tube[i][1] ;
		}
		int m ;

		cin >> m;
		int bcd = 2520;

		int ktotal = 0;

		for(int i = 0; i < n; i++)
		{
			ktotal += bcd / tube[i][0];
		}

		int sum = bcd * m;

		for(int i = 0; i < n; i++)
		{
			sum += tube[i][1] * (bcd / tube[i][0]); 
		}
		double result = static_cast<double>(sum) / ktotal  ;
		double cast_result = static_cast<double> (static_cast<int> (result)); 
		
		if(n == 0)
		{
			cout << 0 << endl;
		}
		else if (result == cast_result)
		{
			cout << static_cast<int>(result) << endl;
		}
		else 
		{	
			cout << 0 << endl;
		}

	}
	return 0;
}