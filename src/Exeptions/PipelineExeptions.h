//
// Created by vladi on 9/9/2026.
//

#ifndef OOP1PROJEKAT_PIPELINEEXEPTIONS_H
#define OOP1PROJEKAT_PIPELINEEXEPTIONS_H
#include <stdexcept>

class PipelineExeptions : public std::runtime_error {
public:
    explicit PipelineExeptions(const std::string& msg)
        : std::runtime_error(msg) {}
};
#endif //OOP1PROJEKAT_PIPELINEEXEPTIONS_H