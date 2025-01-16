#include "Serialization.hpp"

void Serialization::serialize(const std::shared_ptr<Presentation> &presentation, const std::string &path)
{
    std::ofstream
        file
        (path, std::ios::out | std::ios::binary);
    
    if (!file.is_open()) {
        throw CLIException("Can't open file");
    }

    serializePresentation(presentation, file);

    file.close();

}

// void Serialization::serializePresentation(const std::shared_ptr<Presentation> &presentation, std::ofstream &file)
// {
//     file.write(reinterpret_cast<const char*>(presentation->getSlidesCount()), sizeof(int));

//     for (int i = 0; i < presentation->getSlidesCount(); i++) {
//         auto slide = presentation->getSlideByIndex(i);
//         file.write(reinterpret_cast<const char*>(slide->getItemsCount()), sizeof(int));

//         for (const auto& item : slide->getItemList()) {
//             item->serialize(file);
//         }
//     }
// }
