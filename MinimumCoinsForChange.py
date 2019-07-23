def change_dp(coins, value): 
    
    n = len(coins)
    
    # table[i] will be storing the minimum 
    #   number of coins required for value i 
    table = [0 for i in range(value + 1)]

    # ans[i] will be the coins array index of first coin
    #   you make change with at value i
    # we fill with -1 for non-existent values
    ans = [-1 for i in range(value + 1)]
    # Base case (If given value is 0)
    # Can't make change for 0 
    table[0] = 0
    
    # Initialize all table values as infinite
    for i in range(1, value + 1): 
        table[i] = sys.maxsize 


    # Compute minimum coins required 
    # for all values i from 1 to value
    sum = 0
    rem = 0
    for i in range(n):
        for j in range(1,len(table)):
            rem = (j)%coins[i]
            sum = int(j/coins[i])
            sum += table[rem]
            if sum < table[j]:
                table[j] = sum
                ans[j] = coins[i]
            sum = 0
    #print(table)
    # return minimum coins and the coins we used
    return table[value], ans
