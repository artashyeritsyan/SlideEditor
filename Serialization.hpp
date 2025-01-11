#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include "Models/Presentation.hpp"

class Serialization {
public:
    Serialization() = default;
    ~Serialization() = default;

    void serialize(const std::shared_ptr<Presentation>& presentation, const std::string& path);
    std::shared_ptr<Presentation> deserialize(const std::string& path);

private:
    void serializePresentation(const std::shared_ptr<Presentation>& presentation, std::ofstream& file);
};





#endif // SERIALIZATION_HPP