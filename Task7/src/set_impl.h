#pragma once

#include <memory>
#include <vector>
#include <cstddef>

class SetImpl
{   
public:
    virtual ~SetImpl() = default;

    virtual void add(int element) = 0;
    virtual void remove(int element) = 0;
    virtual bool contains(int element) const = 0;

    virtual std::size_t getSize() const = 0;

    virtual std::vector<int> getElements() const = 0;
    virtual std::unique_ptr<SetImpl> clone() const = 0;
};