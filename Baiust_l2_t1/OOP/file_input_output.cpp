#include <bits/stdc++.h>
using namespace std;

class Contestant{
    public:
        string Name;
        int Age, Ratings;

        int input();

        int output_highest_rated();
    
};

int Contestant::input(){

        ofstream file_obj;
        file_obj.open("Input.txt", ios::app);

        Contestant obj;
        obj.Name = "Michael";
        obj.Age = 18;
        obj.Ratings = 2500;

        file_obj.write((char *) &obj, sizeof(obj));

        obj.Name = "Terry";
        obj.Age = 21;
        obj.Ratings = 3200;

        file_obj.write((char *) &obj, sizeof(obj));

        file_obj.close();

        return 0;
}

int Contestant::output_highest_rated(){

    ifstream file_obj;
    file_obj.open("Input.txt",ios::in);

    Contestant obj;
    file_obj.read((char *) &obj, sizeof(obj));
    int max = 0;
    string Highest_rated;
    while(!file_obj.eof()){

        if(obj.Ratings>max){
            max = obj.Ratings;
            Highest_rated = obj.Name;
        }

        file_obj.read((char *) &obj, sizeof(obj));
    }
    
    file_obj.close();

    cout << Highest_rated  << " : " << max << endl;

    return 0;
}


int main(){

    Contestant A;
    A.input();
    A.output_highest_rated();


    return 0;
}