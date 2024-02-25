#include <iostream>
#include <cmath>
#include <string>

using namespace std;


template<typename T>
class Pair {
    private:
        T first, second;
    public:
        Pair(T first, T second);
        //Accessor
        T get_first();
        T get_second();

        //mutator
        void set_first(T val);
        void set_second(T val);

        Pair<T> operator+(Pair b);
        Pair<T> operator/(Pair b); //new operator

        void show_pair();
};



template<typename T>
Pair<T>::Pair(T first, T second) {
    this -> first = first;
    this -> second = second;
}

template<typename T>
T Pair<T>::get_first() {
    return this -> first;
}

template<typename T>
T Pair<T>::get_second() {
    return this -> second;
}

template<typename T>
void Pair<T>::set_first(T val) {
    this -> first = val;
}

template<typename T>
void Pair<T>::set_second(T val) {
    this -> second = val;
}

template<typename T>
void Pair<T>::show_pair() {
    cout << this -> first << " and " << this -> second << endl;
}

template<>
void Pair<double>::show_pair() {
    cout << this -> first << endl;
}

template<typename T>
Pair<T> Pair<T>::operator+(Pair b) {
    return Pair(this -> first + b.first,
                this -> second + b.second);
}

template<typename T>
Pair<T> Pair<T>::operator/(Pair b) {
    string finalval, finalvalb;
    string allstrings = first + second + b.first + b.second; //add all the strings together 
    int mostchar;
    int mostcounter = 0;
    for(int i=93;i<=123;i++){ //ASCII of lowercase letters
        int counter = 0;
        int n = allstrings.length();
        for(int j=0 ;j<n ; j++){ //run through all the chars in the "allstrings"
            if(i == allstrings[j]){
                counter++;} //count how many occurences
        if(mostcounter <= counter){ //if there is a char with a greater occurence, take note
            mostchar = i;
            mostcounter = counter;   
        }}}

    first = mostchar; //get the most recurred char
    second = to_string(mostcounter); //turn into string so that there is no error as it passes through pair
    return Pair<T>(first, second);
}

template<>
Pair<double> Pair<double>::operator/(Pair<double> b) { 
    double finalval = first + second + b.first + b.second; //average equation
    double finalave = finalval / 4;
    cout << finalave << endl;
};

int main() {
    string input1, input2, input3, input4;
    double input5, input6, input7, input8; //double to make sure most, if not, all numbers with decimals are accepted

    cin >> input1;
    cin >> input2;
    cin >> input3;
    cin >> input4;
    cin >> input5;
    cin >> input6;
    cin >> input7;
    cin >> input8;
    Pair<string> p1 = Pair<string>(input1, input2);
    Pair<string> p2 = Pair<string>(input3, input4);
    Pair<double> p3 = Pair<double>(input5, input6);
    Pair<double> p4 = Pair<double>(input7, input8);
    (p1/p2).show_pair();
    (p3/p4).show_pair();

    return 0;
}