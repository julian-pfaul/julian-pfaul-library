#pragma once

#include <ostream>
#include <julian-pfaul/definitions.h>

namespace julian_pfaul {
    class bit_address {
    public:
        bit_address();
        ~bit_address();

        implicit bit_address(u8 address);
        explicit bit_address(size address);

        implicit operator u8() const;
        explicit operator size() const;

        friend bool operator==(const bit_address& lhs, const bit_address& rhs);
        friend bool operator!=(const bit_address& lhs, const bit_address& rhs);

        friend bool operator<(const bit_address& lhs, const bit_address& rhs);
        friend bool operator<=(const bit_address& lhs, const bit_address& rhs);
        friend bool operator>(const bit_address& lhs, const bit_address& rhs);
        friend bool operator>=(const bit_address& lhs, const bit_address& rhs);

        friend std::ostream& operator<<(std::ostream& os, const bit_address& obj);

    private:
        u8 m_address;
    };

    class byte;

    class bit_reference {
    public:
        bit_reference() = delete;
        ~bit_reference();

        bit_reference(byte& byte, bit_address address);

        implicit operator bool() const;

        bit_reference& operator=(bool other);

    private:
        byte& m_byte;
        bit_address m_address;
    };


    class const_bit_reference {
    public:
        const_bit_reference() = delete;
        ~const_bit_reference();

        const_bit_reference(const byte& byte, bit_address address);

        implicit operator bool() const;

    private:
        const byte& m_byte;
        bit_address m_address;
    };

    class byte {
    public:
        byte();
        ~byte();

        implicit byte(u8 byte);
        implicit operator u8() const;

        bit_reference operator[](bit_address index);
        const_bit_reference operator[](bit_address index) const;

        friend std::ostream& operator<<(std::ostream& os, const byte& obj);

    private:
        u8 m_byte;
    };
} // julian_pfaul
