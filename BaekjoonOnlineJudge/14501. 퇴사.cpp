#include <iostream>
#include <algorithm>

using namespace std;

int D[16];
int T[16];
int P[16];
int n;
int ans;


void dfs(int day, int total) {
    if (day >= n + 1) 
    {
        ans = max(ans, total);
        return;
    }

    dfs(day + 1, total);
    if (day + T[day] <= n + 1)
        dfs(day + T[day], total + P[day]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> T[i] >> P[i];
    }
    
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
