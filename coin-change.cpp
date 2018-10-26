// C++ program for coin change problem.
#include<bits/stdc++.h>

using namespace std;

int count( int S[], int m, int n )
{   int include, exclude;
    int dp[n+1][m]={0};
    for(int i=0;i<m;i++)
    dp[0][i]=1;

    for(int i=1;i<n+1;i++)
        for(int j=0;j<m;j++)
    {
      include = (i-S[j]>=0)? dp[i-S[j]][j]  :0;
      exclude=  (j>=1)     ? dp[i][j-1]     :0;
      dp[i][j]=include+exclude;
    }//for loop
    return dp[n][m-1];
}

// Driver Code
int main()
{
	int arr[] = {3, 5, 10};
	int m = sizeof(arr)/sizeof(arr[0]);
	int n = 20;
	cout << count(arr, m, n);
	return 0;
}

// This code is contributed
// by Akanksha Rai(Abby_akku)
