#include "utils/utils_lib/utils_logger.hpp"
#include "utils/utils_lib/utils_version.hpp"
#include "utils/utils_lib/utils_memory.hpp"

static constexpr utils::Version VERSION(0, 2, 0, utils::version::prerelease::none);

#include "parsing/Expression.hpp"
#include "parsing/Statement.hpp"
#include "parsing/SymbolTable.hpp"
#include "parsing/Lexer.hpp"

/*
 *  Version history:
 *      v0.1.0 : Opgaven 2, 3 en 4 uit hoofdstuk 1
 *      v0.2.0 : Project deel 1 - Flex lexer
 */
int main(int argc, char *argv[]) {
    const std::string versionstring = "UHasselt[Compilers] project v" + VERSION.to_string() + " - William Thenaers";
    utils::Logger::SetScreenTitle(versionstring);
    utils::Logger::Notice(versionstring + "\n");
    UNUSED(argc, argv);

#ifdef Assignment_1_Opwarmingsoefening
    using namespace cmp;
    SymbolTable table;

    // e.g. `a := 5+3; b := (print(a, a-1), 10*a); print(b)`
    utils::Logger::Info("Input program (pre-parsed):\n");
    utils::Logger::Stream(utils::os::Console::FG | utils::os::Console::BLACK | utils::os::Console::BRIGHT,
                          "a := 5+3; b := (print(a, a-1), 10*a); print(b)",
                          utils::os::Console::RESET, "\n\n");

    const auto prog = utils::memory::new_unique_var<CompoundStatement>(
        new AssignStatement{
            "a",
            new BinOperandExpression{new NumericExpression{5}, BinaryOperand::Plus, new NumericExpression{3}}
        },
        new CompoundStatement{
            new AssignStatement{
                "b",
                new ExpseqExpression{
                    new PrintStatement{
                        new PairExpressionList{
                            new IdExpression{"a"},
                            new LastExpressionList{
                                new BinOperandExpression{new IdExpression{"a"}, BinaryOperand::Minus, new NumericExpression{1}}
                            }
                        }
                    },
                    new BinOperandExpression{new NumericExpression{10}, BinaryOperand::Times, new IdExpression{"a"}}
                }
            },
            new PrintStatement{new LastExpressionList{new IdExpression{"b"}}}
        }
    );

    utils::Logger::Info("Program max print args: %d", prog->maxargs());

    utils::Logger::Info("Interpreting result:");
    prog->interpret(table);

    utils::Logger::Info("Resulting Symbol Table:");
    utils::Logger::Stream(table);
#endif

    try {
        cmp::Lexer lex("../test_files/lex.testjes/lexme_test1.rb");
        // cmp::Lexer lex("../test_files/lex.testjes/lexme_test2.rb");

        lex.interpret();

        utils::Logger::Info("Lexer token output:");
        utils::Logger::Stream(lex);
        // utils::Logger::Stream("\nRaw:\n"); lex.stream_parsed(utils::Logger::GetConsoleStream());
    } CATCH_AND_LOG_ERROR_TRACE()

    return 0;
}
