long maximumSum(vector<long> a {
    long sum = 0,ans = 0;
    vector<int> sub;
    for(int i = 0; i< a.size(); i++){
        sum += a[i]; //add element to sum
        sub.push_back(a[i]);//add element to array
        if(sum < 0){ //if sum falls negative, reset array 
            sub.clear();
            sum = 0;
        }
        else if(sum > ans) //if sum is greater than current ans, update it
             ans = sum;
    }
    cout << "max array: ";
    for(int i = 0; i < sub.size(); i++)
        cout << sub[i] << " ";
    cout << endl;
    cout << "max sum = " << ans;
    return (ans);
}
