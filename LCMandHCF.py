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

if __name__=="__main__":
    while(True):
        choice = int(input("Menu:\n1]LCM\n2]GCD/HCF\n3]Exit\nEnter Choice :: "))
        if choice == 1:
            
            print("Enter numbers(In line separated by space)")
            numbers = list(map(int,input().split()))
            
            res = lcm(numbers[0],numbers[1])
            
            if len(numbers)>2:
                for i in range(2,len(numbers)):
                    res = lcm(res,numbers[i])
            print(int(res))
            
        elif choice == 2:
            
            print("Enter numbers(In line separated by space)")
            numbers = list(map(int,input().split()))
            
            res = gcd(numbers[0],numbers[1])
            
            if len(numbers)>2:
                for i in range(2,len(numbers)):
                    res = gcd(res,numbers[i])
            print(res)
            
        elif choice == 3:
            break
        
        else:
            print("Wrong choice Entered")
