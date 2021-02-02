#include <iostream>
using namespace std;

int main(){
    int v, e, s, t, d;
    cin >> v >> e;
    int a[v][v], dp[1 << (v - 1)][v - 1];
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++) a[i][j] = 15001;
    }
    for(int i = 0; i < v - 1; i++){
        for(int j = 0; j < (1 << (v - 1)); j++) dp[j][i] = 15001;
    }
    for(int i = 0; i < e; i++){
        cin >> s >> t >> d;
        a[s][t] = d;
    }
    for(int i = 0; i < v - 1; i++) dp[(1 << i)][i] = a[v - 1][i];
    for(int i = 1; i < (1 << (v - 1)); i++){
        for(int j = 0; j < v - 1; j++){
            if(i & (1 << j)){
                for(int k = 0; k < (v - 1); k++){
                    if(k != j && (i & (1 << k))){
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + a[k][j]);
                    }
                }
            }
        }
    }
    s = 15001;
    for(int i = 0; i < v - 1; i++){
        s = min(s, dp[(1 << (v - 1)) - 1][i] + a[i][v - 1]);
    }
    if(s == 15001) cout << -1 << endl;
    else cout << s << endl;
}
