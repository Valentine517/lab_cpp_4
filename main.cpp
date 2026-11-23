#include <iostream>
#include <cmath>

using namespace std;

// ==================== ОГОЛОШЕННЯ ФУНКЦІЙ (ДО MAIN) ====================

// Допоміжна функція перевірки числа на діапазон [-100, 100]
bool isInRange(double val);

// --- Завдання 1.1 (Proc25) ---
void CompoundInterest(double P, double r, int n, double &A); // обчислення складних відсотків
void task_Proc25();                                           // процедура виконання Proc25

// --- Завдання 1.2 (Proc32) ---
double Calc(double A, double B, int Op);                      // арифметичні операції
void task_Proc32();                                           // процедура виконання Proc32

// --- Завдання 2 (Integer14) ---
bool in_Num(int &K);                                          // введення з перевіркою
int shift_RightToLeft(int K);                                 // перестановка цифр
void out_Res(int res);                                        // виведення результату
void task_Integer14();                                        // процедура виконання Integer14


// ==================== ГОЛОВНА ФУНКЦІЯ (ЗАВДАННЯ 3: МЕНЮ) ====================

int main() {
    int choice; // змінна для вибору пункту меню

    cout << "=== Lab Work #4 (Variant 28: Stetsiura) ===" << endl;
    cout << "1. Task 1.1 (Proc25 - Compound Interest)" << endl;
    cout << "2. Task 1.2 (Proc32 - Arithmetic Operations)" << endl;
    cout << "3. Task 2 (Integer14 - Shift Last Digit to Front)" << endl;
    cout << "Select task number (1-3): ";
    cin >> choice;

    // Перевірка коректності введення пункту меню
    if (cin.fail()) {
        cout << "Error! Please enter an integer." << endl;
        return 1;
    }

    // Інструкція вибору switch для запуску відповідної процедури без параметрів
    switch (choice) {
        case 1:
            task_Proc25();
            break;
        case 2:
            task_Proc32();
            break;
        case 3:
            task_Integer14();
            break;
        default:
            cout << "Invalid choice! Enter a number from 1 to 3." << endl;
            break;
    }

    return 0;
}


// ==================== ВИЗНАЧЕННЯ ФУНКЦІЙ (ПІСЛЯ MAIN) ====================

bool isInRange(double val) {
    return (val >= -100.0 && val <= 100.0);
}

// -------------------- PROC 25 --------------------

void CompoundInterest(double P, double r, int n, double &A) {
    A = P * pow(1.0 + r, n);
}

void task_Proc25() {
    double P1, r1, A1, P2, r2, A2, P3, r3, A3;
    int n1, n2, n3;

    cout << "\n--- Task 1.1: Proc25 (Compound Interest) ---" << endl;
    cout << "Note: values in range [-100, 100], P > 0, r >= 0, n > 0." << endl;

    cout << "Investment 1 (enter P, r, n): ";
    cin >> P1 >> r1 >> n1;
    if (cin.fail() || !isInRange(P1) || !isInRange(r1) || !isInRange(n1) || P1 <= 0 || r1 < 0 || n1 <= 0) {
        cout << "Error! Invalid input for investment 1." << endl;
        return;
    }

    cout << "Investment 2 (enter P, r, n): ";
    cin >> P2 >> r2 >> n2;
    if (cin.fail() || !isInRange(P2) || !isInRange(r2) || !isInRange(n2) || P2 <= 0 || r2 < 0 || n2 <= 0) {
        cout << "Error! Invalid input for investment 2." << endl;
        return;
    }

    cout << "Investment 3 (enter P, r, n): ";
    cin >> P3 >> r3 >> n3;
    if (cin.fail() || !isInRange(P3) || !isInRange(r3) || !isInRange(n3) || P3 <= 0 || r3 < 0 || n3 <= 0) {
        cout << "Error! Invalid input for investment 3." << endl;
        return;
    }

    CompoundInterest(P1, r1, n1, A1);
    CompoundInterest(P2, r2, n2, A2);
    CompoundInterest(P3, r3, n3, A3);

    cout << "Future value 1: " << A1 << endl;
    cout << "Future value 2: " << A2 << endl;
    cout << "Future value 3: " << A3 << endl;
}

// -------------------- PROC 32 --------------------

double Calc(double A, double B, int Op) {
    switch (Op) {
        case 1: return A - B;
        case 2: return A * B;
        case 3: return A / B;
        default: return A + B;
    }
}

void task_Proc32() {
    double A, B;
    int N1, N2, N3;

    cout << "\n--- Task 1.2: Proc32 (Arithmetic Operations) ---" << endl;
    cout << "Enter two non-zero real numbers A and B (in range [-100, 100]): ";
    cin >> A >> B;

    if (cin.fail() || !isInRange(A) || !isInRange(B) || A == 0 || B == 0) {
        cout << "Error! A and B must be non-zero numbers in range [-100, 100]." << endl;
        return;
    }

    cout << "Enter three integer operation codes N1, N2, N3 (1: -, 2: *, 3: /, other: +): ";
    cin >> N1 >> N2 >> N3;

    if (cin.fail() || !isInRange(N1) || !isInRange(N2) || !isInRange(N3)) {
        cout << "Error! Operation codes must be integers in range [-100, 100]." << endl;
        return;
    }

    cout << "Result N1 (" << N1 << "): " << Calc(A, B, N1) << endl;
    cout << "Result N2 (" << N2 << "): " << Calc(A, B, N2) << endl;
    cout << "Result N3 (" << N3 << "): " << Calc(A, B, N3) << endl;
}

// -------------------- INTEGER 14 --------------------

bool in_Num(int &K) {
    cout << "\n--- Task 2: Integer14 (Shift Last Digit to Front) ---" << endl;
    cout << "Enter a three-digit integer K (100 to 999 or -999 to -100): ";
    cin >> K;

    if (cin.fail()) {
        return true;
    }

    int absK = abs(K);
    if (absK < 100 || absK > 999) {
        return true;
    }

    return false;
}

int shift_RightToLeft(int K) {
    int sign = (K < 0) ? -1 : 1;
    int absK = abs(K);
    int lastDigit = absK % 10;
    int firstTwoDigits = absK / 10;

    return sign * (lastDigit * 100 + firstTwoDigits);
}

void out_Res(int res) {
    cout << "Resulting number: " << res << endl;
}

void task_Integer14() {
    int K;

    if (in_Num(K)) {
        cout << "Error! Input is not a valid three-digit integer." << endl;
    } else {
        int result = shift_RightToLeft(K);
        out_Res(result);
    }
}
