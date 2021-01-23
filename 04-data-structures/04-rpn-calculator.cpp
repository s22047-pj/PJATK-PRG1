/*
 * A reverse-polish notation calculator.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>


auto pop_top(std::stack<double>& stack) -> double
{
    if (stack.empty()) {
        throw std::logic_error{"empty stack"};
    }
    auto element = std::move(stack.top());
    stack.pop();
    return element;
}

auto round_double_type(double b_int, double a_int) -> std::vector <int>
{
    std::vector <int> result_vec;

    auto b_more = int(b_int+1);
    auto b_less = int(b_int);
    auto b_round = int();

    auto a_more = int(a_int+1);
    auto a_less = int(a_int);
    auto a_round = int();

    if (b_int >= double(b_less)+0.5){
        b_round = b_more;
    } else{
        b_round = b_less;
    }

    if (a_int >= double(a_less)+0.5){
        a_round = a_more;
    } else{
        a_round = a_less;
    }

    result_vec.push_back(a_round);
    result_vec.push_back(b_round);

    return result_vec;
}

void check_denominator(double den){
    if (den == 0){
        throw std::logic_error{"denominator has to be different than 0 -"};
    }
}

auto evaluate_addition(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for +"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a + b);
}

auto evaluate_subtraction(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a - b);
}

auto evaluate_multiplication(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a * b);
}

auto evaluate_division(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    
    check_denominator(b);
    
    stack.push(a / b);
}



auto evaluate_int_division(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }

    auto const b = pop_top(stack);
    auto const a = pop_top(stack);

    check_denominator(b);

    auto conv = round_double_type(b, a);
    stack.push(conv[0] / conv[1]);
}

auto evaluate_rest_of_division(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);

    check_denominator(b);

    auto conv = round_double_type(b, a);
    stack.push(conv[0] % conv[1]);
}

auto evaluate_exponentiation(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);

    stack.push(std::pow(b, a));
}

auto evaluate_square_root(std::stack<double>& stack) -> void
{
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    stack.push(sqrt(b));
}

auto delte_formula(double a, double b, double c) -> double
{
    return std::pow(c, 2) - (4*b*a);
}

void check_delte_result(double res)
{
    if (res > 0){
        std::cout << "function has two different zeros places" << "\n";
    } else if (res < 0){
        std::cout << "function has no zeros places" << "\n";
    } else if (res == 0){
         std::cout << "function has two zeros located in one place" << "\n";
    }
}

auto evaluate_delte_formula(std::stack<double>& stack) -> void
{
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for -"};
    }

    auto const a = pop_top(stack);
    auto const b = pop_top(stack);
    auto const c = pop_top(stack);

    auto delte = delte_formula(a, b, c);
    check_delte_result(delte);

    stack.push(delte);
}

auto make_args(int argc, char* argv[]) -> std::vector<std::string>
{
    auto args = std::vector<std::string>{};
    std::copy_n(argv, argc, std::back_inserter(args));
    return args;
}

auto main(int argc, char* argv[]) -> int
{
    auto const args = make_args(argc - 1, argv + 1);

    auto stack = std::stack<double>{};
    for (auto const each : args) {
        try {
            if (each == "p") {
                std::cout << pop_top(stack) << "\n";
            } else if (each == "+") {
                evaluate_addition(stack);
            } else if (each == "-") {
                evaluate_subtraction(stack);
            } else if (each == "*") {
                evaluate_multiplication(stack);
            } else if (each == "/") {
                evaluate_division(stack);
            } else if (each == "//") {
                evaluate_int_division(stack);
            } else if (each == "%") {
                evaluate_rest_of_division(stack);
            } else if (each == "**") {
                evaluate_exponentiation(stack);
            } else if (each == "sqrt") {
                evaluate_square_root(stack);
            } else if (each == "delte") {
                evaluate_delte_formula(stack);
            } else {
                stack.push(std::stod(each));
            }
        } catch (std::logic_error const& e) {
            std::cerr << "error: " << each << ": " << e.what() << "\n";
        }
    }
    std::cout << pop_top(stack) << "\n";

    return 0;
}
