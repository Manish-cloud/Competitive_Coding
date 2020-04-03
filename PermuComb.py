# -*- coding: utf-8 -*-
"""
Created on Sun Mar 22 23:28:05 2020

@author: Manish
"""
from itertools import permutations 
  
# Get all permutations of [1, 2, 3] 
perm = permutations([1,1,1,2,2]) 
  
# Print the obtained permutations 
for i in list(perm):
    print (i)