/*
Let us first see when the robots first reach to the mining place
first robot will be made after M time and take S time to reach so M + S
second robot .. 2*M + S
so ith robot i*M + S
put all this in (min) priority queue
Why? because it is possible for the first robot to have multiple rounds before a later one is made
priority queue will make sure of that
number of trips is ceil(10000/c) which is (10000 + c - 1)/c
condition to be checked is if a robot is still working we will have to wait
for each robot W + 2*S is added so that it reaches the mining place again
and finally last trip doesnt need to have one jouney extra so we subtract s
Note: dont forget to clear queue in the beginning of each test case
*/
#include <bits/stdc++.h>
using namespace std;

long long int s, w, c, k, m;
priority_queue<long long int, vector<long long int>, greater<long long int> >pq;

int main(){

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while(cin >> s){

		while(!pq.empty())pq.pop();

		cin >> w >> c >> k >> m;
		long long int trips = (10000 + c - 1)/c;
		for(int i = 1; i <= k; ++i){
			pq.push(i*m + s);
		}

		long long int entry = -1;
		long long int leave = 0;

		long long int time = 0;

		while(trips--){
			if(entry == -1){
				entry = pq.top();
			}
			else{
				leave = entry + w;
				if(pq.top() >= leave)
					entry = pq.top();
				else
					entry = leave;
			}
			time = entry;
			pq.pop();
			time = time + w + 2*s;
			pq.push(time);
		}

		time = time - s;

		cout << time << endl;
		
	}	
}
