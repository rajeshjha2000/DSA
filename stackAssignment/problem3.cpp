// Problem 3: Celebrity problem[GFG]

#include <bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        // Step 1: Push all persons into the stack
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        // Step 2: Use the discard method to find a potential celebrity
        while(st.size() > 1){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            // Check if person 'a' knows person 'b'
            if(M[a][b]){
                // If 'a' knows 'b', 'a' cannot be the celebrity, push 'b' back
                st.push(b);
            } else {
                // If 'a' does not know 'b', 'b' cannot be the celebrity, push 'a' back
                st.push(a);
            }
        }
        
        // Step 3: Verify the potential celebrity
        int mightBeCelebrity = st.top();
        st.pop();
        
        // The celebrity should not know anyone else
        for(int i = 0; i < n; i++){
            if(M[mightBeCelebrity][i] != 0){
                return -1;
            }
        }
        
        // Everyone should know the celebrity
        for(int i = 0; i < n; i++){
            if(M[i][mightBeCelebrity] == 0 && i != mightBeCelebrity){
                return -1;
            }
        }
        
        // The potential celebrity is the actual celebrity
        return mightBeCelebrity;
    }

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t; // Number of test cases
    while(t--)
    {
        int n;
        cin >> n; // Number of people at the party
        vector<vector<int> > M(n, vector<int>(n, 0)); // Matrix to store the relationships
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> M[i][j]; // Input the relationship matrix
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl; // Output the result for each test case
    }
}


