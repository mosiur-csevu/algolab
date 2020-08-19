#include <bits/stdc++.h>
using namespace std;


int max(int a,int b) {

return a>b?a:b;

}

int main()
{
    freopen("ksdp.txt","r",stdin);
    int bagSize,items;
    cin >> bagSize >> items;
    cout << "Bag Size :" << bagSize << endl;
    cout << "Number of Items :" << items << endl;

    int table[items+1][bagSize+1];
    memset(table,0,sizeof(table));

    int value[items],weight[items];

    for(int i=1; i<=items; i++)
    {
        cin >> value[i] >> weight[i];

        cout << "Item " << i << ": Value: " << value[i] << " & Weight: " << weight[i] << endl;
    }


    for(int i=1; i<=items; i++)
    {
        for(int j=1; j<=bagSize; j++)
        {
            if(weight[i]>j)
                table[i][j]=table[i-1][j];

            else
            {
                table[i][j] = max(value[i]+table[i-1][j-weight[i]], table[i-1][j]);
            }

        }
    }

    for(int i=0; i<=items; i++)
    {
        for(int j=0; j<=bagSize; j++)
        {
            cout << table[i][j] << " ";

        }
        cout << endl;
    }

    int j = bagSize;
    int i = items;

    while(table[i][j] !=0){
            if(table[i][j] != table[i-1][j]) {
                cout << "item " << i << " is taken. value :" << value[i] << " weight :" << weight[i] << endl;
                j -= weight[i];
            }
            i--;

        }



    return 0;
}
