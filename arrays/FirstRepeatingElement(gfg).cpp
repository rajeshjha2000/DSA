//{ Driver Code Starts
// Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// } Driver Code Ends
// User function Template for C

int firstRepeated(int *arr, int n) {
    // declared unordered map
    unordered_map<int,int>hash;
    
     // step 01 = traverse array and store it's element as hashing
     
     for (int i=0; i<n; i++){
         hash[arr[i]]++;
     }
     
     // step 02 = traverse array to check each element if it has occurence in future
     
     for(int i=0; i<n; i++){
         if(hash[arr[i]]>1){
             return i+1;
         }
     }
     return -1;
}


//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int *arr;
        arr = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        printf("%d\n", firstRepeated(arr, n));
    }
    return 0;
}
// } Driver Code Ends