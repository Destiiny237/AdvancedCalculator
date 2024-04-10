/**
 *
 * @file backend.h
 *
 */
#ifndef BACKEND_H
#define BACKEND_H

#include "../SmartCalc.h"
#include "../Stack/s21_stack.h"

/**
 * @brief Функция преобразует обычную инфиксную запись в обратную польскую запись.
 *
 * @param expression Строка с математическим выражением
 *
 * @return char* выражение в обратной польской записи
 */
char* expression_parser(char* expression);
/**
 * @brief Возвращает математическую операцию по int Lexeme в виде строки
 *
 * @param num Lexeme
 *
 * @return char* выражение (Математическую операцию)
 */
char* returnOperationType(int num);
/**
 * @brief Добавляет математическую операцию в стэк stack или в выходную строку
 *
 * @param stack Стэк
 *
 * @param resultString Выходная строка
 * 
 * @param priority приоритет операции
 * 
 * @param lexeme тип лексемы
 * 
 * @return char* выражение (Математическую операцию)
 */
stack_t* addOperationToStack(stack_t* stack, char* resultString, int priority, Lexeme lexeme);
/**
 * @brief Исправляет унарные минусы и плюсы. Пример: -2+1 -> 0-2+1
 *
 * @param expression Строка с математическим выражением
 */
void correctExpression(char* expression);
/**
 * @brief Принимает выражение в обратной польской нотации и решает его
 *
 * @param expression Строка с математическим выражением
 *
 * @param x Икс (если есть)
 * 
 * @return double ответ на выражение
 */
double expression_solver(char* expression, double x);
/**
 * @brief Удаляет верхние два элемента со стэка и записывает в num1 и num2
 *
 * @param stack Стэк
 *
 * @param num1 Первое значение
 * 
 * @param num2 Второе значение
 * 
 * @return stack_t* стэк без верхних двух элементов
 */
stack_t* pop_last_two_el(stack_t* stack, double* num1, double* num2);

/**
 * @brief Проверяет верно ли введено выражение
 *
 * @param expression Строка с математическим выражением
 * 
 * @return 0-NOT_VALID, 1-VALID
 */
int isValid(char* expression);
/**
 * @brief Проверяет верно ли стоят скобки
 *
 * @param expression Строка с математическим выражением
 * 
 * @return 0-NOT_VALID, 1-VALID
 */
int bracketIsValid(char* expression);
/**
 * @brief Проверяет верно ли стоят операции
 *
 * @param expression Строка с математическим выражением
 * 
 * @return 0-NOT_VALID, 1-VALID
 */
int signsIsValid(char* expression);
/**
 * @brief Проверяет верно ли написана функции
 *
 * @param expression Строка с математическим выражением
 * 
 * @return 0-NOT_VALID, 1-VALID
 */
int functionsIsValid(char* expression);

#endif