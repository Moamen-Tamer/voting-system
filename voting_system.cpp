#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

struct cnd {
    const static int size = 3;
    vector<string>names;
    static vector<int>points;
    
    cnd (string a, string b, string c): names({a, b, c}) {
        if (points.empty()) {
            points.resize(size, 0);
        }
    }
};

vector<int> cnd::points;

void dash();
void mod_dash();
void vote (cnd& c);
void result (cnd& c);
void winner (cnd& c);

int main () {
    cnd voter("jane", "david", "amber");
    
    vote(voter);
    
    return 0;
}

void vote (cnd& c) {
    string name;
    int number;
    cout << "no. of voters: ";
    cin >> number;
    cin.ignore();
    
    for(int i = 0; i < number; i++) {
        bool valid = false;
        cout << "The Candidate: ";
        getline(cin, name);
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        for(int j = 0; j < cnd::size; j++) {
            if (name == c.names[j]) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            cout << "\nInvalid Candidate" << endl;
            return;
        }
        for(int k = 0; k < cnd::size; k++) {
            if (c.names[k] == name) {
                c.points[k] += 1;
            }
        }    
    }    
    cout << "Voted Successfully" << endl;
    dash();
    result (c);
    winner (c);
}

void result (cnd& c) {
    cout << "Scores: " << endl;
    for (int i = 0; i < cnd::size; i++) {
        cout << setw(12) << c.names[i] << ": " << right << c.points[i] << " points" << endl;
    mod_dash();
    }
}

void winner (cnd& c) {
    int max = c.points[0];
    string s = c.names[0];
    for (int i = 1; i < cnd::size; i++) {
        if (max < c.points[i]) {
            max = c.points[i];
            s = c.names[i];
        }
    }
    cout << "winner is " << s << endl;
}

void dash() {
    cout << "-----------------------" << endl;
}

void mod_dash() {
    cout << setw(6) << " " << "-----------------" << endl;
}