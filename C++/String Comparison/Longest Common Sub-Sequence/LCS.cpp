#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=0;

    cin >> n; 
    int arr[n+1][n+1];
    string str1 = "", str2 = "";

    memset(arr, 0, sizeof(arr)); 

    //Ingresar valores
        cin >> str1 >> str2;
        // cout << str2[0] << endl;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(str1[i-1] == str2[j-1]){
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else{
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            cout << arr[i][j] << "   ";
        }
        cout << endl;
    }

    cout << arr[n][n] << endl;
    
    return 0;
}