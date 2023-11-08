/*
Author: jubair7
Date: 21 Sep 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    int arr[11][11] = {0};
    for (int i = 1; i<=10; i++) {
        for (int j = 1; j<=10; j++) {
            if (i == 1 or i == 10) arr[i][j] = 1;
            else if (j == 1 or j == 10) arr[i][j] = 1;
        }
    }
    for (int i = 2; i<=9; i++) {
        for (int j = 2; j<=9; j++) {
            if (i == 2 or i == 9) arr[i][j] = 2;
            else if (j == 2 or j == 9) arr[i][j] = 2;
        }
    }
    for (int i = 3; i<=8; i++) {
        for (int j = 3; j<=8; j++) {
            if (i == 3 or i == 8) arr[i][j] = 3;
            else if (j == 3 or j == 8) arr[i][j] = 3;
        }
    }
    for (int i = 4; i<=7; i++) {
        for (int j = 4; j<=7; j++) {
            if (i == 4 or i == 7) arr[i][j] = 4;
            else if (j == 4 or j == 7) arr[i][j] = 4;
        }
    }
    for (int i = 5; i<=6; i++) {
        for (int j = 5; j<=6; j++) {
            if (i == 5 or i == 6) arr[i][j] = 5;
            else if (j == 5 or j == 6) arr[i][j] = 5;
        }
    }
    while(tt--){
        int sum = 0;
        for (int i = 1; i<=10; i++) {
            for (int j = 1; j<=10; j++) {
                char ch;
                cin >> ch;
                if (ch == 'X')
                    sum += arr[i][j];
            }
        }
        cout << sum << '\n';
    }
  return 0;
}