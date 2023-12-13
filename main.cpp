#include <iostream>
#include <ctime>

using namespace std;

struct Date {
    int day, month, year;
};

class AgeCalculator {
public:
    Date currentDate;
    Date birthDate;

    AgeCalculator(int currentDay, int currentMonth, int currentYear, int birthDay, int birthMonth, int birthYear) {
        currentDate = {currentDay, currentMonth, currentYear};
        birthDate = {birthDay, birthMonth, birthYear};
    }

    int calculateAgeInYears() {
        int age = currentDate.year - birthDate.year;
        if (currentDate.month < birthDate.month || (currentDate.month == birthDate.month && currentDate.day < birthDate.day)) {
            age--;
        }
        return age;
    }

    int calculateAgeInDays() {
        time_t currentTime = time(nullptr);
        tm currentDateStruct = *localtime(&currentTime);

        tm birthDateStruct = {};
        birthDateStruct.tm_year = birthDate.year - 1900;
        birthDateStruct.tm_mon = birthDate.month - 1;
        birthDateStruct.tm_mday = birthDate.day;

        time_t birthTime = mktime(&birthDateStruct);
        time_t currentTimeInSec = mktime(&currentDateStruct);

        int ageInDays = (currentTimeInSec - birthTime) / (60 * 60 * 24);

        return ageInDays;
    }

    Date findNextBirthday() {
        Date nextBirthday = {birthDate.day, birthDate.month, currentDate.year};
        if (isBirthdayPassed()) {
            nextBirthday.year++;
        }
        return nextBirthday;
    }

private:
    bool isBirthdayPassed() {
        return (currentDate.month > birthDate.month) || (currentDate.month == birthDate.month && currentDate.day >= birthDate.day);
    }
};

int main() {
    int currentDay, currentMonth, currentYear;
    int birthDay, birthMonth, birthYear;

    cout << "Enter current date (day): ";
    cin >> currentDay;
    cout << "\nEnter current date (Month): ";
    cin >> currentMonth;
    cout << "\nEnter current date (Year): ";
    cin >> currentYear;

    cout << "=============================";

    cout << "\n\nEnter birth date (day): ";
    cin >> birthDay;
    cout << "\nEnter birth Month (Month): ";
    cin >> birthMonth;
    cout << "\nEnter birth Year (Year): ";
    cin >> birthYear;

    AgeCalculator ageCalc(currentDay, currentMonth, currentYear, birthDay, birthMonth, birthYear);

    cout << "\nAge: " << ageCalc.calculateAgeInYears() << " years" << endl;
    cout << "Age in days: " << ageCalc.calculateAgeInDays() << " days" << endl;

    Date nextBirthday = ageCalc.findNextBirthday();
    cout << "Next birthday: " << nextBirthday.day << "/" << nextBirthday.month << "/" << nextBirthday.year << endl;

    int x = ageCalc.calculateAgeInYears();
    if (x<17){
        cout << "You are Children\n";
    }
    else if(x>=200){
        cout << "Share your secret, How you alive!!!\n";
    }
    else if(x>=150){
        cout << "You are Very Older\n";
    }
    else if(x>=40){
        cout << "You are Older\n";
    }
    else if(x>=18){
        cout << "You are Adult\n";
    }
    else{
        cout <<"Worng INPUT!!!";
    };

    return 0;
}
