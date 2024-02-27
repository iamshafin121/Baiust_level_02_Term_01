#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class BloomTree {
public:
    enum BloomLevel {
        Remembering,
        Understanding,
        Applying,
        Analyzing,
        Evaluating,
        Creating
    };

    BloomTree() {
        addNode(Remembering, {"define", "list", "recall", "repeat", "select", "state"});
        addNode(Understanding, {"classify", "describe", "discuss", "explain", "identify", "locate", "recognize"});
        addNode(Applying, {"calculate", "complete", "demonstrate", "illustrate", "interpret", "operate"});
        addNode(Analyzing, {"analyze", "categorize", "compare", "contrast", "differentiate", "organize"});
        addNode(Evaluating, {"appraise", "critique", "justify", "recommend", "revise","summarize"});
        addNode(Creating, {"compose", "construct", "design", "develop", "formulate", "organize"});
    }

    void addNode(BloomLevel level, const vector<string>& keywords) {
        BloomNode node(level, keywords);
        nodes[level] = node;
    }

    BloomLevel determineLevel(const string& question) const {
        for (const auto& pair : nodes) {
            const auto& keywords = pair.second.getKeywords();
            for (const auto& keyword : keywords) {
                if (question.find(keyword) != string::npos) {
                    return pair.first;
                }
            }
        }
        return Remembering;
    }
private:
    class BloomNode {
    public:
        BloomNode() {}
        BloomNode(BloomLevel level, const vector<string>& keywords) : level(level), keywords(keywords) {}

        BloomLevel getLevel() const {
            return level;
        }

        const vector<string>& getKeywords() const {
            return keywords;
        }

    private:
        BloomLevel level;
        vector<string> keywords;
    };

    unordered_map<BloomLevel, BloomNode> nodes;
};// Overloading << operator for BloomLevel enum

ostream& operator<<(ostream& os, BloomTree::BloomLevel level) {
    switch (level) {
        case BloomTree::Remembering: return os << "Remembering";
        case BloomTree::Understanding: return os << "Understanding";
        case BloomTree::Applying: return os << "Applying";
        case BloomTree::Analyzing: return os << "Analyzing";
        case BloomTree::Evaluating: return os << "Evaluating";
        case BloomTree::Creating: return os << "Creating";
        default: return os << "Unknown";
    }
}

int main() {
    BloomTree tree;

    string word = "Analyze";
    cout << "Word: " << word << endl;
    cout << "Level: " << tree.determineLevel(word) << endl;

    string question = "What are the main components of photosynthesis?";
    cout << "Question: " << question << endl;
    cout << "Level: " << tree.determineLevel(question) << endl;

  return 0;
}