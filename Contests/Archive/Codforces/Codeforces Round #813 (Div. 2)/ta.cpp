/*
Author: jubs
Date: 15 Aug 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

typedef long long ll;



/*........................start.............................*/



void solve(){
    int n;
    cin>>n;

    char arr[n][n];

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin>>arr[i][j]; 
            

    int correct = 1;

    int b = 0;
    int w = 0;
    int bCount = 0;
    int wCount = 0;
    // row check
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            if(arr[row][col] == 'W'){
                wCount++;
                w++;
                b = 0;
            }else{
                bCount++;
                b++;
                w = 0;
            }
            if(b == 3 || w == 3){
                correct = 0;
                break;
            }
        }
        if(bCount != wCount || !correct){
            correct = 0;
            break;
        }else{
            b = 0;
            w = 0;
            bCount = 0;
            wCount = 0;
        }
    }

    // col check
    if(correct){
        for(int col = 0; col<n; col++){
            for(int row = 0; row<n; row++){
              if(arr[row][col] == 'W'){
                    wCount++;
                    w++;
                    b = 0;
                }else{
                    bCount++;
                    b++;
                    w = 0;
                }
                if(b == 3 || w == 3){
                    correct = 0;
                    break;
                }
            }
            if(bCount != wCount || !correct){
                correct = 0;
                break;
            }else{
                b = 0;
                w = 0;
                bCount = 0;
                wCount = 0;
            }
        }

        if(correct) cout<<1<<endl;
        else cout<<0<<endl;
    }else cout<<0<<endl;
}

int main(){
    BOOST;
    solve();
    
    
    return 0;
}
