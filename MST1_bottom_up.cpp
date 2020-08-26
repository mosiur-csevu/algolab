#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 20000001

int MinStep[M];

int MST1(ll num)
{
    int x,y,z;
    x=y=z=INT_MAX;

    MinStep[1]=0;

    for(ll i=2; i<=num; i++)
    {
        x = MinStep[i-1]+1;

        if(num%2==0)
            y = MinStep[i/2]+1;

        if(num%3==0)
            z = MinStep[i/3]+1;

        MinStep[i] = min(min(x,y),z);

    }
    return MinStep[num];
}

int main()
{
    memset(MinStep,-1,sizeof(MinStep));
    int test;
    cin >> test;
    for(int t=1; t<=test; t++)
    {
        int n;
        cin >> n;
        cout << "Case " << t << ": " << MST1(n) << endl;
    }
    return 0;
}

