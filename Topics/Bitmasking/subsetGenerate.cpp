#include<bits/stdc++.h>

using namespace std;


int main(){
	ios::sync_with_stdio(false);

	char ch[] = {'A', 'B', 'C', 'D'};
	int n = 4;
	int tot = 1<<n;

	for(int i = 0; i<tot; i++){

		for(int j = 0; j<n; j++){
			int bit = 1<<j;

			if(bit & i){
				 cout<<ch[j]<<" ";
			}
		}
		cout<<endl;
	}
	



	return 0;
}