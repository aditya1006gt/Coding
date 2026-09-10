class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        vector<int>freq(256,0);
        vector<int>ind;
        vector<char>vowels_list;
        vector<int>first_occ(256,-1);
        for(int i=0;i<n;i++) {
            char c=s[i];
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                freq[c]++;
                ind.push_back(i);

                if (first_occ[c]==-1) {
                    first_occ[c]=i;
                }
                vowels_list.push_back(c);
            }
        }
        
        sort(vowels_list.begin(), vowels_list.end(), [&](char a, char b) {
            if (freq[a]!=freq[b]) {
                return freq[a]>freq[b];
            }
            return first_occ[a]<first_occ[b];
        });

        for(int i=0; i<ind.size();i++) {
            s[ind[i]]=vowels_list[i];
        }
        return s;
    }
};