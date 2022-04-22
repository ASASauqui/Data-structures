#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1 = "", str2 = "";
    cin >> str1 >> str2;
    int n = str1.size(), m = str2.size();
    int arr[n+1][m+1];
    memset(arr, 0, sizeof(arr)); 

    for(int i=0,j=0;i<n+1;i++,j++){
        arr[i][0] = j;
    }
    for(int i=0,j=0;i<m+1;i++,j++){
        arr[0][i] = j;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1] == str2[j-1]){
                arr[i][j] = arr[i-1][j-1];
            }
            else{
                arr[i][j] = min(arr[i][j-1], min(arr[i-1][j], arr[i-1][j-1])) + 1;
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }

    cout << arr[n][m] << endl;
    
    return 0;
}