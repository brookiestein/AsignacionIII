#include <clocale>
#include <format>
#include <iostream>
#include <map>
#include <print>
#include <queue>
#include <stack>
#include <string>

std::string Input(const std::string &Message);
std::queue<std::string> Convert(const std::string &Expression);

int main()
{
    std::setlocale(LC_ALL, "es_DO.UTF-8");
    auto Expression = Input("Por favor, introduzca una expresión matemática");
    auto Converted = Convert(Expression);

    std::println("Expresión: {}", Expression);
    std::println("Convertida: {}", Converted);
}

std::string Input(const std::string &Message)
{
    std::string Value;

    while (true) {
        std::print("{}: ", Message);
        std::getline(std::cin, Value);

        if (Value.empty()) {
            std::println(stderr, "No ingresaste nada.");
            continue;
        }

        break;
    }

    return Value;
}

std::queue<std::string> Convert(const std::string &Expression)
{
    std::map<char, int> Precedence;
    Precedence['+'] = 1;
    Precedence['-'] = 1;
    Precedence['*'] = 2;
    Precedence['/'] = 2;
    Precedence['^'] = 3;

    std::queue<std::string> Output;
    std::stack<char> Operators;

    for (const auto &Token : Expression) {
        if (std::isspace(Token))
            continue;

        if (std::isalnum(Token)) {
            Output.push(std::format("{}", Token));
            continue;
        }

        if (Token == '(') {
            Operators.push(Token);
        } else if (Token == ')') {
            while (!Operators.empty() && Operators.top() != '(') {
                Output.push(std::format("{}", Operators.top()));
                Operators.pop();
            }
            Operators.pop();
        } else if (Precedence.find(Token) != Precedence.end()) {
            while (!Operators.empty() &&
                   Precedence.find(Operators.top()) != Precedence.end() &&
                   Precedence[Operators.top()] >= Precedence[Token]) {
                Output.push(std::format("{}", Operators.top()));
                Operators.pop();
            }
            Operators.push(Token);
        }
    }

    while (!Operators.empty()) {
        Output.push(std::format("{}", Operators.top()));
        Operators.pop();
    }

    return Output;
}
