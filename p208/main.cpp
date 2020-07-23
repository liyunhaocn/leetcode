#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

#define debug(x) cout<<#x<<": "<<(x)<<endl;

class Trie {
public:
    /** Initialize your data structure here. */

    struct node{
        char c;
        node* children[27] = {nullptr};
        node():c('0'){}
        node(char c):c(c){}
    };

    node * root;
    Trie() {
        root = new node('0');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        word+= "{";
        node * t = root;
        for(int i = 0;i < word.size();i ++){
            if(t->children[word[i] - 'a']== nullptr){
                t->children[word[i] - 'a'] = new node(word[i]);
            }
            t = t->children[word[i] - 'a'];
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        word+= "{";
        node * t = root;
        for(int i = 0;i < word.size();i ++){
            if(t->children[word[i] - 'a']== nullptr){
                return false;
            }
            if(t->children[word[i] - 'a']->c != word[i]){
                return false;
            }
            t = t->children[word[i] - 'a'];
        }
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        node * t = root;
        for(int i = 0;i < prefix.size();i ++){
            if(t->children[prefix[i] - 'a'] == nullptr){
                return false;
            }

            if(t->children[prefix[i] - 'a']->c != prefix[i]){
                return false;
            }
            t = t->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    Trie t;
    t.insert("apple");
    debug(t.search("apple"));
    debug(t.search("app"));
    debug(t.startsWith("app"));

    t.insert("app");
    debug(t.search("apple"));
    debug(t.search("app"));
    debug(t.startsWith("app"));
    return 0;
}
