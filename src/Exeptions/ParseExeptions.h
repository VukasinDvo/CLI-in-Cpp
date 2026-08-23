//
// Created by vladi on 8/23/2026.
//

#ifndef OOP1PROJEKAT_PARSEEXEPTIONS_H
#define OOP1PROJEKAT_PARSEEXEPTIONS_H
class ParseExeptions :public std::runtime_error {
    public:
    explicit ParseExeptions(const std::string& msg) : std::runtime_error(msg) {}
};
#endif //OOP1PROJEKAT_PARSEEXEPTIONS_H