import profile
import sys
import random

def fun(n):
    print("runtime of n = ",n)
    ### generates random array of size n
    a = []
    for i in range(n):
        a.append(random.randint(-100,100))

    ### Do whatever to the generated array below
    

def main():
    random.seed 
    samples = 10 #number of samples
    increase_by = 50 #how much each sample increases in value
    for i in range(1,samples+1):
        n = increase_by*i
        profile.runctx('fun(n)',{},{'n':n,'fun':fun}) #creates function profiles, replace fun with function name

if __name__ == "__main__":
    main()

    
