#include <iostream>
#include <iomanip>
#include <string>
#include <random> //randomizer
#include <sstream>
#include <vector>
using namespace std;

class Bingo {
    private:
        int max_value;
    public:
        // int arr[5][5];
        void populate_card(int arr[][5], int max_value);
        void display_card(int arr[][5]);
        string search_card(int arr[][5], int num);
        int (*mark_card(int arr[][5], string colrow))[5];
        bool bingo_check(int arr[][5]);

};

int roundtofive(int num) {
    while ((num % 5) != 0) {
        num++;
    }
    return num;
}

int randomizer(int start, int end) { //O(1)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(start, end);

    return distrib(gen);
}

void Bingo::populate_card(int arr[][5], int max_value) {
    int bmax, imax, nmax, gmax, omax;
    bmax = max_value*(.2);
    imax = max_value*(.4);
    nmax = max_value*(.6);
    gmax = max_value*(.8);
    omax = max_value;
    for (int i = 0; i < 5 ; i++) { //use lab 5 to remove duplicates
        arr[0][i] = randomizer(1, bmax);

        for (int k = 0; k < 5; k++) {
            for (int j = 0; j < 5; j++) {
                if (arr[k][j] == arr[0][i] && j != i) {
                    while ((arr[k][j] == arr[0][i])) {
                        arr[0][i] = randomizer(1, bmax);
                }}
    }}
    }
    


    for (int i = 0; i < 5 ; i++) {
        arr[1][i] = randomizer(bmax + 1, imax);
        for (int k = 0; k < 5; k++) {
            for (int j = 0; j < 5; j++) {
                if (arr[k][j] == arr[1][i] && j != i) {
                    while ((arr[k][j] == arr[1][i])) {
                        arr[1][i] = randomizer(bmax + 1, imax);
                }}
    }}
    }
    for (int i = 0; i < 5 ; i++) {
        arr[2][i] = randomizer(imax + 1, nmax);
        for (int k = 0; k < 5; k++) {
            for (int j = 0; j < 5; j++) {
                if (arr[k][j] == arr[2][i] && j != i) {
                    while ((arr[k][j] == arr[2][i])) {
                         arr[2][i] = randomizer(imax + 1, nmax);
                }}
    }}
    }
    for (int i = 0; i < 5 ; i++) {
        arr[3][i] = randomizer(nmax + 1, gmax);
        for (int k = 0; k < 5; k++) {
            for (int j = 0; j < 5; j++) {
                if (arr[k][j] == arr[3][i] && j != i) {
                    while ((arr[k][j] == arr[3][i])) {
                        arr[3][i] = randomizer(nmax + 1, gmax);
                }}
    }}
    }
    for (int i = 0; i < 5 ; i++) { 
        arr[4][i] = randomizer(gmax + 1, omax);
        for (int k = 0; k < 5; k++) {
            for (int j = 0; j < 5; j++) {
                if (arr[k][j] == arr[4][i] && j != i) {
                    while ((arr[k][j] == arr[4][i])) {
                        arr[4][i] = randomizer(gmax + 1, omax);
                }}
    }}
    }
    arr[2][2] = 0;

}

void Bingo::display_card(int arr[][5]) { //O(n^2)
    cout << "=============================================================" << endl;
    cout << "|" << " " 
    << setw(5) << "B" << setw(5) << " " << "|" << " " 
    << setw(5) << "I" << setw(5) << " " << "|" << " " 
    << setw(5) << "N" << setw(5) << " " << "|" << " " 
    << setw(5) << "G" << setw(5) << " " << "|" << " " 
    << setw(5) << "O" << setw(5) << " " << "|" << " "  << endl;
    cout << "=============================================================" << endl;
    for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cout << "|" << " " << setw(5);
                if (arr[j][i] == 0)
                    cout << "FREE";
                else if (arr[j][i] < 0)
                    cout << "X" << to_string(-1*arr[j][i]) << "X";
                else
                    cout << to_string(arr[j][i]);
                cout << setw(5) << " ";
                if (j == 4)
                    cout << "|" << endl << "-------------------------------------------------------------" << endl;
        }}
}

string Bingo::search_card(int arr[][5], int num) { //O(n^2)
    int col, row;
    for (int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if (num == arr[i][j]){
                col = i;
                row = j;
            }
        }
    }
    string colstring = to_string(col);
    string rowstring = to_string(row);
    string colrow = colstring + rowstring;

    return(colrow);
}

int (*Bingo::mark_card(int arr[][5], string colrow))[5] { //O(1)
    int col = int(colrow[0] - '0');
    int row = int(colrow[1] - '0');
    arr[col][row] = arr[col][row]*-1;

    int (*p)[5] = arr;
    return(p);
}

bool Bingo::bingo_check(int arr[][5]) { //O(n)
    for (int i = 0; i < 5; i++) {
        if (arr[i][0] <= 0 && arr[i][1] <= 0 && arr[i][2] <= 0 && arr[i][3] <= 0 && arr[i][4] <= 0){
            return true;
            }
        if (arr[0][i] <= 0 && arr[1][i] <= 0 && arr[2][i] <= 0 && arr[3][i] <= 0 && arr[4][i] <= 0){
            return true;
        }          
    }
    if (arr[0][0] <= 0 && arr[1][1] <= 0 && arr[2][2] <= 0 && arr[3][3] <= 0 && arr[4][4] <= 0) {
        return true;
    }
    if (arr[4][0] <= 0 && arr[3][1] <= 0 && arr[2][2] <= 0 && arr[1][3] <= 0 && arr[0][4] <= 0) {
        return true;
    }
        
    return false;
}

int main() {
    Bingo g;
    int max_value = 0, num_cards = 0, inputval = 0, winningcard;
    vector<int (*)[5]> v;


    cout << "Input Max Value: ";
    cin >> max_value;
    max_value = roundtofive(max_value);
    cout << "Input Number of Cards: ";
    cin >> num_cards;
    for (int i = 0; i < num_cards; ++i) {
        int (*newarr)[5] = new int[5][5]; 
        g.populate_card(newarr, max_value);
        g.display_card(newarr);
        v.push_back(newarr); 
    }

    while(true){
        cout << "Input Value: ";
        cin >> inputval;
        for (int i = 0; i < num_cards; ++i) {
            int(*newarr)[5] = v[i];
            v[i] = g.mark_card(newarr, g.search_card(newarr, inputval));
        
            if (g.bingo_check(v[i]) == true) {
                winningcard = i;
                goto jump;
            } else {
                cout << "Card # " << i+1 << endl;
                g.display_card(v[i]);
            }
        }
    }
    jump:
        cout << "B I N G O !!!" << endl << "CARD NO. # " << winningcard + 1 << " HAS WON!" << endl;
        g.display_card(v[winningcard]);
        return 0;
    

}