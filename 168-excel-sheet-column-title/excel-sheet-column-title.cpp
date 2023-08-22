class Solution {
public:
    long f(int i)
    {
        long num = 1;
        while(i > 0)
        {
            num *= 26;
            i--;
        }
        return num;
    }
    string convertToTitle(int columnNumber) {
        string ans;
        int i = 0;
        while(columnNumber > 0)
        {
            if((columnNumber % f(i + 1) != 0)){
                ans += ((columnNumber % f(i + 1)/f(i))+'A' - 1);
                cout<<ans<<endl;
            }else{
                ans += 'Z';
                cout<<ans<<endl;
                columnNumber -= f(i + 1);
            }
            columnNumber -= columnNumber % f(i + 1);
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        string ans ="";
        while(columnNumber > 0)
        {
            // find out the char what will be added to the ans String
            char addChar = 'A'+ (columnNumber - 1) %26;
            // adding char to the ans string
            ans = addChar + ans;
            // Update culumnNumber
            columnNumber = (columnNumber - 1) / 26;
        }
        return ans;
    }
};
*/