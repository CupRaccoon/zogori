#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n-3 % 2 == 0)
    {
        cout << (n-3)/2<<endl;
    }
    else
    {
        cout << (n-2)/2 << endl;
    }

    return 0;
}
