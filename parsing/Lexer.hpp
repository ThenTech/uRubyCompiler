#pragma once
/*
 *  https://westes.github.io/flex/manual/
 *  http://dinosaur.compilertools.net/flex/manpage.html
 */
#include "tokens.hpp"
#include "internal/yylexer.hpp"
#include "internal/yyparser.hpp"
#include "../utils/utils_lib/utils_io.hpp"
#include "../utils/utils_lib/utils_exceptions.hpp"

#include <deque>

namespace cmp {
    class Lexer {
        private:
            std::deque<std::pair<cmp::Token, std::string>> tokens;
            std::FILE *infile = nullptr;

        public:
            Lexer() {
                // Uses std::cin by default
                UNUSED(yyunput); // Remove unused warning
                yyset_out(nullptr);
            }

            Lexer(const std::string& input_file) : Lexer() {
                if (utils::io::fs::exists(input_file)) {
                    this->infile = std::fopen(input_file.c_str(), "r");
                } else {
                    throw utils::exceptions::FileReadException(input_file);
                }

                yyrestart(this->infile);
            }

            ~Lexer() {
                if (this->infile) {
                    std::fclose(this->infile);
                }

                utils::memory::delete_var(root);
            }

            void reset_file() {
                std::rewind(this->infile);
                yylocation = { 1, 1 };
                utils::memory::delete_var(root);
            }

            void lexical_analyse() {
                int id;

                while ((id = yylex()) > 0) {
                    this->tokens.emplace_back(
                        static_cast<cmp::Token>(id),
                        std::string{yytext, size_t(yyleng)}
                    );
                }
            }

            void lexical_parse() {
                int result = yyparse();

                utils::Logger::Info("[LEXER] Parsing ended with result: %d", result);
                utils::Logger::Stream("root = ", (void*)root, "\n");
            }

            const Statement * get_root() const {
                return root;
            }

            template<typename TChar, typename TCharTraits>
            auto& stream_parsed(std::basic_ostream<TChar, TCharTraits>& stream) const {
                for (const auto& [token, sv] : this->tokens) {
                    stream << sv;

                    if (token == cmp::Token::END) {
                        stream << "\n";
                    } else {
                        stream << " ";
                    }
                }

                stream << "\n";
                return stream;
            }

            template<typename TChar, typename TCharTraits>
            auto& stream_tokenized(std::basic_ostream<TChar, TCharTraits>& stream) const {
                for (const auto& [token, sv] : this->tokens) {
                    stream << token;

                    if (utils::math::within_inclusive(token, cmp::Token::ID, cmp::Token::STRING)) {
                        stream << "=\"" << sv << "\"";
                    }

                    stream << " ";
                }

                stream << "\n";

                return stream;
            }

            template<typename TChar, typename TCharTraits>
            friend auto& operator<<(std::basic_ostream<TChar, TCharTraits>& stream, const Lexer& l) {
                return l.stream_tokenized(stream);
            }
    };
}
