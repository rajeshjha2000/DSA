class Solution 
{
    public:

    bool isPossible(int A[], int N, int M, int mid) {
        int studentCount = 1;
        int pageSum = 0;

        for (int i = 0; i < N; i++) {
            if (pageSum + A[i] <= mid) {
                pageSum = pageSum + A[i];
            } else {
                studentCount++;
                if (studentCount > M || A[i] > mid) {
                    return false;
                }
                pageSum = A[i];
            }
        }
        return true;
    }

    // Function to find minimum number of pages.
    int findPages(int A[], int N, int M) {
        if (M > N) {
            return -1;  // More students than books, impossible to allocate
        }

        int s = 0;
        int sum = 0;

        for (int i = 0; i < N; i++) {  
            sum = sum + A[i];
        }
        int e = sum;
        int ans = -1;  // Initialize ans variable
        int mid;

        while (s <= e) {
            mid = s + (e - s) / 2;

            if (isPossible(A, N, M, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};