class Solution {
public:
    int myAtoi(string s) {
        //double INT_MAX = pow(2, 31) - 1, INT_MIN = pow(2, 31) * -1;
        long long num = 0, i = 0;
        while(s[i] == ' ') //If its a leading white space 
        {
            i++; //then skip it
        }

        int sign = 1; //by default it is positive
        switch(s[i])
        {
            case '-':
                sign = -1;
                i++;
                break;

            case '+': //sign doesnt need changing
                i++;
                break;
            default: 
        }

        while(isdigit(s[i]) && s[i] == '0') //is s[i] a char digit and is it a leading zero? If yes then skip it
        {
            i++;
        }

        while(isdigit(s[i]))
        {
            num *= 10;
            num += s[i] - 48; //0 has an ascii code of 48
            cout << num;

            if(sign * num >= INT_MAX)
            {
                return INT_MAX; // Round to Int Max
            }
            else if (sign * num <= INT_MIN)
            {
                 return INT_MIN; //Round to Int min
            }
            i++;
        }
        return sign * num;
    }
};