#include <bits/stdc++.h>
using namespace std;



int main()
{
    int numberOfProducts;
    cin >> numberOfProducts;
    double bagWeight;
    cin >> bagWeight;

    double value[numberOfProducts], weight[numberOfProducts];
    map<double,double>bag;
    multimap<double, double, greater <double> > price;
    map<double,double>::iterator it;

    for(int i=0; i<numberOfProducts; i++)
    {
        cin >> value[i] >> weight[i];

        price.insert(make_pair(value[i]/weight[i],i));
    }

    double totalCost=0;

    for(it=price.begin(); it!=price.end(); it++)
    {
        if(bagWeight==0)
            break;

        double currentItemRatio = it->first;
        int currentItem = it->second;

        // cout << "item: " << currentItem << " - " << "v/w: " << currentItemRatio << endl;
        if(bagWeight >= weight[currentItem])
        {
            totalCost += value[currentItem];
            bag[currentItem] = value[currentItem];
            bagWeight -= weight[currentItem];
        }
        else
        {
            bag[currentItem] = value[currentItem]*(bagWeight*1.0/weight[currentItem]);
            totalCost += value[currentItem]*(bagWeight*1.0/weight[currentItem]);
            bagWeight = 0;
        }
    }

    printf("%lf\n",totalCost);
    /*
    for(it=bag.begin(); it!=bag.end(); it++)
    {
        cout << it->first << " - " << it->second << endl;
    }
*/
    return 0;
}
