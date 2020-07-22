#include <bits/stdc++.h>
using namespace std;

void binary_search(int a[],int n)
{
    int low = 0, high = 7;
    int mid;
    int notFound = 1;
    while(low<=high) {
        mid = (low+high)/2;
        if(a[mid]==n) {
            cout << "found in index: " << mid << endl;
            notFound = 0;
            break;
        }
        else if(a[mid]<n) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    if(notFound==1)
    cout << "Not found " << endl;
}


int main()
{
    int a[] = {1,2,3,4,7,6,7,8};
    int n=1;

    binary_search(a,n);
}
