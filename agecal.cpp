#include <iostream>
using namespace std;

// ฟังก์ชันเพื่อคำนวณอายุ
void calculateAge(int current_day, int current_month, int current_year, int birth_day, int birth_month, int birth_year) {
    // คำนวณปี
    int age_year = current_year - birth_year;

    // คำนวณเดือน
    int age_month = 0;
    if (current_month >= birth_month) {
        age_month = current_month - birth_month;
    } else {
        age_year--;
        age_month = 12 + current_month - birth_month;
    }

    // คำนวณวัน
    int age_day = 0;
    if (current_day >= birth_day) {
        age_day = current_day - birth_day;
    } else {
        age_month--;
        if (current_month == 1) {
            age_day = 31 + current_day - birth_day;
        }
        else if (current_month == 2) {
            if ((current_year % 4 == 0 && current_year % 100 != 0) || current_year % 400 == 0) {
                age_day = 29 + current_day - birth_day;
            }
            else {
                age_day = 28 + current_day - birth_day;
            }
        }
        else if (current_month == 4 || current_month == 6 || current_month == 9 || current_month == 11) {
            age_day = 30 + current_day - birth_day;
        }
        else {
            age_day = 31 + current_day - birth_day;
        }
    }

    // พิมพ์ผลลัพธ์
    cout << "Age: " << age_year << " years " << age_month << " months " << age_day << " days" << endl;
}

int main() {
    int current_day, current_month, current_year, birth_day, birth_month, birth_year;

    // รับวันเดือนปีปัจจุบัน
    cout << "Enter current date (day month year): ";
    cin >> current_day >> current_month >> current_year;

    // รับวันเดือนปีเกิด
    cout << "Enter birth date (day month year): ";
    cin >> birth_day >> birth_month >> birth_year;

    // คำนวณอายุ
    calculateAge(current_day, current_month, current_year, birth_day, birth_month, birth_year);

    return 0;
}
