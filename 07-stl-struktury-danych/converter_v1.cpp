#include <iostream>

using namespace std;

// Declaration
void toImperial();

void lengthToImperial();

void massToImperial();

int GetAge(int x, int y, std::string text) {

    std::cout << text << "\n";

    int age = 10 + x + y;

    return age;

}

// MAIN MENU
int main() {

    int x = GetAge(100000, 1128, "Ala ma kota");
    int y = x - 10000;

    std::cout << y << "\n";

    while (1) {
        cout << "\n Welcome! This is a metric <=> imperial system converter!\n";
        cout << " What do you need to convert? Choose and press ENTER\n\n";
        cout << " 1 - Metric to imperial\n\n 2 - Imperial to metric\n";
        std::cout << "3 - Exit" << "\n";
        int mi;
        cin >> mi; // wybor Metric lub Imperial
        if (mi == 1) {
            toImperial(); // NIE DZIALA. Wiec po dzisiejszej lekcji mysle ze warto by bylo to zrealizowac wykorzystujac klassy
        } else if (mi == 2) {
            // tu sensownie powinno byc "toMetrical"
        } else if (mi == 3) {
            break;
        } else {
            cout << "\n Whoops! Something went wrong, try to type again!\n";
        }
    }
    return 0;
}




// TO IMPERIAL

void toImperial() {
    cout << " \nChoose the measurement you need to convert:\n\n";
    cout << " 1 -- LENGTH\n\n";
    cout << " 2 -- MASS\n\n";
    cout << " 3 -- CAPACITY\n\n";
    int ilmc;
    cin >> ilmc; // wybor imperial length mass capacity
    switch (ilmc) {
        case 1:
            lengthToImperial(); // chyba tez nie bedzie dzialalo
            break;
            /* w ponizszych czesciach powinna byc massToImperial i capacityToImperial, czyli chcialam
            zrobic duzo tych funkcji aby je uruchamiac pojedynczo. Ten sam balagan by byl
            z czescia gdzyby uzytkownik chcial przekonwertowac cos do sys. metrycznego*/
        case 2:
            //massToImperial
            break;
        case 3:
            //capacityToImperial
        default:
            cout << "\n Whoops! Something went wrong, try to type again!\n";
            toImperial();
    }
}

void lengthToImperial() {
    cout << " Choose the unit of the length to convert:\n\n\n";
    cout << " 1 - cantimeters -> inches\n\n";
    cout << " 2 - meters      -> feet\n\n";
    cout << " 3 - kilometeres -> miles\n\n";
    int unitl;
    cin >> unitl;

    switch (unitl) {
        case 1: {
            const double oneCm = 0.3937; // inches in 1 cantimeter
            double inputCm = 0;
            double inches = oneCm * inputCm;
            cout << " Enter how many cantimeters you want to convert into inches and press ENTER:\n\n";
            cin >> inputCm;
            cout << endl << inputCm << " = " << inches << " inches\n\n";
            main();
        }
            break;
        case 2: {
            const double oneM = 3.2808;  // foot in 1 meter
            double inputM = 0;
            double foot = oneM * inputM;
            cout << " Enter how many meters you want to convert into feet and press ENTER:\n\n";
            cin >> inputM;
            cout << endl << inputM << " = " << foot << " feet\n\n";
            main();
        }
            break;
        case 3: {
            const double oneKm = 0.6213; // miles in kilometer
            double inputKm = 0;
            double mile = oneKm * inputKm;
            cout << " Enter how many kilometers you want to convert into miles and press ENTER:\n\n";
            cin >> inputKm;
            cout << endl << inputKm << " = " << mile << " miles\n\n";
            main();
        }
            break;
        default:
            cout << "\n Whoops! Something went wrong, try to type again!\n";
            lengthToImperial();
    }
}

void massToImperial() {

}
