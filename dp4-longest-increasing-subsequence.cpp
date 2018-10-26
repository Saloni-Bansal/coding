#include<bits/stdc++.h>

using namespace std;
int lis(int A[], int n) {
int l[n];
l[0]=1;

for(int i=1;i<n;i++)
    {   l[i]=1;
        for(int j=0;j<i;j++)
      {
          if(A[i]>A[j] && l[i]<l[j]+1)
          l[i]=l[j]+1;
      }//for loop
    }
      return *max_element(l,l+n);
}

int main()
{
  int A[]={7, 7, 1, 9, 9, 5};
  int n=sizeof(A)/sizeof(int);
  cout<<lis(A,n);
return 0;
}
