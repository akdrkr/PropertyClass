#pragma once
#ifndef PROPERTY_HPP
#define PROPERTY_HPP


#include <string>
#include <boost/any.hpp>

class Property
{
public:
    Property(uint16_t type, std::string name, uint16_t start_byte, uint16_t len)
        : type_(type), name_(std::move(name)), start_byte_(start_byte), len_(len) {}

    // Copy constructor
    Property(const Property& other)
        : type_(other.type_), name_(other.name_), start_byte_(other.start_byte_), len_(other.len_), m_value(other.m_value) {}

    // Move constructor
    Property(Property&& other) noexcept
        : type_(other.type_), name_(std::move(other.name_)), start_byte_(other.start_byte_), len_(other.len_), m_value(std::move(other.m_value)) {}

    // Copy assignment operator
    Property& operator=(const Property& other) {
        if (this != &other) {
            type_ = other.type_;
            name_ = other.name_;
            start_byte_ = other.start_byte_;
            len_ = other.len_;
            m_value = other.m_value;
        }
        return *this;
    }

    // Move assignment operator
    Property& operator=(Property&& other) noexcept {
        if (this != &other) {
            type_ = other.type_;
            name_ = std::move(other.name_);
            start_byte_ = other.start_byte_;
            len_ = other.len_;
            m_value = std::move(other.m_value);
        }
        return *this;
    }

    // Getter for value
    boost::any getValue() const noexcept { return m_value; }

    // Setter for value
    void setValue(boost::any value) { m_value = std::move(value); }

    // Template getter
    template<typename returnType>
    const returnType* get() const noexcept {
        return boost::any_cast<returnType>(&m_value);
    }

    // Overload ostream operator
    friend std::ostream& operator<<(std::ostream& os, const Property& prop) {
        os << "Property(name: " << prop.name_ << ", type: " << prop.type_
            << ", start_byte: " << prop.start_byte_ << ", len: " << prop.len_
            << ", value: " << prop.valueAsString() << ")";
        return os;
    }

private:
    // Helper function to convert value to string
    std::string valueAsString() const {
        if (m_value.empty()) return "empty";
        try {
            if (auto val = boost::any_cast<int>(&m_value)) return std::to_string(*val);
            if (auto val = boost::any_cast<double>(&m_value)) return std::to_string(*val);
            if (auto val = boost::any_cast<std::string>(&m_value)) return *val;
            // Add more type checks as needed
        }
        catch (const boost::bad_any_cast&) {
            return "unknown";
        }
        return "unknown";
    }

    uint16_t type_;
    std::string name_;
    uint16_t start_byte_;
    uint16_t len_;
    boost::any m_value;
};



#endif
