class Solution
{
  public:
  
 bool isPossibleSol(int arr[],int n,int k,int mid){
     int cases = 1;
     long long timeSum=0;
     
     for(int i=0; i<n; i++){
         if(timeSum + arr[i]<=mid){
             timeSum += arr[i];
         }
         else{
             cases++;
             if(cases>k || arr[i]>mid){
                 return false;
         }
         
         //reset timeSum
         timeSum = arr[i];
     }
      return true ;
 }

 
    long long minTime(int arr[], int n, int k)
    {
       long long start = 0;
       long long end = 0;
       
       for(int i=0; i<n; i++){
           end += arr[i];
       }
       
       long long ans = -1;
       long long mid = start + (end - start)/2;
       while(start<=end){
           if(isPossibleSol(arr, n, k, mid)){
               ans = mid;
               end = mid - 1;
           }
           else{
               start = mid + 1;
               }
              mid = start + (end - start)/2; 
       }
       return ans;
    }
};