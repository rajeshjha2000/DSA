
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MIN;
        }
        
        // humne x length ka 1 segment cut kr liya baanki recursion dekh lega
        int option1 = 1 + maximizeTheCuts(n-x,x,y,z);
        
        // humne y length ka 1 segment cut kr liya baanki recursion dekh lega
        int option2 = 1 + maximizeTheCuts(n-y,x,y,z);
        
        // humne z length ka 1 segment cut kr liya baanki recursion dekh lega
        int option3 = 1 + maximizeTheCuts(n-z,x,y,z);
        
        int finalAns = max(option1, max(option2,option3));
        return finalAns;
    }
};

