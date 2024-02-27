#include <bits/stdc++.h>

using namespace std;

// Class to represent Bloom's Taxonomy
class BloomsTaxonomy {
private:
    fstream file;

public:
    BloomsTaxonomy() {
        file.open("Blooms.txt", ios::out);
        file << "1.Remembering :\tDefine\tList\tRecall\tMemorize\tIdentify\tRepeat\tName " << endl << endl;
        file << "2.Understanding :\tExplain\tSummarize\tParaphrase\tInterpret\tInfer\tClassify\tCompare\tContrast " << endl << endl;
        file << "3.Applying :\tApply\tUse\tImplement\tSolve\tDemonstrate\tIllustrate\tOperate\tCalculate " << endl << endl;
        file << "4.Analyzing :\tAnalyze\tCompare\tContrast\tDifferentiate\tDistinguish\tExamine\tBreak down " << endl << endl;
        file << "5.Evaluating :\tEvaluate\tJudge\tAssess\tCritique\tJustify\tValidate " << endl << endl;
        file << "6.Creating :\tCreate\tDesign\tInvent\tGenerate\tCompose\tDevelop\tConstruct " << endl << endl;
    }

    string getLevel(const string& word) {
        ifstream myfile("Blooms.txt", ios::in);
        string file_word, level;

        while (myfile >> file_word) {
            transform(file_word.begin(), file_word.end(), file_word.begin(), ::tolower);
            if (file_word[0] >= '1' && file_word[0] <= '6')
                level = file_word;
            if (file_word == word) {
                myfile.close();
                return level;
            }
        }

        myfile.close();
        return "Not found";
    }

    ~BloomsTaxonomy() {
        file.close();
    }
};

// Class to analyze questions using Bloom's Taxonomy
class QuestionAnalyzer {
private:
    vector<string> words;
    BloomsTaxonomy taxonomy;

public:
    void analyzeQuestion(const string& question) {
        istringstream iss(question);
        string word, level;

        while (iss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            level = taxonomy.getLevel(word);
            if (level != "Not found") {
                cout << "Word '" << word << "' is found in level " << level << " of Bloom's Taxonomy." << endl;
            }
        }
    }
};

int main() {
    BloomsTaxonomy taxonomy;
    QuestionAnalyzer analyzer;

    // Example 1: Identify the level of a word
    string wordToIdentify;
    cout << "Enter a word to identify its level in Bloom's Taxonomy: ";
    cin >> wordToIdentify;
    transform(wordToIdentify.begin(), wordToIdentify.end(), wordToIdentify.begin(), ::tolower);
    string identifiedLevel = taxonomy.getLevel(wordToIdentify);
    if (identifiedLevel != "Not found") {
        cout << "The word '" << wordToIdentify << "' is found in level " << identifiedLevel << " of Bloom's Taxonomy." << endl;
    } else {
        cout << "The word '" << wordToIdentify << "' is not found in Bloom's Taxonomy." << endl;
    }

    // Example 2: Analyze a question
    string questionToAnalyze;
    cin.ignore(); // Clear the newline character left in the buffer
    cout << "\nEnter a question to analyze using Bloom's Taxonomy: ";
    getline(cin, questionToAnalyze);
    analyzer.analyzeQuestion(questionToAnalyze);

    return 0;
}
