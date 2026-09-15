#include "Queue.hpp"

#include <cstdio>
#include <iostream>
#include <print>
#include <thread>

Queue::Queue(std::size_t capacity)
    : m_Capacity(capacity)
    , m_Size(0)
{
    m_PrintJobs = new PrintJob*[capacity];
}

Queue::~Queue()
{
    for (std::size_t i {}; i < m_Size; ++i) {
        if (m_PrintJobs[i])
            delete m_PrintJobs[i];
    }

    delete[] m_PrintJobs;
}

void Queue::Push(PrintJob *job, bool FreeOnFailure)
{
    if (m_Size == m_Capacity) {
        if (FreeOnFailure)
            delete job;

        std::println(
            stderr,
            "La cola está llena. Por favor, espera a que finalice una impresión "
            "antes de agregar otra e inténtalo de nuevo."
        );

        return;
    }

    m_PrintJobs[m_Size++] = job;
}

void Queue::PrintAll()
{
    if (m_Size == 0)
        return;

    auto jobs = m_Size;
    for (std::size_t i {}; i < jobs; ++i) {
        std::cout << *m_PrintJobs[i];

        // Supongamos que cada impresión dura medio segundo.
        std::this_thread::sleep_for(
            std::chrono::milliseconds(500 * m_PrintJobs[i]->Pages())
        );

        delete m_PrintJobs[i];
        --m_Size;
    }

    std::println("Todos los trabajos fueron impresos con éxito. La cola está vacía.");
}

std::size_t Queue::Capacity() const noexcept
{
    return m_Capacity;
}

std::size_t Queue::Size() const noexcept
{
    return m_Size;
}