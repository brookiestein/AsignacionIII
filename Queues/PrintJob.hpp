#pragma once

#include <ostream>
#include <string>
#include <string_view>

class PrintJob
{
public:
    PrintJob(std::string username, unsigned pages);
    std::string_view Username() const noexcept;
    unsigned Pages() const noexcept;
    std::string priority() const;

private:
    enum class Priority { STANDARD };
    std::string m_Username;
    unsigned m_Pages;
    Priority m_Priority = Priority::STANDARD;
};

namespace
{
std::ostream &operator<<(std::ostream &Out, const PrintJob &Job)
{
    Out << "Imprimiendo trabajo de " << Job.Username() << ": " << Job.Pages()
        << " páginas." << '\n';
    return Out;
}
} // unnamed namespace
