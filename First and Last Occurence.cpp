
vector<int> find(int arr[], int n , int x )
{
    // code here
    
    vector<int>res;
    
    //first occurence
    int indx1 = lower_bound(arr,arr+n,x)-arr;
    if(indx1!=n && arr[indx1]==x)res.push_back(indx1);
    else
    res.push_back(-1);
    
    //last occurence
    
    int indx2 = upper_bound(arr,arr+n,x)-arr;
    indx2--;
    
    if(indx2>=0 && arr[indx2]==x) res.push_back(indx2);
    else
    res.push_back(-1);

    return res;
}