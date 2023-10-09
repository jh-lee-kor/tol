#ifndef TOLELOM_OBJECT_H
#define TOLELOM_OBJECT_H

#include <string>

enum class ObjectType {
    INTEGER,
    BOOLEAN,
    RETURN_VALUE_OBJECT
};

class Object {
public:
    ObjectType type{};

    virtual std::string print() = 0;
};

class Integer : public Object{
public:
    ObjectType type = ObjectType::INTEGER;
    long long value{};

    std::string print() final {
        return std::to_string(value);
    }
};

class Boolean : public Object {
public:
    ObjectType type = ObjectType::BOOLEAN;
    bool value{};

    Boolean() = default;
    explicit Boolean(bool value) : value(value) {};

    std::string print() final {
        return std::to_string(value);
    }
};

class ReturnValue : public Object {
public:
    ObjectType type = ObjectType::RETURN_VALUE_OBJECT;
    Object* value{};

    std::string print() final {
        return value->print();
    }
};

#endif //TOLELOM_OBJECT_H
