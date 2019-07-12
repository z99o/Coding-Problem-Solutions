import profile
import sys
import random

def fun(n,a):
    print("runtime of n = ",n)
    ### generates random array of size n

    ### Do whatever to the generated array below
    #kadane's algorithm below, but I don't have to do your work for you.
    #ans = -sys.maxsize-1
    #temp = 0
    #ans_a = []
    #temp_a = []
    #for i in range(n):
    #    temp += a[i]
    #    temp_a.append(a[i])
    #    if temp < 0:
    #        temp = 0
    #        temp_a.clear()
    #    if temp > ans:
    #        ans = temp
    #        ans_a = temp_a.copy()
    #print(ans)
    #print(ans_a)


def main():
    random.seed 
    samples = 9 #number of samples
    increase_by = 100 #100-900
    for i in range(1,samples+1):
        n = increase_by*i
        a = []
        for i in range(n):
            a.append(random.randint(-100,100))
        profile.runctx('fun(n,a)',{},{'n':n,'fun':fun,'a':a}) #creates function profiles, replace fun with function name
        a.clear()
    increase_by = 1000 # 1000-9000
    for i in range(1,samples+1):
        n = increase_by*i
        a = []
        for i in range(n):
            a.append(random.randint(-100,100))
        profile.runctx('fun(n,a)',{},{'n':n,'fun':fun,'a':a}) #creates function profiles, replace fun with function name
        a.clear()

if __name__ == "__main__":
    main()

    

