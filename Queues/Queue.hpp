#pragma once

#include "PrintJob.hpp"

class Queue
{
public:
    explicit Queue(std::size_t Capacity = 10);
    ~Queue();
    void Push(PrintJob *Job, bool FreeOnFailure = true);
    void PrintAll();
    std::size_t Capacity() const noexcept;
    std::size_t Size() const noexcept;

private:
    PrintJob **m_PrintJobs;
    std::size_t m_Capacity;
    std::size_t m_Size;
};