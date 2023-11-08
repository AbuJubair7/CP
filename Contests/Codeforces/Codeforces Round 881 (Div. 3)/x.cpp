
/*
Author: jubair7
Date: 21 June 2023
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

using namespace std;



void solve() {
    int n;
    cin >> n;

   vector<double> arr(n);

   for(int i = 0; i<n; i++) cin>>arr[i];
    
    sort(arr.begin(), arr.end());
    
    cout<<fixed<<setprecision(1);

    if(n <= 2) cout<<(arr[n-1] + arr[0])/2.0<<endl;
    else{
        double sum = (arr[n-1] + arr[0])/2.0;

        sum = min(sum, arr[1]);
        cout<<sum<<endl;
    }

 
}


int main(){
    BOOST;
    #ifdef jubs
        double start = clock();
    #endif

    solve();
        //cout<<"fsf";
    
    #ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
    return 0;
}

