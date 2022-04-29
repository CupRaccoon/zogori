#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

typedef struct {
    int s;
    int e;
    int v;
}item;

int table[104];
int dp[10012][15013];
vector<item> items;

int main () {
    int m, n, a, b, c;
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        cin >> a;
        table[i] = a;
    }
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        item temp;
        temp.s = a;
        temp.e = b;
        temp.v = (b - a) * table[c - 1];
        items.push_back(temp);
    }
    struct {
        bool operator()(item q, item k) {
            return q.e < k.e;
        }
    } cmp;
    sort(items.begin(), items.end(), cmp);

    for(int i = 0; i < 10001; i++)
        for(int j = 0; j < 15000; j++)
            dp[i][j] = 0;

    for (int i = 1; i <= n; i++) {
        for(int j = 0; j < 15001; j++) {
            if(j >= items[i - 1].e) {
                if(dp[i - 1][j] > dp[i - 1][items[i - 1].s] + items[i - 1].v)
                    dp[i][j] = dp[i - 1][j];
                else {
                    dp[i][j] = dp[i - 1][items[i - 1].s] + items[i - 1].v;
                }
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
//    for(int i = 0; i <= items.size(); i++) {
//        for(int j = 0; j < 25; j++)
//            cout << dp[i][j] << " ";
//        cout << endl;
//
//    }
    cout << dp[n][15000];

    return 0;
}