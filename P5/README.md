# Problem

We have decided to create a rhyming dictionary.  Use a similar idea to the above to sort words based on a rhyming scheme (up to you how to do it).

# Solution

I copied the tree class from last problem and created a method called `ends_with` which searches for words in the dictionary that ends with a specific pattern. 

Let's consider the following dictionary:

```
jack
black
back
green
blue
```

If I wanted to search for words ending with `ack` I would get the following list of words

```
jack
black
back
```

The way I've done the search for these words is similar to how I printed the words.
I go over every character, if the character is the end of a word, then I check if the word ends with the pattern (in the print method, I would just print the word). If the word does end with the pattern, then add it to the list, otherwise, just continue searching for more words.

Here's the code

```cpp
        vector<std::string> _ends_with(std::string prefix, std::string pattern, t_node * root){
            // keep across recursive calls
            static vector<std::string> retvec;
            if(root->is_word){
                // check if word ends with pattern
                if(prefix.length() >= pattern.length() && 
                        std::equal(prefix.begin() + (prefix.size()-pattern.size()),prefix.end(),pattern.begin()))
                {
                    retvec.push_back(prefix);
                }
            }
            // for every letter 
            // check if it has any subtree
            // if it does, that means the letter leads to a word, 
            // then add it to the prefix and call _ends_with recursively
            for(int i=0; i<26; ++i){
                if(root->children[i] != nullptr){
                    std::string new_prefix = prefix + (char) (97 + i);
                    _ends_with(new_prefix, pattern, root->children[i]);
                }
            }

            return retvec;
        }
```


Here's some sample output:

```
Words list: 
back
behind
black
blind
jack
kind
mind
track
unwind

Words ending with "ind"
behind
blind
kind
mind
unwind

Words ending with "ack"
back
black
jack
track 
```

