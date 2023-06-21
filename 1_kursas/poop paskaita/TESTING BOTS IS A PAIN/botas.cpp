///MANTAS DONELA v1
//Del laiko stokos labai daug trukumu kode



#include <iostream>
#include <string>
#include<ctype.h>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#define RAND rand() % 3

using namespace std;
const string greetings[] = {"Hello!", "Good day!", "Welcome!"};
const string wrong_answer[] = {"Whoops wrong answer", "Sorry but you are incorrect", "Unfortunately you are incorrect"};
const string multiplication_question[] = {"What is = ", "What do you get when you multiply these numbers?", "Can you solve this ?"};
const string right_answer[] = {"You are correct!", "Wow you are so smart!", "Huh? the question is too easy?"};
const string end_of_questions[] = {"Wow you answered all questions right, good job", "Good job you passed all questions","All answers are correct, I will make questions harder next time" };
const string ending[] = {"Thanks for your time!Bye!", "I liked playing with you, goodbye!", "Thank you for playing. Farewell"};
const string bad[] = {"Bad input", "I didnt understand your answer", "Can you say that again? I dont really get it"};

void start();
void Multi_question();
void Sub_question();
void Addition_question();
void ending_bot();
void Bad_input();


//void print(string quest);

class Questions {
private:
    int answer;
public:
    void set_answer(){
            cin>>answer;

        }
        int get_answer(){
            return answer;
        }
        Questions(){
            answer = 0;
        //cout<<"constructor"<<endl;

        }
        ~Questions(){
        //cout<<"destructor"<<endl;
        }



};


int main(){
    Questions multiplication;
    srand((unsigned) time(NULL));
   // multiplication.set_answer();
    //cout<<multiplication.get_answer()<<endl;
   // cout<<multiplication_question[1]<<endl;
    start();

    return 0;
}
/*void print(string quest){
    cout<<quest<<endl;




}*/
void start(){
    string answer;
    cout<<greetings[RAND]<<endl;
    cout<<"What is your name? "<<endl;
    cin>>answer;
    cout<<"Hi "<<answer<<endl;
    cout<<"What was your favorite subject in school?"<<endl;
    cin>>answer;
    cout<<"Wow so cool. Mine was Maths"<<endl;
    cout<<" Lets play math game!"<<endl;
    cout<<" I will ask math questions and you will need to answer them"<<endl;
    cout<<"What do you want to do ? (subtract, add, multiply)"<<endl;
    cin>>answer;
    while(1){

        if(answer == "add"){
        cout<<"add";
        cout<<"What do you want to do now?(multiply or add)"<<endl;
        cin>>answer;
        if(answer == "multiply"){
            cout<<"mult"<<endl;
            Multi_question();
            cout<<"Okay, I see you are really smart. Last questions will be with subtraction"<<endl;
            Sub_question();
            //End_questions();
            break;
            }
    }


    else if(answer == "multiply"){
        cout<<"mult"<<endl;
        Multi_question();
        cout<<"What do you want to do now?(subtract or add)"<<endl;
        cin>>answer;
        if(answer == "add"){
            cout<<"addition"<<endl;
            Addition_question();
            cout<<"Okay, I see you are really smart. Last questions will be with subtraction"<<endl;
            Sub_question();
            //End_questions();
            break;



        }
    }
    else if(answer == "subtract"){
            cout<<"sub"<<endl;
            Sub_question();
            cout<<"What do you want to do now?(multiply or add)"<<endl;
            cin>>answer;
            if(answer == "add"){
                cout<<"addition"<<endl;
                Addition_question();
                cout<<"Okay, I see you are really smart. Last questions will be with multiplication"<<endl;
                Multi_question();
                //End_questions();
                break;

            }


    }
    else{
           cout<<"bad input"<<endl;

    }


    }



}
void Multi_question(){
    int num1, num2, answ;
    Questions multiplication;
    for(int i = 0; i < 3; ++i){
        num1 = (rand() % 101);
        num2 = (rand() % 101);
        answ = num1 * num2;
        cout<<"answ="<<answ<<endl;
        while(multiplication.get_answer() != answ){

            cout<<multiplication_question[RAND]<<num1<<"*"<<num2<<endl;
            multiplication.set_answer();
            if(multiplication.get_answer() != answ){
               cout<<wrong_answer[RAND]<<endl;
            }

        }
        cout<<right_answer[RAND]<<endl;

    }
    cout<<end_of_questions[RAND]<<endl;


}


void Addition_question(){
    int num1, num2, answ;
    Questions multiplication;
    for(int i = 0; i < 3; ++i){
        num1 = (rand() % 101);
        num2 = (rand() % 101);
        answ = num1 + num2;
        cout<<"answ= "<<answ<<endl;
        while(multiplication.get_answer() != answ){

            cout<<multiplication_question[RAND]<<num1<<"+"<<num2<<endl;
            multiplication.set_answer();
            if(multiplication.get_answer() != answ){
               cout<<wrong_answer[RAND]<<endl;
            }

        }
        cout<<right_answer[RAND]<<endl;

    }
    cout<<end_of_questions[RAND]<<endl;


}

void Sub_question(){
    int num1, num2, answ;
    Questions multiplication;
    for(int i = 0; i < 3; ++i){
        num1 = (rand() % 101);
        num2 = (rand() % 101);
        answ = num1 - num2;
        cout<<"answ= "<<answ<<endl;
        while(multiplication.get_answer() != answ){

            cout<<multiplication_question[RAND]<<num1<<"-"<<num2<<endl;
            multiplication.set_answer();
            if(multiplication.get_answer() != answ){
               cout<<wrong_answer[RAND]<<endl;
            }

        }
        cout<<right_answer[RAND]<<endl;

    }
    cout<<end_of_questions[RAND]<<endl;


}
void ending_bot(){
    cout<<ending[RAND]<<endl;


}
void Bad_input(){
    cout<<bad[RAND]<<endl;


}

