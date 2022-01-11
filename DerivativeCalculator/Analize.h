#pragma once
#ifndef ANALIZE_H
#define ANALIZE_H

#include <Equation.h>

double string_to_double(const char* str, int start, int end);

Equation* analize_literal(const char* str, int& start, int end);

Equation* analize_factor(const char* str, int& start, int end);

Equation* analize_component(const char* str, int& start, int end);

Equation* analize_simple_equation(const char* str, int& start, int end);

#endif