#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the unboundedKnapsack function below.
int unboundedKnapsack(int k, vector<int> arr) {
    int cur = 0;
    vector<int> ans;
    int c[k+1][arr.size()+1]; //add one to account for extra index
    //set 0 for end cases (item # = 0;)
    for(int i =0; i < k; i++)
        c[i][0] = 0;
    for(int i =0; i < arr.size(); i++)
        c[0][i] = 0;   
    //num items on top, item weight on size
    for(int i = 1; i < k+1; i++){
        for(int j = 0; j < arr.size(); j++){
            if(arr[j] <= i){ //if arr[j] less than current weight
                    //arr[j] can be part of sub solution
                    if(j > 0 && (arr[j] + c[i-1][j]) <= i ) //if sum less than prev
                        c[i][j] = arr[j] + c[i][j-1]; //set index to sum
                    else{ //if not greater, then keep previous
                        c[i][j] = c[i-1][j];
                    }
            }
            else{ //if not, value equals previous value
                c[i][j] = c[i-1][j];
            }
        }
    }
    cout << "  ";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << "|";
    cout << endl;
    for(int i = 1; i < k; i++){
        cout  << i << "|";
        for(int j = 0; j < arr.size(); j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = unboundedKnapsack(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
