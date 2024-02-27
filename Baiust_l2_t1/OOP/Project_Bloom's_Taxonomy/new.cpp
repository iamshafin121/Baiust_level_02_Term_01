system("cls");
            cout << "\t___QUESTION___" << endl << endl;
            cout << "Write 'Exit' for finish the process." << endl;
            cout << "Enter a question : " ;


            getline(cin,question);
            istringstream iss(question);
            string word, level;

            while (iss >> word) {
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                given_question.push_back(word);
            }



            // cin >> sub_string;
            // transform(sub_string.begin(), sub_string.end(), sub_string.begin(), ::tolower);
            // given_question.push_back(sub_string);
            // while(sub_string[sub_string.size()-1]!='\n'){
            
            // while(sub_string.back() == '\n'){
            //     cin >> sub_string;
            //     transform(sub_string.begin(), sub_string.end(), sub_string.begin(), ::tolower);
            //     given_question.push_back(sub_string);
            //     cout << sub_string << endl;
            // }



            // getline(cin,sub_string);
            // char c[100];
            // string s;
            // int j = 0;
            // for(int i=0; sub_string[i] != '\0';j++,i++){
            //     if(sub_string[i]==' '){
            //         s[j] = '\0';
            //          transform(s.begin(), s.end(), s.begin(), ::tolower);
            //         given_question.push_back(c);
            //         j=0;
            //     }
            //     else{
            //         s[j] = sub_string[i];
            //     }
            // }
            // s[j] = '\0';
            // given_question.push_back(s);




            // string question;
            // getline(cin, question);

            // istringstream iss(question);
            // string word;
            // while (iss >> word) {
            //     transform(word.begin(), word.end(), word.begin(), ::tolower);
            //     given_question.push_back(word);
            // }





            
            if(given_question[0] == "exit") return false;
            else{
                for(string word : given_question){
                    myfile.open("Blooms.txt", ios::in);
                    while(myfile >> file_word){
                        transform(file_word.begin(), file_word.end(), file_word.begin(), ::tolower);
                        if(file_word[0]>='1' && file_word[0]<='6') level = file_word; 
                        if(file_word == word) {
                            Blooms_Taxonomy::Display(level);
                            cout << endl;
                        }
                    }
                    myfile.close();
                }
            }
            system("pause");
            return true;