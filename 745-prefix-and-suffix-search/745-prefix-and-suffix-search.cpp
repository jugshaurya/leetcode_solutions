class Trie{
private:
	struct Node{
		vector<Node*> childs;
		int index;
		Node(): index(-1), childs(27, nullptr){};
		~Node(){
			for(auto node: childs){
				delete node;
			}
		}
	};
	Node* find(const string & s){
		Node* temp = root_.get();
		for(const char & c: s){
			if(!temp->childs[c - 'a']) return nullptr;
			temp = temp->childs[c - 'a'];
		}
		return temp;
	}
	unique_ptr<Node> root_;
public:
	Trie(): root_(new Node()){};
	void insert(const string & word, int index){
		Node* temp = root_.get();
		for(const char & c: word){
			if(!temp->childs[c - 'a']){
				temp->childs[c -'a'] = new Node();
			}
			temp = temp->childs[c - 'a'];
			temp->index = index;
		}
	}
	
	int startWith(const string & s){
		auto node = find(s);
		if(!node) return -1;
		return node->index;
	}
};
class WordFilter {
private:
	Trie trie_;
public:
	WordFilter(vector<string>& words) {
		int size = words.size();
		for(int i = 0; i < size; ++i){
			const string word = words[i];
			int len = word.length();
			for(int j = len; j >= 0; j--)
				trie_.insert(word.substr(j, len) + "{" + word, i);
		}
	}
	
	int f(string prefix, string suffix) {
		return trie_.startWith(suffix + "{" + prefix);
	}
};
/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */