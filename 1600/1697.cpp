#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const function<int(int)> f[3] = {
	[](int n){ return n-1; },
	[](int n){ return n+1; },
	[](int n){ return n*2; }
};

int main(){
	int N, K, result = 0;
	scanf("%d %d", &N, &K);
	bool visited[100001] = {0};
	visited[N] = true;

	queue<int> Q;
	Q.push(N);
	for(int i=1; !visited[K]; i++){
		int qSize = Q.size();
		for(int j=0; j<qSize; j++){
			int curr = Q.front();
			Q.pop();
			for(int k=0; k<3; k++){
				int next = f[k](curr);
				if(next < 0 || next > 100000) continue;
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
		result = i;
	}
	printf("%d\n", result);
}