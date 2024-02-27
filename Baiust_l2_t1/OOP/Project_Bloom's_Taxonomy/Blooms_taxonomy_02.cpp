


/*
    Bangladesh Army International University of Science and Technology.
    Project name : Bloom's Taxonomy (Word and question level analyzation).
    Name : MD Shafin Ahammad Hredoy
    ID : 0822220105101009
    Level : 02 , Term : 01
    Section : A

*/



#include <bits/stdc++.h>
using namespace std;



class Blooms_Taxonomy {
protected:
    fstream file;

public:
    Blooms_Taxonomy() {
        file.open("Blooms.txt", ios::out);
        file << "1.Remembering :\tDefine\tList\tRecall\tMemorize\tIdentify\tRepeat\tName " << endl << endl;
        file << "2.Understanding :\tExplain\tSummarize\tParaphrase\tInterpret\tInfer\tClassify\tCompare\tContrast " << endl << endl;
        file << "3.Applying :\tApply\tUse\tImplement\tSolve\tDemonstrate\tIllustrate\tOperate\tCalculate " << endl << endl;
        file << "4.Analyzing :\tAnalyze\tCompare\tContrast\tDifferentiate\tDistinguish\tExamine\tBreak down " << endl << endl;
        file << "5.Evaluating :\tEvaluate\tJudge\tAssess\tCritique\tJustify\tValidate " << endl << endl;
        file << "6.Creating :\tCreate\tDesign\tInvent\tGenerate\tCompose\tDevelop\tConstruct " << endl << endl;
    }

    void Display(string s) {
        cout << "Found in level " << s << "." << endl;
    }

    ~Blooms_Taxonomy() {
        file.close();
    }
};

class Blooms_Taxonomy_word : public Blooms_Taxonomy {
private:
    ifstream myfile;
    string given_word;
    string file_word;
    string level;

public:
    Blooms_Taxonomy_word() {
        myfile.open("Blooms.txt", ios::in);
    }

    void Run() {
        cout << "\t___WORD SEARCH___" << endl << endl;
        cout << "Enter a Word: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> given_word;
        transform(given_word.begin(), given_word.end(), given_word.begin(), ::tolower);
        bool found = false;
        while (myfile >> file_word) {
            transform(file_word.begin(), file_word.end(), file_word.begin(), ::tolower);
            if (file_word[0] >= '1' && file_word[0] <= '6')
                level = file_word;
            if (file_word == given_word) {
                Display(level);
                found = true;
            }
        }
        if(!found) cout << "The word is not in any level." << endl;
        system("Pause");
        system("cls");
    }

    void Display(string s) {
        cout << "The word found in level " << s[0] << " Which is (" << (char)(s[2]-32);
        for(int i=3; i<s.length(); i++) cout << s[i];
        cout << ") level." << endl;
    }

    ~Blooms_Taxonomy_word() {
        myfile.close();
    }
};

class Blooms_Taxonomy_question : public Blooms_Taxonomy {
private:
    ifstream myfile;
    string question;
    vector<string> qs_word;
    string file_word;
    string level;

public:
    void Run() {
        cout << "\t___QUESTION ANALYSIS___" << endl << endl;
        cout << "Enter a Question: ";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, question);
        transform(question.begin(), question.end(), question.begin(), ::tolower);
        qs_word = extractWords(question);
        bool found = false;
        for (const auto& word : qs_word) {

            ifstream myfile("Blooms.txt", ios::in);

            while (myfile >> file_word) {
                transform(file_word.begin(), file_word.end(), file_word.begin(), ::tolower);
                if (file_word[0] >= '1' && file_word[0] <= '6') level = file_word;
                if (file_word == word){
                    Display(level);
                    found = true;
                }
            }

            myfile.close();
        }
        if(!found) cout << "The question is not in any level." << endl;
        system("Pause");
        system("cls");
    }

    vector<string> extractWords(const string& sentence) {
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

    void Display(string s){
        cout << "The question is written in level " << s[0]  << " (";
        for(int i=2; i<s.length(); i++) cout << s[i];
        cout << ")." << endl;
    }
};


int main() {


    UP:
    int num;
    cout << endl << endl << "\t___BLOOM's TAXONOMY___" << endl << endl;
    cout << "Enter 1 for Word Search." << endl;
    cout << "Enter 2 for Question Analysis." << endl;
    cout << "Enter 3 for Exit." << endl;
    cout << ">>> ";
    cin >> num;
    if (num == 1) {
        Blooms_Taxonomy_word a;
        a.Run();
    } else if (num == 2) {
        Blooms_Taxonomy_question a;
        a.Run();
    } else if (num == 3) {
        return 0;
    }
    else{
        cout << "Invalid Input! Please Try again!" << endl;
    }

    goto UP;

}
