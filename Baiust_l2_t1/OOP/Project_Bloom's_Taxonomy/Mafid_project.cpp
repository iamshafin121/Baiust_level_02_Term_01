#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Blooms_Taxonomy {
protected:
    fstream file;
    vector<string> qs_word;
    string question;
    string f_word;
    string level;
public:
    Blooms_Taxonomy() {
        file.open("Blooms_Taxonomy.txt", ios::out);
        file << "1.Remembering :\tDefine\tList\tRecall\tMemorize\tIdentify\tRepeat\tName " << endl << endl;
        file << "2.Understanding :\tExplain\tSummarize\tParaphrase\tInterpret\tInfer\tClassify\tCompare\tContrast " << endl << endl;
        file << "3.Applying :\tApply\tUse\tImplement\tSolve\tDemonstrate\tIllustrate\tOperate\tCalculate " << endl << endl;
        file << "4.Analyzing :\tAnalyze\tCompare\tContrast\tDifferentiate\tDistinguish\tExamine\tBreak down " << endl << endl;
        file << "5.Evaluating :\tEvaluate\tJudge\tAssess\tCritique\tJustify\tValidate " << endl << endl;
        file << "6.Creating :\tCreate\tDesign\tInvent\tGenerate\tCompose\tDevelop\tConstruct " << endl << endl;
    }
    void Display() {
        cout << "Enter any Question or word: ";
        getline(cin, question);
        transform(question.begin(), question.end(), question.begin(), ::tolower);
        qs_word = extractWords(question);
        bool found = false;

        for (const auto &word : qs_word) {
            ifstream myfile("Blooms_Taxonomy.txt", ios::in);

            while (myfile >> f_word) {
                transform(f_word.begin(), f_word.end(), f_word.begin(), ::tolower);
                if (f_word[0] >= '1' && f_word[0] <= '6')
                    level = f_word;
                if (f_word == word) {
                    cout << "The question refers to the level " << level[0] << " (";
                    for (int i = 2; i < level.length(); i++)
                        cout << level[i];
                    cout << ") of Bloom's Taxonomy." << endl;
                    found = true;
                }
            }

            myfile.close();
        }

        if (!found)
            cout << "The question is not of Bloom's Taxonomy library!!!" << endl;
    }

    vector<string> extractWords(const string &sentence) {
        vector<string> words;
        string word;

        for (char ch : sentence) {
            if (ch == ' ' || ch == '\t') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += ch;
            }
        }

        if (!word.empty()) {
            words.push_back(word);
        }

        return words;
    }
    ~Blooms_Taxonomy() {
        file.close();
    }
};

int main() {

    Blooms_Taxonomy obj;
    obj.Display();
    return 0;
}