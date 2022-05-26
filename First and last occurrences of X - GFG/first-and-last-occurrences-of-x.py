#User function Template for python3
class Solution: 
    def firstAndLast(self, a, n, x): 
        # Code here
        for i in range(n):
            if a[i]==x:
             break
             
        for j in range(n-1,-1,-1):
            if a[j]==x:
             return i, j
             
        return [-1]

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input()) 
    for _ in range(t):
        n,x = [int(i) for i in input().split()] 
        arr = [int(i) for i in input().split()] 
        ob=Solution() 
        ans=ob.firstAndLast(arr,n,x) 
        s=(" ").join(map(str,ans))
        print(s)

# } Driver Code Ends