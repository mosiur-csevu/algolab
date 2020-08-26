#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 20000001

int MinStep[M];

int MST1(ll num)
{
    if(MinStep[num]!=-1)
        return MinStep[num];
    if(num==1)
        return 0;

    int x=INT_MAX,y=INT_MAX,z=INT_MAX;

    x = MST1(num-1)+1;

    if(num%2==0)
        y = MST1(num/2)+1;
    if(num%3==0)
        z = MST1(num/3)+1;

    return MinStep[num] = min(min(x,y),z);
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
