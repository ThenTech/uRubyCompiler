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

    class SymbolTable {
        private:
            typedef std::map<std::string_view, InterpretResult> _TableType;
            _TableType table;

        public:
            typedef typename _TableType::key_type       key_type;
            typedef typename _TableType::value_type     pair_type;
            typedef typename _TableType::mapped_type    value_type;
            typedef typename _TableType::size_type	    size_type;

            SymbolTable() {
                // Empty
            }

            ~SymbolTable() {}

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
                                    const SymbolTable& t)
            {
                size_t max_key_len = 0;

                for (auto [key, val] : t.table) {
                    UNUSED(val);
                    if (const size_t key_len = key.size(); key_len > max_key_len) {
                        max_key_len = key_len;
                    }
                }

                for (auto [key, val] : t.table) {
                    stream << utils::string::format("[%*s] : ", max_key_len, key.data());

                    if (std::holds_alternative<bool>(val)) {
                        stream << std::boolalpha << std::get<bool>(val);
                    } else {
                        std::visit([&](auto&& arg){stream << arg;}, val);
                    }

                    stream << "\n";
                }

                return stream;
            }
    };
}
