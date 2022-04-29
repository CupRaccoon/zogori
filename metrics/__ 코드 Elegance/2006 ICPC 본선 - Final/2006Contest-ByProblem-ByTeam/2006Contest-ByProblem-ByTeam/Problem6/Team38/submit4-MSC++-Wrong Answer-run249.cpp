#include <iostream>
using namespace std;

class Pair {
public :
	int GetInt(int x) { return a*x + b; }
	int a, b;
};



Pair set[20];
int  N,M;
int  answer ;
bool isEnd;


void rec(int np, int MSum, int preSum)
{
	if(isEnd == true)
		return;
	
	if(np == N-1 && MSum == M)
	{
		answer = preSum;
		return;
	}

	for(int i = 1; i <= M; ++i)
	{
		if(MSum+i <= M)
		{
			if(preSum == set[np+1].GetInt(i))
			{
				rec(np+1, MSum+i, preSum);
			}
		}
	}
}

int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i) {
		cin >> N;
		isEnd = false;

		//input
		for(int j = 0; j < N; ++j) 
			cin >> set[j].a >> set[j].b;

		cin >> M;

		answer = 0;

		for(int p = 1; p <=M; ++p)
		{
			if(isEnd == true)
			{
				break;
			}

			rec(0, p, set[0].GetInt(p));
		}

		cout << answer << endl;
	}

	return 0;
}

/*
void bt(int k, int preSum, int sum) {
	if ( answer ) return;
	if ( sum < 0 ) return;
	if ( sum == 0 ) {
		answer = preSum;
		return;
	}
	for(int i = 1; i <= sum-(N-k); ++i) {
		int cal = set[k].GetInt(i);
		cout << cal << endl;
		if ( k != 0 && cal != preSum ) continue;;
		bt(k+1, cal, sum-i);
	}
}


int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i) {
		cin >> N;

		for(int j = 0; j < N; ++j) 
			cin >> set[j].a >> set[j].b;

		cin >> M;

		answer = 0;

		bt(0,-1,M);

		cout << answer << endl;
	}

	return 0;
}
*/