#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Convert a Roman numeral to an integer
int romanToInt(std::string s) {
    std::unordered_map<char, int> T = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int sum = T[s.back()];
    for (int i = s.length() - 2; i >= 0; --i) {
        if (T[s[i]] < T[s[i + 1]]) {
            sum -= T[s[i]];
        } else {
            sum += T[s[i]];
        }
    }

    return sum;
}

// Convert an integer to a Roman numeral
std::string intToRoman(int num) {
    std::vector<std::pair<int, std::string>> T = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

    std::string roman;
    for (auto const& t : T) {
        while (num >= t.first) {
            roman += t.second;
            num -= t.first;
        }
    }

    return roman;
}

int main() {
    std::string num1, num2;
    char op;
    std::cout << "Enter two Roman numerals and an operator (+, -, *, /): ";
    std::cin >> num1 >> num2 >> op;

    // Validate input
    if (num1.empty() || num2.empty() || (op != '+' && op != '-' && op != '*' && op != '/')) {
        std::cout << "Error: Invalid input" << std::endl;
        return 1;
    }

    // Convert Roman numerals to integers
    int n1 = romanToInt(num1);
    int n2 = romanToInt(num2);

    // Perform operation
    int result;
    switch (op) {
        case '+':
            result = n1 + n2;
            break;
        case '-':
            result = n1 - n2;
            break;
        case '*':
            result = n1 * n2;
            break;
        case '/':
            result = n1 / n2;
            break;
        default:
            std::cout << "Error: Invalid operator" << std::endl;
            return 1;
    }

    // Validate result
    if (result <= 0 || result > 3999) {
        std::cout << "Error: Result out of range" << std::endl;
        return 1;
    }

    // Convert result to Roman numeral
    std::string romanResult = intToRoman(result);

    // Output result
    std::cout << num1 << ' ' << op << ' ' << num2 << " = " << romanResult << std::endl;

    return 0;
}
