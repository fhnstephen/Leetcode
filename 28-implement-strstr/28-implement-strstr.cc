class Solution {
public:
    int strStr(char *haystack, char *needle) {
        char* result = strstr(haystack, needle);
        return result ? result - haystack : -1;
    }
};
