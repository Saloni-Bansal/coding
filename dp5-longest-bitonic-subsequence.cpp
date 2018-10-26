
/*
Given an array arr[0 … n-1] containing n positive integers,
a subsequence of arr[] is called Bitonic if it is first increasing,
 then decreasing. Write a function that takes an array as argument
 and returns the length of the longest bitonic subsequence.
*/

#include<bits/stdc++.h>

using namespace std;

int lbs(int A[], int n) { //longest_bitonic_subsequence
int l[n];

int d[n];
for(int i=0;i<n;i++)
{ l[i]=1;
  d[i]=1;}
//first find the longest increasing subsequence
for(int i=1;i<n;i++)
    {for(int j=0;j<i;j++)
        {
            if(A[i]>A[j]&& l[i]<l[j]+1)
            l[i]=l[j]+1;
        }//inner for
    }//outer for



//then find the longest decreasing subsequence
for(int i=n-2;i>=0;i--)
    {for(int j=n-1;j>i;j--)
        {
            if(A[i]>A[j]&& d[i]<d[j]+1)
            d[i]=d[j]+1;
        }//inner for
    }//outer for

//now l[i]+d[i] have size of longest increasing decreasing subsequence+1
// as "i" element is being counted twice, so decrease 1 and give out max answer
    int max=0;
    for(int i=0;i<n;i++)
    if(max<(l[i]+d[i]-1))
    max=l[i]+d[i]-1;

    return max;
}

//driver program
int main()
{
  int A[]={7,7,1,9,9,5};
  int n=sizeof(A)/sizeof(int);
  cout<<lbs(A,n);

  return 0;
}
