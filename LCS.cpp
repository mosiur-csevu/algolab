#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("LCS.txt","r",stdin);

    string a,b;
    cin >> a >> b;

    int row = b.size();
    int col = a.size();

    int table[row+1][col+1];
    memset(table,0,sizeof(table));

    for(int i=1,k=0; i<=row; i++,k++) {
        for(int j=1,n=0; j<=col; j++,n++) {
            if(a[n]==b[k]) {
                table[i][j] = table[i-1][j-1]+1;
            }

            else {
                table[i][j] = max(table[i-1][j],table[i][j-1]);
            }
        }
    }

    for(int i=0; i<=row; i++) {
        for(int j=0; j<=col; j++) {
                cout << table[i][j] << " ";
        }
        cout << endl;
    }

    cout << table[row][col] << endl;

    string sub;
    int i=0;

    while(table[row][col]!=0) {


        if(table[row][col] == table[row][col-1]) {
            col--;
        }

        else if(table[row][col] == table[row-1][col]) {
            row--;
        }

        else if(table[row][col] == table[row-1][col-1]+1) {
            sub.push_back(a[col-1]);
            col--;
            row--;
        }
    }

    reverse(sub.begin(), sub.end());
    cout << sub << endl;


    return 0;
}
