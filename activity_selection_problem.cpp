#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int start[n], temp;
    multimap<int,int>finish;
    map<int,int>::iterator it;

    for(int i=0;i<n;i++) {
        cin >> start[i] >> temp;
        finish.insert(make_pair(temp,i));
    }

    int currentTime=0,activityCount=0, activityList[n];
    int i=0;
    for(it=finish.begin();it!=finish.end();it++)
    {

        int currentFinishTime = it->first;
        int currentActivity = it->second;
        cout << "item: " << currentActivity << " - " << "fin: " << currentFinishTime << endl;
        if(start[currentActivity]>currentTime) {
            currentTime = currentFinishTime;
            activityCount++;
            activityList[i++] = currentActivity;
        }
    }


    cout << activityCount << endl;

    for(int i=0;i<activityCount;i++)
        cout << activityList[i] << endl;

    return 0;
}
