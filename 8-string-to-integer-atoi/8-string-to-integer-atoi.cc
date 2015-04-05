class Solution {
public:
    int atoi(string str) {
        try {
            return stoi(str);
        }
        catch (invalid_argument e) {
            return 0;
        }
        catch (out_of_range e) {
            auto first = str.find_first_not_of(' ');
            if (str[first] == '-') return INT_MIN;
            return INT_MAX;
        }
    }
};
