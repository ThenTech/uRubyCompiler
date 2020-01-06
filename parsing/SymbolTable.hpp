#pragma once

#include "../utils/utils_lib/utils_algorithm.hpp"
#include "../utils/utils_lib/utils_string.hpp"

#include "fwd.hpp"

#include <map>
#include <string_view>
#include <optional>
#include <variant>


namespace cmp {
    using InterpretResult = std::variant<int32_t, double, bool>;

    class BasicTable {
        protected:
            typedef std::map<std::string_view, InterpretResult> _TableType;
            _TableType table;

            size_t max_key_size() const {
                size_t max_key_len = 0;

                for (auto [key, val] : this->table) {
                    UNUSED(val);
                    if (const size_t key_len = key.size(); key_len > max_key_len) {
                        max_key_len = key_len;
                    }
                }

                return max_key_len;
            }

        public:
            typedef typename _TableType::key_type       key_type;
            typedef typename _TableType::value_type     pair_type;
            typedef typename _TableType::mapped_type    value_type;
            typedef typename _TableType::size_type	    size_type;

            BasicTable() {
                // Empty
            }

            virtual ~BasicTable() {}

            size_type size() const {
                return this->table.size();
            }

            bool empty() const {
                return this->table.empty();
            }

            void insert(key_type name, value_type value) {
                this->table[name] = value;
            }

            void erase(key_type name) {
                this->table.erase(name);
            }

            std::optional<value_type> get(key_type name) {
                if (utils::algorithm::contains(this->table, name)) {
                    return { this->table[name] };
                }
                return std::nullopt;
            }

            template<typename TChar, typename TCharTraits>
            friend auto& operator<<(std::basic_ostream<TChar, TCharTraits>& stream,
                                    const BasicTable& t)
            {
                const size_t max_key_len = t.max_key_size();

                for (auto [key, val] : t.table) {
                    std::visit([&](auto&& arg){
                        stream << utils::string::format("[%*s] %6s : ",
                                        max_key_len, key.data(),
                                        utils::print::type2name(arg).c_str())
                               << std::boolalpha << arg << "\n";
                    }, val);
                }

                return stream;
            }
    };

    class FunctionTable : public BasicTable {
        private:

        public:
            FunctionTable() {
                // Empty
            }

            ~FunctionTable() {}

            template<typename TChar, typename TCharTraits>
            friend auto& operator<<(std::basic_ostream<TChar, TCharTraits>& stream,
                                    const FunctionTable& t)
            {
                const size_t max_key_len = t.max_key_size();

                for (auto [key, val] : t.table) {
                    std::visit([&](auto&& arg){
                        stream << utils::string::format("[%*s] args : ", max_key_len, key.data())
                               << arg << "\n";
                    }, val);
                }

                return stream;
            }
    };

    class SymbolTable {
        private:
            BasicTable var_table;
            FunctionTable fun_table;

        public:
            typedef typename BasicTable::key_type   key_type;
            typedef typename BasicTable::pair_type  pair_type;
            typedef typename BasicTable::value_type value_type;
            typedef typename BasicTable::size_type  size_type;

            SymbolTable() {
                // Empty
            }

            ~SymbolTable() {}

            auto& get_var_table() {
                return this->var_table;
            }

            auto& get_var_table() const {
                return this->var_table;
            }

            auto& get_fun_table() {
                return this->fun_table;
            }

            auto& get_fun_table() const {
                return this->fun_table;
            }

            template<typename TChar, typename TCharTraits>
            friend auto& operator<<(std::basic_ostream<TChar, TCharTraits>& stream,
                                    const SymbolTable& t)
            {
                stream << "Variables:\n" << t.get_var_table()
                       << "Functions:\n" << t.get_fun_table();
                return stream;
            }
    };
}
