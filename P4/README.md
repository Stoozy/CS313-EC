# Problem

We have decided to store words in a tree. As such: .Notice how we do this.  For the word "to", "tea" "ted" and "ten" - they all are storedstarting from "t" and then branching out, letter by letter.  This will help us look up wordsvia their spelling (like in a dictionary).  Create an algorithm to populate such a tree andsearch it.

# Solution

For this I've created a tree with 26 children representing the alphabet. I needed nodes for the tree so the structure looks like this:

```
struct t_node{
    t_node * children[26];
    bool is_word;
}
```
Note: the children are not characters, they are of type `t_node`. However, we can represent them as characters based on their position in the array (('a' + i), where i is the position in the array)

The boolean `is_word` value is used to check if the word end at the current node.

For example, A tree with the words `hi`,`eat`, and `and` may look like this
```

        [a] [] [] [e] [] [] [h] []...
         |         |         |
      ..[n]..     [a]..   ..[i] -> is_word = true
         |         |        
      ..[d]..   ..[t] -> is_word = true [] ...
         | 
         |-> is_word = true

```

Inserting words, for me, it made most sense to do it recursively. Where the base case would be when we reach the end of the word (aka word == '\0'). And then each call, if a node doesn't exist at the index (represented by word[i] - 'a'), create the `t_node` and then make the recursive call which inserts the rest of the word to the new `t_node` as root, and if a node already exists, continue with that `t_node` as root. 


For searching, I check every character in the search term if it's in the root. If not I return false, because for the entire word to exist, it must have the prefix characters in the tree (`hello` can't exists if `h` is not in the tree root). By the end of the iterations, the root should have `is_word` set to true and it should not be a `nullptr`. 

Then it's just a matter of using the tree data structure to `insert` and `search` words.

Here's the driver code:

```cpp
int main(){
    tree words_tree = tree();

    words_tree.insert("red");
    words_tree.insert("orange");
    words_tree.insert("yellow");
    words_tree.insert("green");
    words_tree.insert("blue");
    words_tree.insert("violet");

    cout << "list: " <<  endl;
    words_tree.print();
    cout << endl;

    std::string search_term;
    for(;;){
        cout << "Search:";
        cin >> search_term;
        if(words_tree.search(search_term))
            cout << search_term << " was found in the tree." << endl;
        else cout << search_term << " was not found in the tree." << endl;
    }
    return 0;
} 
```

Some sample output:

```
list: 
blue
green
orange
red
violet
yellow

Search:purple
purple was not found in the tree.
Search:green
green was found in the tree.
Search:orange
orange was found in the tree.
```
