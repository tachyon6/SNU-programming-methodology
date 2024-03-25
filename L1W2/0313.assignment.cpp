#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void afterTime(int currHour, int currMin, int min) {
    int afterHour = currHour;
    int afterMin = currMin + min;
    if(afterMin > 59) {
        afterHour += afterMin / 60;
        afterMin = afterMin % 60;
    }
    if(afterHour > 23){
        afterHour -= 24;
    }

    cout << "ETA: ";
    if(afterHour < 10){
        cout << "0";
    }
    cout << afterHour << ":";
    if(afterMin < 10){
        cout << "0";
    }
    cout << afterMin;
}

int main() {
    int busMin, taxiMin, walkMin, busFee, taxiFee, numFriends, budget, currHour, currMin;

    cin >> busMin >> taxiMin >> walkMin;
    cin >> busFee >> taxiFee;
    cin >> numFriends >> budget;
    cin >> currHour >> currMin;

    int total_busFee = busMin * busFee;
    int total_taxiFee = taxiMin * taxiFee;

    if(numFriends > 0) {
        total_taxiFee = round(float(total_taxiFee) / (1+numFriends));
    }

    cout << "Bus Fee: " << total_busFee << endl;
    cout << "Taxi Fee: " << total_taxiFee << endl;




    if(total_busFee > budget && total_taxiFee > budget) {
        cout << "\"Going home on foot\"" << endl;
        afterTime(currHour, currMin, walkMin);
    } else if(total_busFee > budget) {
        cout << "\"Going home by taxi\"" << endl;
        afterTime(currHour, currMin, taxiMin);
    } else if(total_taxiFee > budget) {
        cout << "\"Going home by bus\"" << endl;
        afterTime(currHour, currMin, busMin);
    } else {
        if(total_busFee < total_taxiFee) {
            cout << "\"Going home by bus\"" << endl;
            afterTime(currHour, currMin, busMin);
        } else {
            cout << "\"Going home by taxi\"" << endl;
            afterTime(currHour, currMin, taxiMin);
        }
    }

    return 0;
}

