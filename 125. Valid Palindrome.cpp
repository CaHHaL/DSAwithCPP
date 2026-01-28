class Solution
{
private:
public:
    bool isPalindrome(string s)
    {
        string temp;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                temp.push_back(s[i]);
            }
        }
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] >= 'A' && temp[i] <= 'Z')
            {
                temp[i] = temp[i] - 'A' + 'a';
            }
        }
        int j = temp.size() - 1;
        int i = 0;
        while (i <= j)
        {
            if (temp[i] != temp[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};