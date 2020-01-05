#!/bin/bash

flex --noline --nounistd --never-interactive -o ./parsing/internal/yylexer.hpp ./parsing/internal/tokens.flex
