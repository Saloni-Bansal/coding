/*Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
Insert
Remove
Replace
All of the above operations are of equal cost.*/

#include<bits/stdc++.h>
using namespace std;

int edit_distance(string A, string B) {

int n=A.length();
int m=B.length();

int d[n+1][m+1];

for(int i=0;i<n+1;i++)
for(int j=0;j<m+1;j++)
{
    if(i==0) // if first string is null , then j delete operations
    d[i][j]=j;
    else if(j==0) //if second string is null, then i delete operations
    d[i][j]=i;

    else if(A[i-1]==B[j-1]) //if characters match then no increase in distance
    d[i][j]=d[i-1][j-1];
    else
    //if the strings differ at these characters, then increase edit distance
    d[i][j]=1 + min( d[i-1][j], min(d[i][j-1], d[i-1][j-1]) );
    //d[i-1][j]-> delete
    //d[i][j-1]-> insert
    //d[i-1][j-1]-> replace
}

return d[n][m]; //return the result
}
//the driver program
int main()
{

	string str1 = "SaloniBansal";
	string str2 = "BansalSaloni";

	cout << edit_distance(str1, str2);

	return 0;
}
