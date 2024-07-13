/**
 * @file helper.hpp
 * @author Moztanku (mostankpl@gmail.com)
 * @brief This file contains helper functions for the project
 */
#pragma once

namespace utils
{

/**
 * @brief Custom iterator for entt::basic_view made for Events::EventRegistry, it hides away the first element of the tuple (entt::entity)
 * @tparam It Iterator type used by entt::iterable_adaptor
 */
template<typename It>
struct custom_iterator final {
    public:
        constexpr custom_iterator(It&& it) : m_iterator{std::forward<It>(it)} {}

        constexpr auto operator++() {
            m_iterator = std::next(m_iterator);
            return *this;
        }

        [[nodiscard]] constexpr auto operator*() {
            return remove_first_element(*m_iterator);
        }

        constexpr auto operator!=(const custom_iterator& rhs) {
            return m_iterator != rhs.m_iterator;
        }
    private:
        It m_iterator;

        template<typename Tuple, std::size_t... Is>
        constexpr auto remove_first_element_impl(Tuple&& t, std::index_sequence<Is...>) {
            return std::tie(std::get<Is + 1>(t)...);
        }

        template<typename Tuple>
        constexpr auto remove_first_element(Tuple&& t) {
            return remove_first_element_impl(
                t, std::make_index_sequence<std::tuple_size_v<Tuple> - 1>{});
        }
};

/**
 * @brief Custom iterator adaptor, it returns a custom_iterator instead of the default iterator
 * @tparam Iter Type of iterator used by entt::iterable_adaptor
 */
template<typename Iter>
struct custom_iterable_adaptor final {
    public:
        constexpr custom_iterable_adaptor(Iter&& iter) : m_iterable{std::forward<Iter>(iter)} {}

        [[nodiscard]] constexpr auto begin() -> custom_iterator<typename Iter::iterator> {
            return m_iterable.begin();
        }

        [[nodiscard]] constexpr auto end() -> custom_iterator<typename Iter::sentinel> {
            return m_iterable.end();
        }
    private:
        Iter m_iterable;
};

} // namespace utils
