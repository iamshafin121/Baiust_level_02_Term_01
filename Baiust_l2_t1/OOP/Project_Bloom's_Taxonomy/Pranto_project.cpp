#include<bits/stdc++.h>
using namespace std;

class Bloomsearch{
    private:
        string filename;
        string searchString;

    public:
        // Function to convert the word to lower case
        string toLowerCase(string str){
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            return str;
        }

        Bloomsearch(string searchString){
            this->filename = "bloom.txt";
            this->searchString = toLowerCase(searchString);
        }

        void addContent(){
            // Create the file and add the Blooms taxonomy library
            ofstream newFile(filename);
            newFile << "Remembering: Define, Descrribe, Identify, Label, List, Match, Name, Outline, Recall, Recognize, Reproduce, State.\n";
            newFile << "Understanding: Classify, Describe, Discuss, Explain, Identify, Locate, Recognize, Report, Select, Translate, Paraphrase.\n";
            newFile << "Applying: Choose, Demonstrate, Dramatize, Employ, Illustrate, Interpret, Operate, Schedule, Sketch, Solve, Use, Write.\n";
            newFile << "Analyzing: Appraise, Compare, Contrast, Criticize, Differentiate, Discriminate, Distinguish, Examine, Experiment, Question, Test.\n";
            newFile << "Evaluating: Appraise, Argue, Defend, Judge, Select, Support, Value, Evaluate.\n";
            newFile << "Creating: Assemble, Construct, Create, Design, Develop, Formulate, Write.\n";
            newFile.close();
        }

        void findLevels(){
            //Function to search user input against the bloom taxonomy file
            ifstream file(filename);
            string line;
            string level;

            bool Found = false;

            if (file.is_open()){
                while (getline(file, line)) {
                    // Convert the line to lower case before performing the comparison
                    string lowerCaseLine = toLowerCase(line);

                    if (lowerCaseLine.find("remembering") != string::npos) {
                        level = "Level 1: Remembering";
                    } 
                    else if (lowerCaseLine.find("understanding") != string::npos) {
                        level = "Level 2: Understanding";
                    } 
                    else if (lowerCaseLine.find("applying") != string::npos) {
                        level = "Level 3: Applying";
                    } 
                    else if (lowerCaseLine.find("analyzing") != string::npos) {
                        level = "Level 4: Analyzing";
                    } 
                    else if (lowerCaseLine.find("evaluating") != string::npos) {
                        level = "Level 5: Evaluating";
                    } 
                    else if (lowerCaseLine.find("creating") != string::npos) {
                        level = "Level 6: Creating";
                    }
                    istringstream iss(searchString);
                    for(string s; iss >> s; ) {
                        // Exclude singular letters
                        if (s.length() > 1) {
                            if (lowerCaseLine.find(s) != string::npos) {
                                cout << "The key-word '" << s << "' belongs to " << level << endl;
                                Found = true;
                            }
                        }
                    }
                }
                file.close();
            } 
            else{
                cout << "Unable to open file";
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
    obj.addContent();
    obj.findLevels();
    return 0;
}