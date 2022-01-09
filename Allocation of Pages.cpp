class Solution 
{
    public:
    //Function to find minimum number of pages.
    //Allocate minimum no of pages
    //Algorithm
    /*
    1.Since our answer lies in a range, it is a binary search question
    2.lo=max(arr),since minimum one book needs to be allocated
    3.hi=sum(arr),since maximum no of pages a student can get is sum of all pages
    4.cal mid:which reprsents the maximum no of pages
    5.Try whether with this mid is ti possible to allocate books
    6.if not possible decrement hi,otherwise store the res and increment lo
    7.return res
    8.base case:if(n<m)return -1
    // Isvalid Function
    1.keep a counter for no. of students
    2.keep a resultant sum
    3.keep adding the element
    4.if sum exceeds the mid value,increase the counter and reassign the current element to sum
    5.check if counter>M,return false
    6.return true
    T.C:O(log(n))
    S.C:O(1)
    */
    
    bool isValid(int A[],int N,int M,int mid)
    {
        int students=1;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum>mid)
            {
                students++;
                sum=A[i];
            }
            
            if(students>M)
            {
                return false;
            }
        }
        
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        int lo=INT_MIN;
        int res=-1;
        int hi=0;
        for(int i=0;i<N;i++)
        {
        if(lo<A[i])
        {
            lo=A[i];
        }
        hi+=A[i];
        }
        
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(isValid(A,N,M,mid))
            {
                res=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        return res;
        
    }
};