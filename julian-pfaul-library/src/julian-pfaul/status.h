#pragma once

namespace julian_pfaul {
    class status {
        using status_code_type = int;
    public:
        explicit consteval status() : m_status_code {0} {}
        explicit constexpr status(const status_code_type status_code) : m_status_code {status_code} {}
        ~status() = default;

        [[nodiscard]] constexpr bool is_good() const { return m_status_code == 0; }
        [[nodiscard]] constexpr bool is_bad() const { return m_status_code != 0; }

        [[nodiscard]] constexpr status_code_type status_code() const { return m_status_code; }
    private:
        status_code_type m_status_code;

    };
}
