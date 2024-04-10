/**
 *
 * @file s21_stack.h
 *
 */
#ifndef STACK_H
#define STACK_H

#include "../SmartCalc.h"

typedef enum Token {
    Bracket = 0,
    Number = 1,
    X = 2,
    Plus = 3,
    Minus = 4,
    Multiply = 5,
    Divide = 6,
    Exponent = 7,
    s21_sin = 8,
    s21_cos = 9,
    s21_tan = 10,
    s21_asin = 11,
    s21_acos = 12,
    s21_atan = 13,
    Sqrt = 14,
    Log = 15,
    Ln = 16,
    Mod = 17
} Lexeme;

typedef struct stack {
    double value;
    int priority;
    struct stack* next;
    Lexeme lexeme_type;
} stack_t;

/**
 * @brief Добавляет на вершину стэка новое значение
 * @param stack Указатель на вершину стэка
 * @param value Значение
 * @param lexeme_type Тип лексемы
 * @param priority Приоритет
 * @return Указатель на новую вершину
 */
stack_t* push(stack_t* stack, double value, Lexeme lexeme_type, int priority);
/**
 * @brief Удаляет значение с вершины стэка
 * @param stack Указатель на вершину стэка
 * @return Указатель на новую вершину
 */
stack_t* pop(stack_t* stack);


#endif