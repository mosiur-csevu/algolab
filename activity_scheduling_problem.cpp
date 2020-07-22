#include <bits/stdc++.h>
using namespace std;

int main()
{
    multimap<int, int, greater <int> > value;
    map<int,int>::iterator it;

    int n;
    cin >> n;
    int wait[n],temp;

    int isBooked[n] = {0},maximumTime=INT_MIN;
    int total=0;

    for(int i=0; i<n; i++)
    {
        cin >> temp >> wait[i];
        if(wait[i]>maximumTime)
            maximumTime = wait[i];
        value.insert(make_pair(temp,i));
    }

    for(it=value.begin(); it != value.end(); it++)
    {
        if(maximumTime==0) break;

        int currentValue = it->first;
        int currentJob = it->second;
        int currentWait = wait[currentJob];

        cout << "val: " << currentValue << "  job: " << currentJob << " wait: " << currentWait << endl;

        while(currentWait)
        {
            if(isBooked[currentWait]==0)
            {
                isBooked[currentWait] = 1;
                total += currentValue;
                cout << currentValue << endl;
                maximumTime--;
                break;

            }
            else
            {
                currentWait--;
            }
        }
    }

    cout << total << endl;


    return 0;
}
/*

7
12 1
5 2
20 2
15 3
35 3
25 4
30 4

*/
