#!/bin/python

import sys

def howManyCollisions(s):
    my_s = [i for i in s]
    col_cnt = 0
    right = False
    cnt = 0
    for i in range(len(s)):
        if s[i] == 'r':
           # print s[i]
            right = True
            cnt += 1
            #print cnt
        elif s[i] == 'l':
            if right:
                my_s[i] = 'd'
                #print my_s
                col_cnt += cnt + 1
                cnt = 0
                right = False
        elif s[i] == 'd':
            col_cnt += cnt
            cnt = 0
    cnt = 0

    n = len(my_s)-1
    #print 'DEBUG: n is: {}'.format(n)
    left = False
    while n >= 0:
        if my_s[n] == 'l':
            left = True
            cnt += 1
        elif my_s[n] == 'r':
            if left:
                my[n] = 'd'
                col_cnt += cnt +1
                cnt = 0
                left = False
        elif my_s[n] == 'd':
            col_cnt += cnt
        n -= 1
    return col_cnt        
            
            
    # Complete this function

q = int(raw_input().strip())
for a0 in xrange(q):
    s = raw_input().strip()
    # Returns the number of times moving robots collide.
    result = howManyCollisions(s)
    print(result)
