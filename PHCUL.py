# -*- coding: utf-8 -*-
"""

@author: Manish
"""
import math

def eucdist(x1,y1,x2,y2):
    return math.sqrt(math.pow(x2-x1,2)+math.pow(y2-y1,2))

if __name__=="__main__":
    for _ in range(int(input())):
        x,y=map(int,input().split())
        N,M,K=map(int,input().split())
        Ndata=list(map(int,input().split()))
        Mdata=list(map(int,input().split()))
        Kdata=list(map(int,input().split()))
        
        mNearestDict={}
        for i in range (0,2*M,2):
            x1,y1=Mdata[i],Mdata[i+1]
            for j in range(0,2*K,2):
                x2,y2=Kdata[j],Kdata[j+1]
                if j==0:
                    mindis=eucdist(x1,y1,x2,y2)
                else:
                    mindis=min(mindis,eucdist(x1,y1,x2,y2))
            mNearestDict[str((x1,y1))]=mindis
        
        nNearestDict={}
        for i in range (0,2*N,2):
            x1,y1=Ndata[i],Ndata[i+1]
            for j in range(0,2*M,2):
                x2,y2=Mdata[j],Mdata[j+1]
                if j==0:
                    mindis=eucdist(x1,y1,x2,y2)+mNearestDict[str((x2,y2))]
                else:
                    mindis=min(mindis,eucdist(x1,y1,x2,y2)+mNearestDict[str((x2,y2))])
            nNearestDict[str((x1,y1))]=mindis
            
        shareChatNearestDict={}
        x1,y1=x,y
        for i in range (0,2*N,2):
            x2,y2=Ndata[i],Ndata[i+1]
            if i==0:
                mindis=eucdist(x1,y1,x2,y2)+nNearestDict[str((x2,y2))]
            else:
                mindis=min(mindis,eucdist(x1,y1,x2,y2)+nNearestDict[str((x2,y2))])
            shareChatNearestDict[str((x2,y2))]=mindis
        
#        print(shareChatNearestDict)
#        print(nNearestDict)
#        print(mNearestDict)
        resl1=shareChatNearestDict.values()
#        print(min(resl1))
        
        #swap of layers
        nNearestDict={}
        for i in range (0,2*N,2):
            x1,y1=Ndata[i],Ndata[i+1]
            for j in range(0,2*K,2):
                x2,y2=Kdata[j],Kdata[j+1]
                if j==0:
                    mindis=eucdist(x1,y1,x2,y2)
                else:
                    mindis=min(mindis,eucdist(x1,y1,x2,y2))
            nNearestDict[str((x1,y1))]=mindis

        
        mNearestDict={}
        for i in range (0,2*M,2):
            x1,y1=Mdata[i],Mdata[i+1]
            for j in range(0,2*N,2):
                x2,y2=Ndata[j],Ndata[j+1]
                if j==0:
                    mindis=eucdist(x1,y1,x2,y2)+nNearestDict[str((x2,y2))]
                else:
                    mindis=min(mindis,eucdist(x1,y1,x2,y2)+nNearestDict[str((x2,y2))])
            mNearestDict[str((x1,y1))]=mindis
        
                    
        shareChatNearestDict={}
        x1,y1=x,y
        for i in range (0,2*M,2):
            x2,y2=Mdata[i],Mdata[i+1]
            if i==0:
                mindis=eucdist(x1,y1,x2,y2)+mNearestDict[str((x2,y2))]
            else:
                mindis=min(mindis,eucdist(x1,y1,x2,y2)+mNearestDict[str((x2,y2))])
            shareChatNearestDict[str((x2,y2))]=mindis
        
        resl2=shareChatNearestDict.values()
        print(min(min(resl1),min(resl2)))