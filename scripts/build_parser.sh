#!/bin/bash

bison --no-lines -o ./parsing/internal/yyparser.hpp ./parsing/internal/tokens.yacc
