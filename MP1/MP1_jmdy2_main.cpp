#include <iostream>
#include <string>
using namespace std;
class Bingo {
    private:
        int max_value;
    public:
        int card[5][5];
        void populate_card(int max_value);
        void display_card();
        void search_card();
        void mark_card();
        void bingo_check();

};

int roundtofive(int num) {
    while ((num % 5) != 0) {
        num++;
    }
    return num;
}


void Bingo::populate_card(int max_value) {
    int bmax, imax, nmax, gmax, omax, newval;
    bmax = max_value*(.2);
    imax = max_value*(.4);
    nmax = max_value*(.6);
    gmax = max_value*(.8);
    omax = max_value;
    for (int i = 0; i < 5 ; i++) { //use lab 5 to remove duplicates
        newval = ((rand() % (bmax - 1 + 1)) + 1);
        for (int j = 0; j<5;){
            if (card[0][j] == newval) {
                continue;
            } else {
                card[0][i] = ((rand() % (bmax - 1 + 1)) + 1);
            }
        }

        
    }
    for (int i = 0; i < 5 ; i++) {
        card[1][i] = (rand() % (imax - (bmax + 1) + 1)) + (bmax + 1);
    }
    for (int i = 0; i < 5 ; i++) {
        card[2][i] = (rand() % (nmax - (imax + 1) + 1)) + (imax + 1);
    }
    for (int i = 0; i < 5 ; i++) {
        card[3][i] = (rand() % (gmax - (nmax + 1) + 1)) + (nmax + 1);
    }
    for (int i = 0; i < 5 ; i++) { 
        card[4][i] = (rand() % (omax - (gmax + 1) + 1)) + (gmax + 1);
    }
}

void Bingo::display_card() {
    cout << "=============================================================" << endl;
    cout << "|" << " " 
    << "B" << " " << "|" << " " 
    << "I" << " " << "|" << " " 
    << "N" << " " << "|" << " " 
    << "G" << " " << "|" << " " 
    << "O" << " " << "|" << " " << endl;
    cout << "=============================================================" << endl;
    for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cout << "|" << " " << card[j][i] << " ";
                if (j == 4)
                    cout << "|" << endl << "----------------------------------------------------------------------------------" << endl;
        }}
}

void Bingo::search_card() {

}

void Bingo::mark_card() {

}

void Bingo::bingo_check() {

}

int main() {
    Bingo g;
    int max_value, num_cards;
    max_value = 99;
    max_value = roundtofive(max_value);
    num_cards = 5;
    for (int i = 0; i < num_cards; i++){
        string newclass = (to_string(i));
        cout << newclass;
        g.populate_card(max_value);
        // g.display_card();
    }
    

}