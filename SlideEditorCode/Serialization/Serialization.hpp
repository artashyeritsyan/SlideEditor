#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../Application/Application.hpp"

class Serialization {
public:
    Serialization() = default;
    ~Serialization() = default;

    void serialize(const std::string& filename);
    void deserialize(const std::string& filename);

private:
    void serializePresentation(std::ofstream& file);
    void serializeSlide(std::ofstream& file, std::shared_ptr<Slide> slide);
    void serializeItem(std::ofstream& file, std::shared_ptr<Item> item);

    std::shared_ptr<Presentation> deserializePresentation(std::ifstream& file);
    std::shared_ptr<Slide> deserializeSlide(std::ifstream& file);
    std::shared_ptr<Item> deserializeItem(std::ifstream& file);

};





#endif // SERIALIZATION_HPP