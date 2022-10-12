/*
Author: Mohammad Seeam
Purpose: Demonstrating use of various features of C++ functions to calculate distance.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

char input(string prompt_text, string error_message_text){
    char x;
    while(true){
        cout<<prompt_text;
        cin>>x;
        if(!isalpha(x)){
            cout << error_message_text << endl;
            continue;
        }
        break;
    }
    return x;
}
double input(double min_number, double max_number, string prompt_text, string error_message_text){
    double x;
    while(true){
        cout<<prompt_text;
        cin>>x;
        if(x<min_number || x>max_number){
            cout<<error_message_text<<endl;
            continue;
        }
        break;
    }
    return x;
}
void input(double &x, double &y, string prompt_text){
    static string X = "X1";
    static string Y= "Y1";
    while(true){
        cout<<prompt_text + X + ":";
        cin>>x;
        if (x>100.00 || x<-100.00){
            cout<< "Number X1 not in range." << endl;
            continue;
        }
        break;
    }
    while(true){
        cout<<prompt_text + Y + ":";
        cin>>y;
        if (y>100.00 || y<-100.00){
            cout<< "Number Y1 not in range. " << endl;
            continue;
        }
        break;
    }
    X = "X2";
    Y = "Y2";
}
int dist(char x, char y){
    int distance_of_char=x-y;
    return distance_of_char;
}
double dist(double d1, double d2){
    double diatance_of_number=d2-d1;
    return diatance_of_number;
}
double dist(double x1, double x2, double y1, double y2){
    double distance_of_point=(sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1))));
    return distance_of_point;
}
void display(const string &msg, char ch1='z', char ch2='a'){
    static string disp = "the distance between characters ";
    disp.append(1, ch1);
    disp = disp + " and ";
    disp.append(1, ch2);
    disp = disp + " is " + msg;
    cout<< disp << endl;
}
void display(const string &msg, double d1, double d2){
    cout<< "the distance between numbers " << d1 << " and " << d2 << " is " << msg << endl;
}
void display(const string &msg, double x1, double y1, double x2, double y2){
    cout<<"The distance between points " << "x1: "<< x1<< ", y1: "<<y1<< ", x2: "<<x2<<", y2: "<<y2<<" is "<<msg<<endl;
}
int main(){
    cout<<"Display the distance between two items: letters, numbers, or points."<<endl;
    while(true){
    cout<<"Please enter the option: L/l for Letter, N/n for Number, P/p for Point, Q/q for Quit: ";
    char options=' '; //this is named options because it will take option as input from user, such as l for letter//
    cin>> options;
    char options_upper_lower = tolower(options); //it is named options_upper_lower because it will work with both lower and upper case
    if (options_upper_lower=='l'){
        string prompt = "Please enter a character: ";
        string error = "Number is not alpha-numeric.";
        char x = input(prompt, error);
        char y = input(prompt, error);
        int diatance_of_letter = dist(x,y);
        string msg = to_string(abs(diatance_of_letter));
        display(msg, x, y);

    }else if(options_upper_lower=='n'){
        double min = -100.00;
        double max = 1000.00;
        string prompt = "Please enter a number: ";
        string error = "Number not in range.";
        double x = input(min, max, prompt, error);
        double y = input(min, max, prompt, error);
        double diatance_of_number = dist(x,y);
        string msg = to_string(abs(diatance_of_number));
        display(msg, x, y );

    }else if(options_upper_lower=='p'){
       double x1;
       double x2;
       double y1;
       double y2;
       string prompt = "Please enter a number ";
       input(x1,y1, prompt);
       input(x2,y2, prompt);
       double distance_of_points= dist(x1,x2,y1,y2);
       string msg = to_string(abs(distance_of_points));
       display(msg, x1, y1, x2, y2);

    }else if(options_upper_lower=='q'){
        cout<<"Good Bye!"<<endl;
        exit(0);}
    }
}
/*
Display the distance between two items: letters, numbers, or points.
Please enter the option: L/l for Letter, N/n for Number, P/p for Point, Q/q for Quit: l
Please enter a character: a
Please enter a character: z
the distance between characters a and z is 25
Please enter the option: L/l for Letter, N/n for Number, P/p for Point, Q/q for Quit: n
Please enter a number: 12
Please enter a number: 90
the distance between numbers 12 and 90 is 78.000000
Please enter the option: L/l for Letter, N/n for Number, P/p for Point, Q/q for Quit: l
Please enter a character: 1
Number is not alpha-numeric.
Please enter a character: a
Please enter a character: f
the distance between characters a and z is 25a and f is 5
Please enter the option: L/l for Letter, N/n for Number, P/p for Point, Q/q for Quit: p
Please enter a number X1:3
Please enter a number Y1:3
Please enter a number X2:1
Please enter a number Y2:5
The distance between points x1: 3, y1: 3, x2: 1, y2: 5 is 2.828427
Please enter the option: L/l for Letter, N/n for Number, P/p for Point, Q/q for Quit: q
Good Bye!
*/