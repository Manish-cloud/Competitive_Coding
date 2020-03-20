# -*- coding: utf-8 -*-
"""
Created on Fri Mar 20 12:11:40 2020

@author: Manish
"""

def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a) 

def lcm(a,b): 
    return (a*b) / gcd(a,b)

def gcdAndLcm(func):
    
    print("Enter numbers(In line separated by space)")
    numbers = list(map(int,input().split()))
    
    res = func(numbers[0],numbers[1])
    if len(numbers)>2:
        for i in range(2,len(numbers)):
            res = func(res,numbers[i])
    print(int(res))
    
if __name__=="__main__":
    while(True):
        choice = int(input("Menu:\n1]LCM\n2]GCD/HCF\n3]Exit\nEnter Choice :: "))
        if choice == 1:
            gcdAndLcm(lcm)
        
        elif choice == 2:
            gcdAndLcm(gcd)
            
        elif choice == 3:
            break
        
        else:
            print("Wrong choice Entered")