// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <algorithm>
// #include <map>
// #include <vector>

// using namespace std;

// class BloomSearch {
//     private:
//         const string filename = "bloom.txt";
//         string searchString;
//         map<string, vector<string>> taxonomy;

//         string toLowerCase(const string& str) {
//             string lowerCaseStr = str;
//             transform(lowerCaseStr.begin(), lowerCaseStr.end(), lowerCaseStr.begin(), ::tolower);
//             return lowerCaseStr;
//         }

//     public:
//         BloomSearch(const string& searchString) : searchString(toLowerCase(searchString)) {
//             addContent();
//         }

//         void addContent() {
//             taxonomy["Remembering"] = {"Define", "Describe", "Identify", "Label", "List", "Match", "Name", "Outline", "Recall", "Recognize", "Reproduce", "State"};
//             taxonomy["Understanding"] = {"Classify", "Describe", "Discuss", "Explain", "Identify", "Locate", "Recognize", "Report", "Select", "Translate", "Paraphrase"};
//             taxonomy["Applying"] = {"Choose", "Demonstrate", "Dramatize", "Employ", "Illustrate", "Interpret", "Operate", "Schedule", "Sketch", "Solve", "Use", "Write"};
//             taxonomy["Analyzing"] = {"Appraise", "Compare", "Contrast", "Criticize", "Differentiate", "Discriminate", "Distinguish", "Examine", "Experiment", "Question", "Test"};
//             taxonomy["Evaluating"] = {"Appraise", "Argue", "Defend", "Judge", "Select", "Support", "Value", "Evaluate"};
//             taxonomy["Creating"] = {"Assemble", "Construct", "Create", "Design", "Develop", "Formulate", "Write"};
//         }

//         void findLevels() {
//             bool found = false;
//             istringstream iss(searchString);
//             for(string s; iss >> s; ) {
//                 if (s.length() > 3) {
//                     for (const auto& level : taxonomy) {
//                         if (find(level.second.begin(), level.second.end(), s) != level.second.end()) {
//                             cout << "The key-word '" << s << "' belongs to Level " << level.first << " of Bloom's Taxonomy" << endl;
//                             found = true;
//                         }
//                     }
//                 }
//             }

//             if (!found) {
//                 cout << "This does not belong to Bloom's Taxonomy" << endl;
//             }
//         }
// };

// int main() {
//     string searchString;
//     cout << "Enter a Key-Word or Question: ";
//     getline(cin, searchString);
//     BloomSearch bloomSearch(searchString);
//     bloomSearch.findLevels();
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

class Bloomsearch{
    private:
        string filename;
        string searchString;
        map<string, vector<string>> bloomsTaxonomy;

    public:
        // Function to convert the word to lower case
        string toLowerCase(string str){
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            return str;
        }

        Bloomsearch(string searchString){
            this->filename = "bloom.txt";
            this->searchString = toLowerCase(searchString);
            this->bloomsTaxonomy = {
                {"remembering", {"define", "descrribe", "identify", "label", "list", "match", "name", "outline", "recall", "recognize", "reproduce", "state"}},
                {"understanding", {"classify", "describe", "discuss", "explain", "identify", "locate", "recognize", "report", "select", "translate", "paraphrase"}},
                {"applying", {"choose", "demonstrate", "dramatize", "employ", "illustrate", "interpret", "operate", "schedule", "sketch", "solve", "use", "write"}},
                {"analyzing", {"appraise", "compare", "contrast", "criticize", "differentiate", "discriminate", "distinguish", "examine", "experiment", "question", "test"}},
                {"evaluating", {"appraise", "argue", "defend", "judge", "select", "support", "value", "evaluate"}},
                {"creating", {"assemble", "construct", "create", "design", "develop", "formulate", "write"}}
            };
        }

        void findLevels(){
            //Function to search user input against the bloom taxonomy
            istringstream iss(searchString);
            bool Found = false;
            for(string s; iss >> s; ) {
                // Exclude small words
                if (s.length() > 3) {
                    for(auto &level : bloomsTaxonomy) {
                        if(find(level.second.begin(), level.second.end(), s) != level.second.end()) {
                            cout << "The key-word '" << s << "' belongs to Level " << level.first << " of Bloom's Taxonomy" << endl;
                            Found = true;
                            break;
                        }
                    }
                }
            }

            // Check if any word was not found
            if (!Found) {
                cout << "This does not belong to Bloom's Taxonomy" << endl;
            }
        }
};

int main(){
    string searchString;
    cout << "Enter a Key-Word or Question: ";
    getline(cin, searchString);
    Bloomsearch obj(searchString);
    obj.findLevels();
    return 0;
}