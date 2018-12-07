/*
See for one single case.
We need to make as many sauces as possible using each material only once.
the array a holds the mask for each possible recipe.
We have to make dp using this array
in dp we check if a[submask] is there then we have option to take it or not.
if we take then mask becomes mask & (~submask) because we have to make bits of mask 0 which are 1 in submask.
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXM = (1 << 18);

int a[MAXM];
int dp[MAXM];
int n, m;

int solve(int mask){
	int &ret = dp[mask];
	if(ret != -1)return ret;
	ret = 0;
	for(int submask = mask; submask; submask = (submask - 1) & mask){
		if(a[submask]){
			ret = max(ret, 1 + solve(mask&(~submask)));
		}
	}
	return ret;
}

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); --> doesnt work on zoj since c++11 specific

	while(cin >> n >> m){
		memset(a, 0, sizeof(a));
		for(int i = 0; i < m; ++i){
			int k, t, tempmask = 0;
			cin >> k;
			for(int j = 0; j < k; ++j){
				cin >> t;
				tempmask = tempmask | (1 << (t - 1));
			}
			a[tempmask] = 1;
		}
		memset(dp, -1, sizeof(dp));
		int ans = solve((1<<n) - 1);
		cout << ans << endl;
	}

	return 0;
}
