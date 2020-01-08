#include "utils/utils_lib/utils_logger.hpp"
#include "utils/utils_lib/utils_version.hpp"
#include "utils/utils_lib/utils_memory.hpp"

static constexpr utils::Version VERSION(0, 3, 3, utils::version::prerelease::none);

#include "parsing/Expression.hpp"
#include "parsing/Statement.hpp"
#include "parsing/SymbolTable.hpp"
#include "parsing/Lexer.hpp"

/*
 *  Version history:
 *      v0.1.0 : Opgaven 2, 3 en 4 uit hoofdstuk 1
 *      v0.2.0 : Project deel 1 - Flex lexer
 *      v0.3.0 : Project deel 2 - Bison parser
 */
int main(int argc, char *argv[]) {
    const std::string versionstring = "UHasselt[Compilers] project v" + VERSION.to_string() + " - William Thenaers";
    utils::Logger::SetScreenTitle(versionstring);
    utils::Logger::Notice(versionstring + "\n");

#ifdef Assignment_1_Opwarmingsoefening
    UNUSED(argc, argv);
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

    argc--; argv++;
    std::string input_file, output_file;
    if (argc > 0) {
        // "../test_files/lex.testjes/lexme_test1.rb"
        // "../test_files/lex.testjes/lexme_test2.rb"
        input_file = argv[0];
    } else {
        utils::Logger::Warn("Please provide an input µRuby file!");
        return 1;
    }

    if (argc > 1) {
        output_file = argv[1];
    }

    try {
        cmp::Lexer lex(input_file);

        // Lex
        lex.lexical_analyse();
        if (output_file.empty()) {
            utils::Logger::Info("Lexer token output:");
            utils::Logger::Stream(lex);
            // lex.stream_parsed(utils::Logger::GetConsoleStream());
        } else {
            std::ofstream(output_file) << lex;
            utils::Logger::Info("Output written to \"%s\"", output_file.c_str());
        }

        // Parse (also does lexing, so reset file to start)
        utils::Logger::Info("Bison parsing output:");
        lex.reset_file();
        if (lex.lexical_parse() == 0 && lex.get_root() != nullptr) {
            utils::Logger::Info("Interpreting result:");

            cmp::SymbolTable table;

            utils::Logger::Stream("Root object: ", lex.get_root(), " at ", static_cast<const void*>(lex.get_root()), "\n");
            lex.get_root()->interpret(table);

            utils::Logger::Info("Resulting Symbol Table:");
            utils::Logger::Stream(table.get_var_table());
            utils::Logger::Info("Resulting Function Table:");
            utils::Logger::Stream(table.get_fun_table());

            utils::Logger::Info("Max args: %d", lex.get_root()->maxargs());
        }
    } CATCH_AND_LOG_ERROR_TRACE()

    return 0;
}
