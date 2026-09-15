#include "PrintJob.hpp"

#include <utility>

PrintJob::PrintJob(std::string username, unsigned pages)
    : m_Username(std::move(username))
    , m_Pages(pages)
{
}

std::string_view PrintJob::Username() const noexcept
{
    return m_Username;
}

unsigned PrintJob::Pages() const noexcept
{
    return m_Pages;
}

std::string PrintJob::priority() const
{
    switch (m_Priority) {
    case Priority::STANDARD:
        return "Estándar";
    }

    std::unreachable();
}
