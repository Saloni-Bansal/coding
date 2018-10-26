// C++ program for coin change problem.

#include<bits/stdc++.h>

using namespace std;

int count( int S[], int m, int n )
{   int include, exclude; //variables to store the number of ways
    int dp[n+1][m]={0}; // 2-D array to store the values from sub-problems

    for(int i=0;i<m;i++)  //initializing the number of ways for "0"
    dp[0][i]=1;

    for(int i=1;i<n+1;i++)  //loop for all values till "n"
        for(int j=0;j<m;j++) //loop for all given coins
    {
      include = (i-S[j]>=0)? dp[i-S[j]][j]  :0; //number of ways when coin "j" is included
      exclude=  (j>=1)     ? dp[i][j-1]     :0; // number of ways when coin "j" is not included
      dp[i][j]=include+exclude; //total number of ways
    }//for loop
    return dp[n][m-1];  // return the final answer
}

// Driver Code
int main()
{
	int arr[] = {1, 2, 10};  //coins available
	int m = sizeof(arr)/sizeof(arr[0]); //number of coins
	int n = 20; //Target number
	cout << count(arr, m, n); // Counting the total number of ways
	return 0;
}
