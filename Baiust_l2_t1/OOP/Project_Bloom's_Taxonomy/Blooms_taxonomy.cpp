


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


class Blooms_Taxonomy{
    protected:
        fstream file;
    public:
        Blooms_Taxonomy(){
            file.open("Blooms.txt", ios::out);
            file << "1.Remembering :\tDefine\tList\tRecall\tMemorize\tIdentify\tRepeat\tName " << endl << endl;
            file << "2.Understanding :\tExplain\tSummarize\tParaphrase\tInterpret\tInfer\tClassify\tCompare\tContrast " << endl << endl;
            file << "3.Applying :\tApply\tUse\tImplement\tSolve\tDemonstrate\tIllustrate\tOperate\tCalculate " << endl << endl;
            file << "4.Analyzing :\tAnalyze\tCompare\tContrast\tDifferentiate\tDistinguish\tExamine\tBreak down " << endl << endl;
            file << "5.Evaluating :\tEvaluate\tJudge\tAssess\tCritique\tJustify\tValidate " << endl << endl;
            file << "6.Creating :\tCreate\tDesign\tInvent\tGenerate\tCompose\tDevelop\tConstruct " << endl << endl;
        }
        void Display(string s){
            cout << "Found in level " << s << "." << endl;
        }
        ~Blooms_Taxonomy(){
            file.close();
        }

};

class Blooms_Taxonomy_word: public Blooms_Taxonomy{
    private:
        string given_word;
        ifstream myfile;
        string level;
        string file_word;
    public:
        Blooms_Taxonomy_word(){
            myfile.open("Blooms.txt", ios::in);
        }
        bool Run(){
            system("cls");
            cout << "\t___WORD SEARCH___" << endl << endl;
            cout << "Write 'Exit' for finish the process." << endl;
            cout << "Enter a Word : " ;
            cin >> given_word;
            transform(given_word.begin(), given_word.end(), given_word.begin(), ::tolower);
            if(given_word == "exit") return false;
            else{
                while(myfile >> file_word){
                    transform(file_word.begin(), file_word.end(), file_word.begin(), ::tolower);
                    if(file_word[0]>='1' && file_word[0]<='6') level = file_word;
                    if(file_word == given_word) {
                        Display(level);
                        cout << endl;
                    }
                }
            }
            system("pause");
            return true;
        }
        void Display(string s){
            cout << "The word found in level " << s << "." << endl;
        }
        ~Blooms_Taxonomy_word(){
            myfile.close();
        }

};

class Blooms_Taxonomy_question: public Blooms_Taxonomy{
    private:
        vector<string> given_question;
        ifstream myfile;
        string sub_string;
        string level;
        string file_word;


        string question;
    public:
        bool Run(){
            // Write the function for a question.
        }
};

int main(){
    UP:
    int num;
    cout << endl << endl << "\t___BLOOM's TAXONOMY___" << endl << endl;
    cout << "Enter 1 for Word Search." << endl;
    cout << "Enter 2 for Question analyzation." << endl;
    cout << "Enter 3 for Exit." << endl;
    cout << ">>> " ;
    cin >> num;
    if(num==1){
       bool Run = true;
        while(Run){
            Blooms_Taxonomy_word a;
            Run = a.Run();
        }
    }
    else if(num==2){
        bool Run = true;
        while(Run){
            Blooms_Taxonomy_question a;
            Run = a.Run();
        }
    }
    else if(num==3){
        return 0;
    }
    else{
        cout << "Invalid input! (Try again)" << endl;
        goto UP;
    }

    

    return 0; 
}