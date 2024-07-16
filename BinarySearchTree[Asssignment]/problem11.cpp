// valid BST From Preorder[interviewBit]

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
void build(int &i, int min, int max, vector<int> &A) {
    // Agar array ke end tak pahunche, to return kar do
    if (i >= A.size()) {
        return;
    }
    
    // Agar current element min aur max ke beech mein hai
    if (A[i] > min && A[i] < max) {
        int rootData = A[i++]; // Current element ko rootData set karte hain
        build(i, min, rootData, A); // Left subtree build karte hain
        build(i, rootData, max, A); // Right subtree build karte hain
    }
}

int solve(vector<int> &A) {
    int min = INT_MIN, max = INT_MAX;
    int i = 0; // Array index ko track karne ke liye
    build(i, min, max, A); // BST build karne ka function call
    return i == A.size(); // Agar sabhi elements use ho gaye, to true return karte hain
}

/*
Time Complexity: O(N), jahan N array ka size hai.
                 Har element ko ek baar process karte hain.
Space Complexity: O(H), jahan H tree ki height hai.
                  Recursion stack ke liye space use hota hai.
*/
