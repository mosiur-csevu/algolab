#include <bits/stdc++.h>
using namespace std;

int num[1234567], temp[1234567];

void mergesort(int low, int high)
{
    /// base condition
    if(low==high)
        return;
    /// determining mid
    int mid = (low+high)/2;

    /// left sub-problem
    mergesort(low,mid);
    /// right sub-problem
    mergesort(mid+1,high);

    for(int i = low, j = mid+1, k=low ; k<= high ; k++)
    {

        if(i==mid+1) {
            temp[k] = num[j++];
        }
        else if(j== high+1) {
            temp[k] = num[i++];
        }
        else if(num[i] < num[j]) {
            temp[k] = num[i++];
        }
        else {
            temp[k] = num[j++];
        }
    }

    for(int k=low; k<=high; k++) {
        num[k] = temp[k];
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
        cin>>num[i];

    mergesort(0,n-1);

    cout << num[n/2] << endl;

}
