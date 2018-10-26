/* Given a string, find out if the string is K-Palindrome or not.
A k-palindrome string transforms into a palindrome on removing
at most k characters from it.*/

#include<bits/stdc++.h>

using namespace std;
int edit_distance(string s, string r, int n)
{
  int dp[n+1][n+1];

      for(int i=0;i<n+1;i++)
      for(int j=0;j<n+1;j++)
      {
        if(i==0)
        dp[i][j]=j;
        else if(j==0)
        dp[i][j]=i;
        else if(s[i-1]==r[i-1]) //matching character, do nothing
        dp[i][j]=dp[i-1][j-1];
        else
        dp[i][j]=min(dp[i-1][j], dp[i][j-1]);  //insert or delete increase 1
      }//

      return dp[n][n];
}
bool k_pal(string s, int k)
{
  int n=s.length(); //length
  string r=s;
  reverse(r.begin(), r.end()); //create a reverse of string

  return edit_distance(s,r,n)<=k*2;  // total edit distance should be <=k*2
}//driver function for finding k-palindrome

//driver program
int main()
{
string s ="salonjxaznolas";
int k=2;
cout<<k_pal(s,k);
}
