class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mapA;
        unordered_map<char,int>mapB;

        for(char c: s){
            mapA[c]++;
        }
        for(char c : t){
            mapB[c]++;
        }
        return mapA == mapB;
    }
};