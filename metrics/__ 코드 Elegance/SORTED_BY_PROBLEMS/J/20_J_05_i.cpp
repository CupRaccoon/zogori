#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int t = 1;
    int ans = 1e9;
    for(int i=0;n-t >= 2;i++,t*=2) {
        int a = n-t;
        int b = a - (a+1)/2 - 1;
        a = (a+1)/2 - 1;
        int cnt = 0;
        while(a) {
            a/=2;
            cnt++;
        }
        int cnt2 = 0;
        while(b) {
            b/=2;
            cnt2++;
        }
        ans = min(ans, max({cnt + i, cnt + cnt2, cnt2 + i}) );
    }
    printf("%d\n",ans);
    return 0;
}
