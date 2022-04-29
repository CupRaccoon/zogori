#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plll;
ll N, M, x, y, ans=0, cnt=0;
vector<plll> arr;
ll cmpx(plll a, plll b){
    return a.first.first<b.first.first || ((a.first.first == b.first.first) && a.first.second<b.first.second);
}
ll cmpy(plll a, plll b){
    return a.first.second<b.first.second || ((a.first.second == b.first.second) && a.first.first<b.first.first);
}

int main()
{
    cin >> N;
    for (int i=0;i<N;i++){
        ll a, b;
        cin >> a >> b;
        arr.push_back({{a,b},1});
    }
    cin >> M;
    for (int i=0;i<M;i++){
        ll a, b;
        cin >> a >> b;
        arr.push_back({{a,b},-1});
    }
    cin >> x >> y;
    sort(arr.begin(),arr.end(),cmpx);
    for (int i=0;i<N+M;i++){
        if (arr[i].second==1)
            cnt+=x;
        else
            cnt-=y;
        if (cnt<0)
            cnt=0;
        ans=max(cnt,ans);
    }
    sort(arr.begin(),arr.end(),cmpy);
    cnt=0;
    for (int i=0;i<N+M;i++){
        if (arr[i].second==1)
            cnt+=x;
        else
            cnt-=y;
        if (cnt<0)
            cnt=0;
        ans=max(cnt,ans);
    }
    cout << ans;
    return 0;
}
