#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[5]={4,5,3,1,2};
    int n=5;
    int mmin;
    cout << "unsorted:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    for(int i=0;i<n-1;i++)
    {
        mmin=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j] < a[mmin])
            {
                mmin=j;
            }
        }
        swap(a[mmin],a[i]);
    }
    
    cout << "sorted:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
 return 0;
}
