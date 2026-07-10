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