class Solution(object):
    def myAtoi(self, s):
        INT_MAX = 2**31 - 1
        INT_MIN = -(2**31)
        i = 0
        n = len(s)

        #Step 1 is to check and skip for any leading white
        while i < n and s[i] == " ":
            i += 1
        
        #Step 2 is to check the signedness
        sign = 1 #a + by default
        if i < n and s[i] == "-":
            sign = -1
            i += 1
        elif i < n and s[i] == "+":
            sign = 1
            i += 1


        #step 3 is to check and skip for leading 0's
        while i < n and s[i] == "0":
            i += 1
    
        
        #Step 4 is the conversion
        res = 0 #result
        num = 0
        while i < n and s[i].isdigit():
            num = ord(s[i]) - 48 #converting ASCII to integer
            res = res * 10 + num
            if res * sign <= INT_MIN:
                return INT_MIN
            if res * sign >= INT_MAX:
                return INT_MAX
            i+=1
        return sign * res


        """
        :type s: str
        :rtype: int
        """
        