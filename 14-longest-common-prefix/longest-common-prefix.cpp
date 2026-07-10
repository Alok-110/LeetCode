class Solution {
public:

    class Trie {
    public:

        Trie* children[26];
        bool isEnd;

        Trie() {
            for(int i = 0; i<26; i++)
                children[i] = NULL;
            isEnd = false;
        }
        
        void insert(string word) {
            Trie* crawler = this;
            for(auto &c: word){
                if(crawler->children[c-'a'] == NULL)
                    crawler->children[c-'a'] = new Trie();
                crawler = crawler->children[c-'a'];
            }
            crawler->isEnd = true;
        }
        
        bool search(string word) {
            Trie* crawler = this;
            for(auto &c: word){
                int idx = c-'a';
                if(crawler->children[idx] == NULL) return false;
                crawler = crawler->children[idx];
            }
            return crawler->isEnd;
        }
        
        bool startsWith(string prefix) {
            Trie* crawler = this;
            for(auto &c: prefix){
                int idx = c-'a';
                if(crawler->children[idx] == NULL) return false;
                crawler = crawler->children[idx];
            }
            return true;
        }
    };

    string longestCommonPrefix(vector<string>& strs) {
        
        Trie* root = new Trie();
    
        for(auto &s: strs)
            root->insert(s);
        
        string prefix = "";
        Trie* crawler = root;

    while(true){
        int childCount = 0, childIdx = -1;
        for(int i = 0; i < 26; i++){
            if(crawler->children[i] != NULL){
                childCount++;
                childIdx = i;
            }
        }
        if(childCount != 1 || crawler->isEnd) break;
        prefix += (char)('a' + childIdx);
        crawler = crawler->children[childIdx];
    }
    return prefix;
    }
};