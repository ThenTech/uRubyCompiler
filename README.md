# Compilers µRuby parser

> 2020-01-09 **William Thenaers**

## Build and run

- First make sure Flex and Bison are installed in the environment
- If the lex or yacc file was changed, run `./scripts/build_lexer.sh` and `./scripts/build_parser.sh` first
- Next run `./run.sh`
- The executable can be called with `./bin/compiler` and with the first argument being a µRuby file to parse and an optional second argument to write the lexer output to.