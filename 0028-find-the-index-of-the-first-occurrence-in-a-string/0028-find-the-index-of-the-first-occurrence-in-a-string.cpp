class Solution {
public:

    vector<int> computeLPS(string pat) {

        int n = pat.size();
        vector<int> lps(n, 0);

        int i=1;
        int j=0;

        while (i<n) {

            if (pat[i] == pat[j]) {
                j++;
                lps[i] = j;
                i++;
            }
            else {

                if (j != 0) {
                    j = lps[j-1];
                }
                else {
                    lps[i]=0;
                    i++;
                }

            }
        }

        return lps;
    }

    int strStr(string haystack, string needle) {

        if (needle.empty()) return 0;

        vector<int> lps = computeLPS(needle);

        int i = 0; // haystack pointer
        int j = 0; // needle pointer

        while (i < haystack.size()) {

            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needle.size()) {
                return i - j;
            }

            else if (i < haystack.size() && haystack[i] != needle[j]) {

                if (j != 0) {
                    j = lps[j-1];
                }
                else {
                    i++;
                }

            }
        }

        return -1;
    }
};