
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


