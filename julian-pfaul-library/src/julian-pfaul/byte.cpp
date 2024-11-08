#include "byte.h"

namespace julian_pfaul {
    // BIT ADDRESS CLASS
    bit_address::bit_address() : m_address {0} {}
    bit_address::~bit_address() = default;
    bit_address::bit_address(const u8 address) : m_address {address} {}
    bit_address::bit_address(const size address) : m_address {static_cast<u8>(address)} {}

    bit_address::operator u8() const {
        return m_address;
    }

    bit_address::operator size() const {
        return m_address;
    }

    bool operator==(const bit_address& lhs, const bit_address& rhs) { return lhs.m_address == rhs.m_address; }
    bool operator!=(const bit_address& lhs, const bit_address& rhs) { return lhs.m_address != rhs.m_address; }

    bool operator<(const bit_address& lhs, const bit_address& rhs) { return lhs.m_address < rhs.m_address; }
    bool operator<=(const bit_address& lhs, const bit_address& rhs) { return lhs.m_address <= rhs.m_address; }
    bool operator>(const bit_address& lhs, const bit_address& rhs) { return lhs.m_address > rhs.m_address; }
    bool operator>=(const bit_address& lhs, const bit_address& rhs) { return lhs.m_address >= rhs.m_address; }

    std::ostream& operator<<(std::ostream& os, const bit_address& obj) {
        return os << std::hex << static_cast<int>(obj.m_address);
    }

    // BIT REFERENCE CLASS
    bit_reference::~bit_reference() = default;
    bit_reference::bit_reference(byte& byte, const bit_address address) : m_byte {byte}, m_address {address} {}

    bit_reference::operator bool() const {
        return m_byte >> m_address & 0b0000'00001;
    }

    bit_reference& bit_reference::operator=(const bool other) {
        m_byte = m_byte & ~(other << m_address) | (other << m_address);
        return *this;
    }

    // CONST BIT REFERENCE CLASS
    const_bit_reference::~const_bit_reference() = default;
    const_bit_reference::const_bit_reference(const byte& byte, const bit_address address) : m_byte {byte}, m_address {address} {}

    const_bit_reference::operator bool() const {
        return m_byte >> m_address & 0b0000'00001;
    }

    // BYTE CLASS
    byte::byte() : m_byte {0x00} {}
    byte::~byte() = default;
    byte::byte(const u8 byte) : m_byte {byte} {}

    byte::operator u8() const { return m_byte; }

    bit_reference byte::operator[](const bit_address index) {
        return bit_reference(*this, index);
    }

    const_bit_reference byte::operator[](const bit_address index) const {
        return const_bit_reference(*this, index);
    }

    std::ostream& operator<<(std::ostream& os, const byte& obj) {
        return os << std::hex << static_cast<int>(obj.m_byte);
    }
} // julian_pfaul
