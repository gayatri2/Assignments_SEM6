#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[4]={3,2,1,4};
    int n=4; int mmin;
    cout << "Before:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n-1; i++)
    {
        mmin=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[mmin])
            {
                mmin=j;
            }
        }
        swap(arr[mmin],arr[i]);
    }
    cout << "After:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}