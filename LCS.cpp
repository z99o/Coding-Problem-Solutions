#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    //fill arrays
    string sizeA;
    string sizeB;
    cin >> sizeA;
    cin >> sizeB;
    int m = stoi(sizeA);
    int n = stoi(sizeB);
    vector<int> a;
    vector<int> b;
    string temp;
    for(int i = 0; i < m; i++){
        cin >> temp;
        a.push_back(stoi(temp));
    }
      
    for(int i = 0; i < n; i++){
        cin >> temp;
        b.push_back(stoi(temp));
    }

    //add to array size to account for i & j being 0 to avoid accessing out of array
    m++;
    n++;
    int c[m][n];
    //special case
    for(int i = 0; i < m; i++)
        c[i][0] = 0;
    for(int i = 0; i < n; i++)
        c[0][i] = 0;
    
    int longest = 0;
    vector<int> ans;
    for(int i = 1; i < m; i++){
        for(int j = 1;  j < n; j++){
            if(a[i-1] == b[j-1]){
                c[i][j] = c[i-1][j-1]+1; //if you dont add to the arrays this breaks
                if(c[i][j] > longest){
                   longest++; 
                   //ans.push_back(a[i]);
                   cout << a[i-1] << " ";
                }
                
            }
            else
                c[i][j] = max(c[i-1][j],c[i][j-1]);
                //if you dont add to the arrays this breaks as well
        }
    }
    /* dynamic programming array printout 
    cout << "max length: " << c[m-1][n-1] << endl;
    int size = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << c[i][j] << " "; 
        }
        cout << endl;
    }
    */
    
    return 0;
}

