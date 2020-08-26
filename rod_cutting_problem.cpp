#include <bits/stdc++.h>
using namespace std;



int main()
{
    freopen("rc.txt","r",stdin);
    int n;
    cin >> n;

    int val[n+1];

    for(int i=1;i<=n;i++) {
            cin >> val[i];
    }

    int table[n+1][n+1];
    memset(table,0,sizeof(table));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i<=j)
                table[i][j] = max(val[i]+table[i][j-i],table[i-1][j]);
            else
                table[i][j] = table[i-1][j];
        }
    }
    cout << endl << endl;

    for(int i=0;i <=n;i++) {
        cout.width(3);
        cout << i << " ";
    }

    cout << endl;

    for(int i=0;i<=n;i++) {
            cout.width(3);
            cout << val[i] << ": " << i << " - ";
        for(int j=0;j<=n;j++) {
                cout.width(3);
                cout << table[i][j] << " ";
        }
        cout << endl;
    }

    int i=n,j=n;

    while(table[i][j]!=0)
    {
        if(table[i][j] != table[i-1][j]) {
            j -= i;
            cout << "Cut : " << i << " - value: " << val[i] << endl;

        }
        else {
            i--;
        }
    }

    return 0;
}
